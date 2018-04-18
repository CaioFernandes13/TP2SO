//
// Created by caio on 18/04/18.
//

#include "TADFila.h"
#include "ProcessoSimulado.h"

void fazFVazia(TFila *pFila){
    pFila->pFrente = (TCelula*) malloc(sizeof(TCelula));
    pFila->pTras = pFila->pFrente;
    pFila->pFrente->pProx = NULL;
    pFila->tamanho = 0;
}

int verificaFilaVazia(TFila *pFila){
    return (pFila->pTras == pFila->pFrente);
}

int enfileirar(TFila *pFila, ProcessoSimulado *processoSimulado){
    TCelula *pCelAux;
    pCelAux = (TCelula*) malloc(sizeof(TCelula));
    if(pCelAux == NULL) return 0;
    pFila->pTras->pProx = pCelAux;
    pFila->pTras = pCelAux;
    pCelAux->processoSimulado = *processoSimulado;
    pCelAux->pProx = NULL;
    pFila->tamanho++;

}

int desenfileirar(TFila *pFila, ProcessoSimulado *processoSimulado){
    TCelula *pCelAux;
    if(verificaFilaVazia(pFila)) return 0;
    pCelAux = pFila->pFrente;
    pFila->pFrente-> = pFila->pFrente->pProx;
    *processoSimulado = pFila->pFrente->processoSimulado;
    free(pCelAux);
    pFila->tamanho--;
    return 1;
}

int tamFila(TFila *pFila){
    return (pFila->tamanho);
}

void imprimeFila(TFila *pFila){
    TCelula *pCelAux;
    pCelAux = pFila->pFrente->pProx;
    while(pCelAux->pProx != NULL){
        printf("\n %d",pCelAux->processoSimulado.PID);
        pCelAux = pCelAux->pProx;
    }
}
