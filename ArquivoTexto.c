//
// Created by caio on 16/04/18.
//


#include "ArquivoTexto.h"

int quantLinhas(char *nomeArq){
    FILE *arq;
    char caractere;
    int cont = 0;
    arq = fopen(nomeArq, "r");
    if(arq == NULL){
        printf("Erro ao abrir arquivo!");
    }
    while(!feof(arq)){
        caractere = fgetc(arq);
        if(caractere == '\n'){
            cont++;
        }
    }
    fclose(arq);
    return cont;
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
    char** programa;
    int linhas = quantLinhas(nomeArq), i = 0;
    char leitura[MAXTAMINSTRUCAO];
    FILE *arq;
    programa = alocarMatriz(linhas, MAXTAMINSTRUCAO);
    //arq = fopen(nomeArq, "r");
    arq = fopen("/home/caio/Desktop/TP2SO/init", "r");
    if(arq == NULL){
        printf("Erro ao abrir arquivo!");
    }

    while(!feof(arq)){
        fgets(leitura, MAXTAMINSTRUCAO, arq);
        strcpy(programa[i],leitura);
        i++;
    }
    fclose(arq);

    return programa;
}