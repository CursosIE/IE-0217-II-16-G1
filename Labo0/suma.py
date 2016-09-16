#!/usr/bin/python

## @file suma.py
# @author Brizula M, Morera B
# @date 19 Agosto 2016
# Documentacion interna utilizando doxygen
# Funcion que recibe 'n' parametros y retorna la suma de estos

import sys


## @brief Documentacion de la funcion suma.
#
# Esta funcion no recibe parametros explicitamente, toma los parametros de 'sys.argv'. Suma todos los numero dados y retorna la sumatoria.
def suma():
    Arguments = sys.argv[1:]
    Result = 0.0
    for argument in Arguments:
        Result += float(argument)
    print "El resultado es: " + str(Result)

suma()
