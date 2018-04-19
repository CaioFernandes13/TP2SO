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

void comandoQ(ProcessManager *processManager){
    int PC = processManager->cpu.PC;
    char *instrucao, *arqNovoProcesso;
    instrucao = processManager->cpu.vetorProgram[PC];
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