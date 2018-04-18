//
// Created by caio on 16/04/18.
//

#include "ProcessoSimulado.h"
#include "Reporter.h"

#ifndef TP2SO_PROCESSMANAGER_H
#define TP2SO_PROCESSMANAGER_H

typedef int Time;

typedef struct {
    //armazenar um ponteiro para o vetor de programa -> struct do processo simulado
    ProcessoSimulado *processo;

}Cpu;

typedef  struct {
    //Lista(Vetor) de processos que ainda não terminou a sua execução
}PcbTable;

typedef struct {
    //Lista de processos que estão prontos para executar ----- Usar fila ou fila de prioridades
}ReadyState;

typedef struct {
    //Lista de processos que estão bloqueados no momento ----- Usar fila
}BlockedState;

typedef struct {
    //Processo que está sendo executado no momento----- Usar indice de PcbTable do processo simulado atualmente em execução
    ProcessoSimulado * processo;
}RunningState;


typedef struct {
    Time time;
    Cpu cpu;
    PcbTable pcbTable;
    ReadyState readyState;
    BlockedState blockedState;
    RunningState runningState;
}ProcessManager;

ProcessManager iniciarProcessManager(); //Criar o primeiro processo (com o ID = 0) e inicializar todas as suas estruturas de dados
void leituraCommander(ProcessManager *processManager,char comando); // process manager recebe, repetidamente, e processa um comando por vez, a partir do processo commander
                         /* Ao receber um comando Q, process manager
                            executa a próxima instrução do processo simulado, atualmente em execução, incrementa
                            o valor do contador de programa (exceto para instruções F ou R), incrementa Time e
                            depois faz o escalonamento. Observe que o escalonamento pode envolver a troca de
                            contexto.

                            Ao receber um comando U, process manager move o primeiro processo simulado da fila
                            bloqueada para a fila de estado pronto para executar. Ao receber um comando P, process
                            manager dispara um novo processo reporter. Ao receber um comando T, process manager
                            primeiro dispara um processo reporter e depois termina após a finalização do processo
                            reporter. Process manager garante que apenas um processo reporter execute ao mesmo
                            tempo.

                         */

#endif //TP2SO_PROCESSMANAGER_H
