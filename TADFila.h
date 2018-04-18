//
// Created by caio on 18/04/18.
//
#include <stdio.h>
#include <stdlib.h>
#include "ProcessoSimulado.h"

#ifndef TP2SO_TADFILA_H
#define TP2SO_TADFILA_H

/*Estrutura para Fila por Apontadores*/

typedef struct Celula *Apontador;

typedef struct Celula{
    ProcessoSimulado processoSimulado;
    Apontador pProx;
}TCelula;

typedef struct{
    TCelula *pFrente;
    TCelula *pTras;
    int tamanho;
}TFila;

void fazFVazia(TFila *pFila);
int verificaFilaVazia(TFila *pFila);
int enfileirar(TFila *pFila, ProcessoSimulado *processoSimulado);
int desenfileirar(TFila *pFila, ProcessoSimulado *processoSimulado);
int tamFila(TFila *pFila);
void imprimeFila(TFila *pFila);
#endif //TP2SO_TADFILA_H
