//
// Created by caio on 16/04/18.
//

#include <stdlib.h>
#include "ProcessoSimulado.h"



void lerPrograma(ProcessoSimulado processoSimulado, char* nomeArq){
    processoSimulado.vetorProgram = leituraArq(nomeArq, MAXTAMINSTRUCTION);

}