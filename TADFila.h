//
// Created by caio on 18/04/18.
//


#ifndef TP2SO_TADFILA_H
#define TP2SO_TADFILA_H

#include <stdio.h>
#include <stdlib.h>
#include "ProcessoSimulado.h"
#include "ProcessManager.h"
/*Estrutura para Fila por Apontadores*/

typedef struct Celula *Apontador;

typedef struct Celula{
    int indiceProcessoSimulado;
    Apontador pProx;
}TCelula;

typedef struct{
    TCelula *pFrente;
    TCelula *pTras;
    int tamanho;
}TFila;

void fazFVazia(TFila *pFila);
int verificaFilaVazia(TFila *pFila);
int enfileirar(TFila *pFila, int indiceProcessoSimulado);
int desenfileirar(TFila *pFila, int *indiceProcessoSimulado);
void imprimeFila(TFila *pFila, PcbTable pcbTable);
#endif //TP2SO_TADFILA_H