#!/bin/bash

EXECFILE=./push_swap

function executa_teste_com_aspa()
{
    TESTCASE=${1}
    echo "Testando COM ASPAS, o caso \"${TESTCASE}\":"
    ${EXECFILE} "${TESTCASE}"
    echo -ne "\n----------------------------\n"
}
function executa_teste_sem_aspa()
{
    TESTCASE=${1}
    echo "Testando SEM ASPAS, o caso ${TESTCASE}:"
    ${EXECFILE} ${TESTCASE}
    echo -ne "\n----------------------------\n"
}
                    
executa_teste_com_aspa "1 2 3 4 5"
executa_teste_com_aspa "1 23456 6432126 954 -124"
executa_teste_com_aspa "23 *& ()"
executa_teste_com_aspa " 23  "
executa_teste_com_aspa ""
executa_teste_com_aspa "  "

executa_teste_sem_aspa "8 9 10 100"

