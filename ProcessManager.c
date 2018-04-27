//
// Created by caio on 16/04/18.
//

#include "ProcessManager.h"
#include "ProcessoSimulado.h"

///FALTA CRIAR FORK PARA PROCESSO REPORTER(Chamadas de sistema fork())
///Função comandoQ() incompleta, falta escalonador, e conferir se a lógica de chamada do processo simulado está correta
///Funções comandoP() comandoT() incompletas pela falta do fork()

void iniciarBlockedState(ProcessManager * processManager){
    fazFVazia(&(processManager->blockedState.filaBlocked));
}
void iniciarReadyState(ProcessManager * processManager){
    fazFVazia(&(processManager->readyState.filaReady));
}
void iniciarPcbTable(ProcessManager * processManager, ProcessoSimulado processoSimulado){
    processManager->pcbTable.processoSimulado[0] = processoSimulado;
}

ProcessManager iniciarProcessManager(){
    ProcessManager processManager;
    ProcessoSimulado processoSimulado;

    /* Iniciando processo simulado */
    processoSimulado.PID = 0;
    processoSimulado.PPID = 0;
    lerPrograma(&processoSimulado, "init");
    processoSimulado.CPUtime = 0;
    processoSimulado.n = 0;
    *(processoSimulado.PC) = 0;
    processoSimulado.priority = 0;
    processoSimulado.startTime = 0; //__TIME__;
    processoSimulado.state = EXECUTANDO; //Enum estados_processo = 0
    /* Iniciando PcbTable com o processo simulado */
    iniciarPcbTable(&processManager, processoSimulado);
    /* Iniciando o time */
    processManager.time = 0;
    /* Iniciando a CPU com o primeiro processo simulado */
    processManager.cpu.PC = *(processoSimulado.PC);
    processManager.cpu.n = processoSimulado.n;
    processManager.cpu.timeProcess = 1; //Unidades de tempo que o processo tem,
    processManager.cpu.usedTime = 0;
    processManager.cpu.vetorProgram = processoSimulado.vetorProgram;
    /* Iniciando lista de estados */
    processManager.runningState = 0;
    iniciarBlockedState(&processManager);
    iniciarReadyState(&processManager);

    return processManager;
}

int recuperarN(char *instrucao){
    int n, i = 0;
    char instrucaoAux[MAXTAMINSTRUCTION], caractere;
    strcpy(instrucaoAux, instrucao);
    caractere = instrucaoAux[i+2];
    while(1){
        instrucaoAux[i] = caractere;
        i++;
        if((caractere = instrucaoAux[i+2]) == '\0'){
            instrucaoAux[i] = caractere;
            break;
        }
    }
    n = atoi(instrucaoAux);
    return n;
}
int calcularFatia(int priority){
    switch (priority){
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 4;
        case 3:
            return 8;
        default:
            return 0;
    }
}

void instrucaoS(char *instrucao, Cpu *cpu){
    cpu->n = recuperarN(instrucao);
}

void instrucaoA(char *instrucao, Cpu *cpu){
    cpu->n = cpu->n + recuperarN(instrucao);
}

void instrucaoD(char *instrucao, Cpu *cpu){
    cpu->n = cpu->n - recuperarN(instrucao);
}

void instrucaoB(Cpu *cpu, PcbTable *pcbTable, RunningState *runningState, BlockedState *blockedState, ReadyState *readyState){
    pcbTable->processoSimulado[*runningState].PC = (int*) cpu->PC;
    pcbTable->processoSimulado[*runningState].n = cpu->n;
    pcbTable->processoSimulado[*runningState].vetorProgram = cpu->vetorProgram;
    pcbTable->processoSimulado[*runningState].CPUtime += cpu->timeProcess;
    pcbTable->processoSimulado[*runningState].state = BLOQUEADO;
    enfileirar(&(blockedState->filaBlocked), *runningState);
    desenfileirar(&(readyState->filaReady), runningState);
    pcbTable->processoSimulado[*runningState].state = EXECUTANDO;
    cpu->n = pcbTable->processoSimulado[*runningState].n;
    cpu->vetorProgram = pcbTable->processoSimulado[*runningState].vetorProgram;
    cpu->PC = (int) pcbTable->processoSimulado[*runningState].PC;
    cpu->timeProcess = calcularFatia(pcbTable->processoSimulado[*runningState].priority);
}

