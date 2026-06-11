#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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

void moverJugador(char tecla){
    int nuevaFila = fJugador;
    int nuevaColumna = cJugador;

    tecla= tolower(tecla);

    if(tecla == 'w'){
        nuevaFila--;
    }

    else if(tecla == 's'){
        nuevaFila++;
    }

    else if(tecla == 'a'){
        nuevaColumna--;
    }

    else if(tecla == 'd'){
        nuevaColumna++;
    }

    if(!validarMovimiento(&mapa[0][0],COLUMNAS,nuevaFila,nuevaColumna)){
        return;
    }

    mapa[fJugador][cJugador]= '.';

    fJugador= nuevaFila;
    cJugador= nuevaColumna;

    mapa[fJugador][cJugador]= 'P';
}

void iniciarJuego(){
    char tecla;

    iniciarMapa();

    while(1){
        system("cls");

        mostrarVentana();

        printf("\nW A S D mover\n");
        printf("Q salir\n");

        scanf(" %c", &tecla);

        if(tecla == 'q' || tecla == 'Q')
        {
            break;
        }

        moverJugador(tecla);
    }
}