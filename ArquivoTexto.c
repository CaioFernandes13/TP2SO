//
// Created by caio on 16/04/18.
//

#include <stdlib.h>
#include "ArquivoTexto.h"

int quantLinhas(char *nomeArq){

}

char** alocarMatriz(int linhas, int colunas){
    char** matriz;
    int i;

    matriz = (char**) malloc(linhas * sizeof(char*));
    for (i = 0; i < linhas; ++i) {
        matriz[i] = (char*) malloc(colunas * sizeof(char));
    }

    return matriz;
}

char** leituraArq(char *nomeArq, int MAXTAMINSTRUCAO){
    char** leitura;
    int linhas = quantLinhas(nomeArq), i;
    leitura = alocarMatriz(linhas, MAXTAMINSTRUCAO);
}