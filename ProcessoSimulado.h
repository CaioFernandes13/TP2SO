//
// Created by caio on 16/04/18.
//

#include "ArquivoTexto.h"
#include <stdlib.h>
#include <stdio.h>

#ifndef TP2SO_PROCESSOSIMULADO_H
#define TP2SO_PROCESSOSIMULADO_H
#define MAXTAMINSTRUCTION 100

typedef struct {
    int PID;
    int PPID;
    int *PC; //Contador de programa
    int n; //Valor inteiro que será modificado
    int priority; //prioridade do processo
    int state; //Estado do processo (Executando, Bloqueado, Pronto para execução)
    int startTime; //Tempo de início
    int CPUtime; //Tempo de CPU
    char **vetorProgram; //Vetor de programa -- Matriz que armazena as instruções do processo;
}ProcessoSimulado;

void lerPrograma(ProcessoSimulado processoSimulado, char* nomeArq);
#endif //TP2SO_PROCESSOSIMULADO_H
