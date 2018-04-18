//
// Created by caio on 16/04/18.
//

#include "Reporter.h"
#include "ProcessManager.h"
#include "ProcessoSimulado.h"

void imprimirReporter(ProcessManager processManager){
    ProcessoSimulado processoSimulado;
    processoSimulado = processManager.pcbTable.processoSimulado[processManager.runningState];
    printf("**************************************************\n");
    printf("The current system state is as follows: \n");
    printf("**************************************************\n");
    printf("CURRENT TIME: %d\n", processManager.time);
    printf("RUNNING PROCESS:\n");
    printf("PID: %d\tPPID: %d\tPriority: %d\tValue: %d\tStart Time: %d\tCPU Time: %d\n", processoSimulado.PID,
           processoSimulado.PPID, processoSimulado.priority, processoSimulado.n, processoSimulado.startTime, processoSimulado.CPUtime);
    printf("BLOCKED PROCESSES:\n");
    printf("Queue of blocked processes:\n");
    imprimeFila(&(processManager.blockedState.filaBlocked),processManager.pcbTable);
    printf("PROCESSES READY TO EXECUTE:\n");
    printf("Queue of processes ready:\n");
    imprimeFila(&(processManager.readyState.filaReady),processManager.pcbTable);
}