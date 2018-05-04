//
// Created by caio on 16/04/18.
//


#ifndef TP2SO_PROCESSOSIMULADO_H
#define TP2SO_PROCESSOSIMULADO_H
#define MAXTAMINSTRUCTION 100
#include <stdlib.h>
#include <stdio.h>
#include "ProcessManager.h"
#include "ArquivoTexto.h"

enum flagPCBTable {SIM, NAO};
typedef struct {
    int PID;
    int PPID;
    int *PC; //Contador de programa
    int n; //Valor inteiro que será modificado
    int priority; //prioridade do processo
    int state; //Estado do processo (0 - Executando, 1 - Pronto para execução, 2 - Bloqueado)
    int startTime; //Tempo de início
    int CPUtime; //Tempo de CPU
    char **vetorProgram; //Vetor de programa -- Matriz que armazena as instruções do processo;
    int flag;
}ProcessoSimulado;

void lerPrograma(char **vetorProgram, char* nomeArq);
#endif //TP2SO_PROCESSOSIMULADO_H
