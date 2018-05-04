//
// Created by caio on 16/04/18.
//

#include <stdlib.h>
#include "ProcessoSimulado.h"
#include "ProcessManager.h"


void lerPrograma(char **vetorProgram, char* nomeArq){
    vetorProgram = leituraArq(nomeArq, MAXTAMINSTRUCTION);
}