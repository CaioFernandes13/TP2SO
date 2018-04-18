//
// Created by caio on 16/04/18.
//

#include "ProcessManager.h"
#include "ProcessoSimulado.h"

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

    processoSimulado.PID = 0;
    processoSimulado.PPID = 0;
    lerPrograma(&processoSimulado, "init");
    processoSimulado.CPUtime = 0;
    processoSimulado.n = 0;
    *(processoSimulado.PC) = -1;
    processoSimulado.priority = 0;
    processoSimulado.startTime = 0;
    processoSimulado.state = 0;

    processManager.time = 0;
    processManager.cpu.processo = &processoSimulado;
    processManager.runningState.processo = &processoSimulado;
    iniciarBlockedState(&processManager);
    iniciarReadyState(&processManager);
    iniciarPcbTable(&processManager, processoSimulado);

    return processManager;
}



void comandoQ(ProcessManager *processManager){
    int PC = processManager->cpu.processo->PC;
    char instrucao;
    instrucao = processManager->cpu.processo->vetorProgram[PC+1][0];
    if(instrucao == 'F' || instrucao == 'R');
    else{
        processManager->cpu.processo->PC = PC + 1;
        executarProcesso(&(processManager->cpu.processo)); //Executar proxima linha de programa do processo
    }
    processManager->time = processManager->time + 1;
    //escalonar(processManager);

}

void comandoU(ProcessManager *processManager){
    ProcessoSimulado processoSimuladoProx;
    //processoSimuladoProx = processManager->blockedState.primeiro;
    //processManager->blockedState.primeiro = processManager->blockedState.primeiro.prox;
    //insereReadyState(processManager->readyState, processoSimuladoProx);
}

void comandoP(ProcessManager *processManager){
    //imprimirReporter(processManager);
}

void comandoT(ProcessManager *processManager){
    //imprimirReporter(processManager);
}

void leituraCommander(ProcessManager *processManager, char comando){
    if(comando == 'Q') comandoQ(processManager);
    if(comando == 'U') comandoU(processManager);
    if(comando == 'P') comandoP(processManager);
    if(comando == 'T') comandoT(processManager);
}