void instrucaoE(Cpu *cpu, PcbTable *pcbTable, RunningState *runningState, BlockedState *blockedState, ReadyState *readyState){
    free(pcbTable->processoSimulado[*runningState].vetorProgram);
    desenfileirar(&(blockedState->filaBlocked), runningState);
    desenfileirar(&(readyState->filaReady), runningState);
    pcbTable->processoSimulado[*runningState].state = EXECUTANDO;
    cpu->n = pcbTable->processoSimulado[*runningState].n;
    cpu->vetorProgram = pcbTable->processoSimulado[*runningState].vetorProgram;
    cpu->PC = (int) pcbTable->processoSimulado[*runningState].PC;
    cpu->timeProcess = calcularFatia(pcbTable->processoSimulado[*runningState].priority);
}

void instrucaoF(char *instrucao, Cpu *cpu){
    cpu->PC = cpu->PC + recuperarN(instrucao);
}

void instrucaoR(char *instrucao, char* nome){

}

void comandoQ(ProcessManager *processManager){
    int PC = processManager->cpu.PC;
    char *instrucao, *arqNovoProcesso = NULL;
    instrucao = processManager->cpu.vetorProgram[PC];

    if(instrucao[0] == 'S'){
        instrucaoS(instrucao, &(processManager->cpu));
    }
    if(instrucao[0] == 'A'){
        instrucaoA(instrucao, &(processManager->cpu));
    }
    if(instrucao[0] == 'D'){
        instrucaoD(instrucao, &(processManager->cpu));
    }
    if(instrucao[0] == 'B'){
        instrucaoB(&(processManager->cpu), &(processManager->pcbTable), &(processManager->runningState), &(processManager->blockedState), &(processManager->readyState));
    }
    if(instrucao[0] == 'E'){
        instrucaoE(&(processManager->cpu), &(processManager->pcbTable), &(processManager->runningState), &(processManager->blockedState), &(processManager->readyState));
    }
    if(instrucao[0] == 'F'){
        instrucaoF(instrucao, &(processManager->cpu));
    }
    if(instrucao[0] == 'R'){
        instrucaoR(instrucao, arqNovoProcesso);
    }

    if(instrucao[0] == 'F' || instrucao[0] == 'R'){
        executarInstrucao(instrucao, &(processManager->cpu.n), arqNovoProcesso); //Executar proxima linha de programa do processo
    }
    else{
        executarInstrucao(instrucao, &(processManager->cpu.n), arqNovoProcesso); //Executar proxima linha de programa do processo
        processManager->cpu.PC = PC + 1;
    }
    processManager->time = processManager->time + 1;
    //escalonar(processManager);
}

void comandoU(ProcessManager *processManager){
    int indiceProcesso;
    desenfileirar(&(processManager->blockedState.filaBlocked), &indiceProcesso);
    enfileirar(&(processManager->readyState.filaReady), indiceProcesso);
    processManager->pcbTable.processoSimulado[indiceProcesso].state = PRONTO;
}

void comandoP(ProcessManager *processManager){
    imprimirReporter(*processManager);
}

void comandoT(ProcessManager *processManager){
    imprimirReporter(*processManager);
    //Finalizar sistema
}

void leituraCommander(ProcessManager *processManager, char comando){
    if(comando == 'Q') comandoQ(processManager);
    if(comando == 'U') comandoU(processManager);
    if(comando == 'P') comandoP(processManager);
    if(comando == 'T') comandoT(processManager);
}