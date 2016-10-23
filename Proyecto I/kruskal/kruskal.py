#!/usr/bin/env python
 # coding=utf-8
## @package pyexample

## @file Kruskal.py
# @author Brizula M, Morera B
# @date 21 Octubre 2016

import pygame
from pygame.locals import *
import sys
from random import randint
import inputbox
import os
from time import sleep

parametrosCpp = 'kruskal/confTxt/entradaCpp.txt'
salidaInterfaz = 'kruskal/confTxt/pesosKruskal.txt'

## @brief Método crearArchivoSalida
#
# Crea un archivo, el cual es la entrada para el binario escrito en C++. Contiene
# la cantidad de vertices y los pesos para la matriz de adyacencia. Este método
# no recibe parametros.
def crearArchivoSalida():
    archivoSalida = open(parametrosCpp, 'w')
    archivoSalida.close()

## @brief Función grabarArchivoSalida
#
# Guarda la salida en el archivo que servira como parametros de entrada para el
# binario.
# @param cantVertices Entero cantidad de vertices del grafo.
# @param vectorPesoArista Vector que contiene
def grabarArchivoSalida(cantVertices, vectorPesoArista):
    archivoSalida = open(parametrosCpp, 'a')
    archivoSalida.write(str(cantVertices)+" ")
    for peso in xrange(len(vectorPesoArista)):
        archivoSalida.write(str(vectorPesoArista[peso])+" ")
    archivoSalida.close()

## @brief Función dibujarCirculo
#
# Función encargada de dibujar círculos de color aleatoreo. Recibe dos parametros.
# @param screen Pantalla donde se dibujará el círculo.
# @param posicion Posicion del círculo en la pantalla.
def dibujarCirculo(screen, posicion):
    randomColorCirculo = (randint(0,255), randint(0,255), randint(0,255))
    pygame.draw.circle(screen, randomColorCirculo, posicion, 12)

## @brief Función reConfigKruskal
#
# Función encargada de dibujar el árbol de mínima expansión. No edita el dibujo antes
# ingresado, solo repinta con color blanco las aristas que pertenecen al árbol resultante.
# @param contadorVertices Cantidad de vértices del grafo dibujado.
# @param posicionVerticesGrafo Arreglo de enteros de posiciones cartesianas en la pantalla de los vértices.
# @param screen Pantalla donde se dibuja el grafo.
# @param pesosAristas Arreglo de enteros de los pesos de las aristas.
# @param puntosLinea Arreglo de enteros de posiciones cartesianas en la pantalla de los puntos de las aristas, puntos de posición de un vértice de inicio y un vértice final.
# @param Datos Arreglo de los pesos de las aristas ordenados, este vector es el que se escribe en el archivo de salida.
def reConfigKruskal(contadorVertices, posicionVerticesGrafo, screen, pesosAristas, puntosLinea, Datos):
    pesosParametros = ""
    for dato in xrange(len(Datos)):
        pesosParametros += str(Datos[dato])+" "
    ## @var comandKruskal
    # Comando a correr en el sistema para utilizar el algoritmo en el binario de C++.
    comandKruskal = "./kruskal/correrKruskal " + str(contadorVertices) + " " + pesosParametros
    os.system(comandKruskal)
    ## Tiempo de espera
    # Tiempo dado para que se genera la salida del binario y se pueda leer.
    sleep(1.5)
    archivoPesosKruskal = open(salidaInterfaz, 'r')
    pesosArbolMinimo = archivoPesosKruskal.readline()
    archivoPesosKruskal.close()
    pesosArbolMinimo = pesosArbolMinimo.split(" ")
    pesosArbolMinimo.pop()
    cantAristaArbolMinimo = len(pesosArbolMinimo)
    for peso in xrange(cantAristaArbolMinimo):
            pesosArbolMinimo[peso] = int(pesosArbolMinimo[peso])
    ## For para dibujar el árbol de expansión mínima
    for peso in xrange(cantAristaArbolMinimo):
        for arista in xrange(len(pesosAristas)):
            if (pesosArbolMinimo[peso] == pesosAristas[arista]) and (pesosArbolMinimo[peso] != 0):
                puntoInicio = puntosLinea[2*arista]
                puntoFinal = puntosLinea[2*arista + 1]
                pygame.draw.line(screen, (255, 255, 255), puntoInicio, puntoFinal, 7)
