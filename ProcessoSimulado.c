//
// Created by caio on 16/04/18.
//

#include <stdlib.h>
#include "ProcessoSimulado.h"
#include "ProcessManager.h"


void lerPrograma(ProcessoSimulado *processoSimulado, char* nomeArq){
    processoSimulado->vetorProgram = leituraArq(nomeArq, MAXTAMINSTRUCTION);

}

void instrucaoS(ProcessoSimulado *processoSimulado, int n){

}

void instrucaoA(ProcessoSimulado *processoSimulado, int n){

}

void instrucaoD(ProcessoSimulado *processoSimulado, int n){

}

void instrucaoB(ProcessoSimulado *processoSimulado){

}

void instrucaoE(ProcessoSimulado *processoSimulado){

}

void instrucaoF(ProcessoSimulado *processoSimulado, int n){

}

void instrucaoR(ProcessoSimulado *processoSimulado, char* nome){

}

void executarProcesso(ProcessoSimulado *processoSimulado){
    char instrucao;
    char nomeArq[100];
    int n;
    instrucao = processoSimulado->vetorProgram[*(processoSimulado->PC)][0];
    if(instrucao == 'S'){
        instrucaoS(processoSimulado, n);
    }
    if(instrucao == 'A'){
        instrucaoA(processoSimulado, n);
    }
    if(instrucao == 'D'){
        instrucaoD(processoSimulado, n);
    }
    if(instrucao == 'B') instrucaoB(processoSimulado);
    if(instrucao == 'E') instrucaoE(processoSimulado);
    if(instrucao == 'F'){
        instrucaoF(processoSimulado, n);
    }
    if(instrucao == 'R'){
        instrucaoR(processoSimulado, nomeArq);
    }
}