#include <stdio.h>
#include "juego.h"

char mapa[FILAS][COLUMNAS];

int fJugador= 5;
int cJugador= 5;

void iniciarMapa(){
    int i, j;

    for(i=0; i<FILAS; i++){
        for(j = 0; j < COLUMNAS; j++)
        {
            mapa[i][j] = '.';
        }
    }

    for(i=0; i<FILAS; i++){
        mapa[i][0]= '#';
        mapa[i][COLUMNAS-1]= '#';
    }

    for(j=0; j<COLUMNAS; j++)
    {
        mapa[0][j]= '#';
        mapa[FILAS-1][j]= '#';
    }

    mapa[fJugador][cJugador]= 'P';
}

void mostrarVentana(){
    int inicioFila;
    int inicioColumna;
    int i, j;

    printf("Mostrando ventana: \n");

    inicioFila= fJugador - 10;
    inicioColumna= cJugador - 10;

    if(inicioFila < 0){
        inicioFila= 0;
    }

    if(inicioColumna < 0){
        inicioColumna= 0;
    }

    if(inicioFila > FILAS - VENTANA_FILAS){
        inicioFila= FILAS - VENTANA_FILAS;
    }

    if(inicioColumna > COLUMNAS - VENTANA_COLUMNAS){
        inicioColumna= COLUMNAS - VENTANA_COLUMNAS;
    }

    for(i= inicioFila; i<inicioFila + VENTANA_FILAS; i++){
        for(j = inicioColumna; j < inicioColumna + VENTANA_COLUMNAS; j++){
            printf("%c", mapa[i][j]);
        }

        printf("\n");
    }
}

void iniciarJuego(){
    iniciarMapa();

    printf("BitQuest iniciado\n");

    mostrarVentana();
}