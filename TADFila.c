//
// Created by caio on 18/04/18.
//

#include "TADFila.h"
#include "ProcessManager.h"

void fazFVazia(TFila *pFila){
    pFila->pFrente = (TCelula*) malloc(sizeof(TCelula));
    pFila->pTras = pFila->pFrente;
    pFila->pFrente->pProx = NULL;
    pFila->tamanho = 0;
}

int verificaFilaVazia(TFila *pFila){
    return (pFila->pTras == pFila->pFrente);
}

int enfileirar(TFila *pFila, int indiceProcessoSimulado){
    TCelula *pCelAux;
    pCelAux = (TCelula*) malloc(sizeof(TCelula));
    if(pCelAux == NULL) return 0;
    pFila->pTras->pProx = pCelAux;
    pFila->pTras = pCelAux;
    pCelAux->indiceProcessoSimulado = indiceProcessoSimulado;
    pCelAux->pProx = NULL;
    pFila->tamanho++;

}

int desenfileirar(TFila *pFila, int *indiceProcessoSimulado){
    TCelula *pCelAux;
    if(verificaFilaVazia(pFila)) return 0;
    pCelAux = pFila->pFrente;
    pFila->pFrente-> = pFila->pFrente->pProx;
    indiceProcessoSimulado = pFila->pFrente->indiceProcessoSimulado;
    free(pCelAux);
    pFila->tamanho--;
    return 1;
}

int tamFila(TFila *pFila){
    return (pFila->tamanho);
}

void imprimeFila(TFila *pFila, PcbTable pcbTable){
    TCelula *pCelAux;
    ProcessoSimulado processoSimulado;
    pCelAux = pFila->pFrente->pProx;
    while(pCelAux->pProx != NULL){
        processoSimulado = pcbTable.processoSimulado[pCelAux->indiceProcessoSimulado];
        printf("PID: %d\tPPID: %d\tPriority: %d\tValue: %d\tStart Time: %d\tCPU Time: %d\n", processoSimulado.PID,
               processoSimulado.PPID, processoSimulado.priority, processoSimulado.n, processoSimulado.startTime, processoSimulado.CPUtime);
        pCelAux = pCelAux->pProx;
    }
}