## @brief Función correrKruskal
#
# Función corre la interfaz, crea el screen, lee los eventos constantemente y
# aplica las acciones como respuesta a estos eventos.
def correrKruskal():
    ## @brief Se inicializa pyGame, se crea el screen
    pygame.init()
    screenSize = (800, 400)
    screen = pygame.display.set_mode(screenSize, 0 ,32)
    pygame.display.set_caption("Kruskal Algorithm")

    ## @brief Se definen variables y arreglos
    #
    # Definicion botones del mouse.
    LEFT = 1
    RIGHT = 3
    ## Contadores
    contadorVertices = 0
    ## Arreglos;
    posicionVerticesGrafo = []
    puntosLinea = []
    pesosAristas = []
    Datos = []
    locate = [0]*2

    pygame.event.set_blocked(MOUSEMOTION)

    ## @brief Ciclo
    while True:
        ## Lee constantemente los eventos que ocurren, eventos de uso de mouse y
        # teclado.
        for event in pygame.event.get():
            if event.type == QUIT:
                exit()
            elif event.type == KEYDOWN:
                if event.key == K_q:
                    exit()
                ## Evento tecla: k
                #
                # Dicho evento obtiene el árbol de expansión mínima
                if event.key == K_k:
                    crearArchivoSalida()
                    grabarArchivoSalida(contadorVertices, Datos)
                    reConfigKruskal(contadorVertices, posicionVerticesGrafo, screen, pesosAristas, puntosLinea, Datos)
                ## Evento tecla: r
                #
                # Reinicia la interfaz, se puede dibujar otro grafo.
                if event.key == K_r:
                    correrKruskal()
            ## Verifia si los eventos son de tipo MOUSEBUTTONUP, entiendase cuando
            # el se presiona y se suelta el boton del mouse, este detecta cuando se
            # levanta el boton.
            elif event.type == MOUSEBUTTONUP:
                ## Si el boton presionado es el izquierdo, se dibuja los círculos
                if event.button == LEFT:
                    circuloPosicion = list(pygame.mouse.get_pos())
                    dibujarCirculo(screen, circuloPosicion)
                    posicionVerticesGrafo.append(circuloPosicion)
                    contadorVertices = contadorVertices + 1
                    for i in range(contadorVertices-1):
                        Datos.append(0)
                    myFont = pygame.font.SysFont("monospace", 18)
                    label = myFont.render(chr(64+contadorVertices), 1, (255,255,255))
                    screen.blit(label, (circuloPosicion[0]+10,circuloPosicion[1]+10))
                ## Si el boton presionado es el derecho, dibuja las aristas entre los vértices
                if event.button == RIGHT:
                    puntoTerminalLinea = list(pygame.mouse.get_pos())
                    for vertice in xrange(contadorVertices):
                        ## Dibuja las aristas en el centro del circulo de los vértices.
                        if (  abs(puntoTerminalLinea[0] - posicionVerticesGrafo[vertice][0])  ) < 12:
                            if (  abs(puntoTerminalLinea[1] - posicionVerticesGrafo[vertice][1])  ) < 12:
                                puntosLinea.append(posicionVerticesGrafo[vertice])
                                if len(puntosLinea)%2 == 0 and len(puntosLinea) != 0:
                                    locate[1] = vertice
                                else:
                                    locate[0] = vertice
                    ## Solicita el peso de las aristas cuando estas se dibujan.
                    if len(puntosLinea)%2 == 0 and len(puntosLinea) != 0:
                        randomColorLinea = (randint(0,255), randint(0,255), randint(0,255))
                        pygame.draw.line(screen, randomColorLinea, puntosLinea[-2], puntosLinea[-1], 5)
                        esEntero = False
                        try:
                            pesoAsignado = int(inputbox.ask(screen, 'Peso arista '))
                        except ValueError:
                            correrKruskal()

                        if locate[0]<locate[1]:
                            position = 0
                            for x in range(locate[1]):
                                position = position + x
                            Datos[position+locate[0]] = pesoAsignado
                        else:
                            position = 0
                            for x in range(locate[0]):
                                position = position + x
                            Datos[position+locate[1]] = pesoAsignado

                        ## Imprime los pesos al lado de las aristas.
                        myFont = pygame.font.SysFont("monospace", 18)
                        label = myFont.render(str(pesoAsignado), 1, (255,255,255))
                        xMedio = (puntosLinea[-1][0]+puntosLinea[-2][0])/2
                        yMedio = (puntosLinea[-1][1]+puntosLinea[-2][1])/2
                        screen.blit(label, (xMedio, yMedio))
                        pesosAristas.append(pesoAsignado)
        pygame.display.update()
correrKruskal()
