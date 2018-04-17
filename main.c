#include <stdio.h>
#include <stdlib.h>
#include "Commander.h"
#include <syscall.h>

int main() {
    int control = 0;

    while(control == 0){
        printf("Commander via arquivo ou entrada padrão?\n");
        printf("\t1 - Arquivo\n");
        printf("\t2 - Entrada padrão\n");
        printf("Opcao: ");
        scanf("%d", &control);

        switch(control){
            case 1:
                entradaArquivo();
                break;
            case 2:
                entradaPadrao();
                break;
            default:
                printf("Opcao invalida, pressione qualquer tecla para continuar...");
                control = 0;
                getchar();
                getchar();
                system("clear");
        }
    }
    return 0;
}