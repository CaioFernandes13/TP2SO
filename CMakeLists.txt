cmake_minimum_required(VERSION 3.10)
project(TP2SO C)

set(CMAKE_C_STANDARD 99)

#add_executable(TP2SO main.c)
add_executable(TP2SO main.c Commander.c Commander.h ProcessManager.c ProcessManager.h Reporter.c Reporter.h ProcessoSimulado.c ProcessoSimulado.h ArquivoTexto.c ArquivoTexto.h TADFila.c TADFila.h)