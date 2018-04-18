//
// Created by caio on 16/04/18.
//

#include <stdlib.h>
#include "ProcessoSimulado.h"
#include "ProcessManager.h"


void lerPrograma(ProcessoSimulado *processoSimulado, char* nomeArq){
    processoSimulado->vetorProgram = leituraArq(nomeArq, MAXTAMINSTRUCTION);

}

void instrucaoS(char *instrucao, int n){

}

void instrucaoA(char *instrucao, int n){

}

void instrucaoD(char *instrucao, int n){

}

void instrucaoB(char *instrucao){

}

void instrucaoE(char *instrucao){

}

void instrucaoF(char *instrucao, int n){

}

void instrucaoR(char *instrucao, char* nome){

}

void executarInstrucao(char *instrucao, int *n, char *arqNovoProcesso){
    if(instrucao == 'S'){
        instrucaoS(instrucao, n);
    }
    if(instrucao == 'A'){
        instrucaoA(instrucao, n);
    }
    if(instrucao == 'D'){
        instrucaoD(instrucao, n);
    }
    if(instrucao == 'B') instrucaoB(instrucao);
    if(instrucao == 'E') instrucaoE(instrucao);
    if(instrucao == 'F'){
        instrucaoF(instrucao, n);
    }
    if(instrucao == 'R'){
        instrucaoR(instrucao, arqNovoProcesso);
    }
}