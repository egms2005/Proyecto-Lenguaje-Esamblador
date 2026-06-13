#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "juego.h"
#include "mapas.h"

char mapa[FILAS][COLUMNAS];

int fJugador= 5;
int cJugador= 5;

int nivelActual= 1;

int monedasRec= 0;
int tieneLlave= 0;

int pasos= 0;
int nivelesComp= 0;

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

    if(detectarObjeto(&mapa[0][0],COLUMNAS,nuevaFila,nuevaColumna,'M')){
            monedasRec++;

            mapa[nuevaFila][nuevaColumna]= '.';
        }
    
    if(detectarObjeto(&mapa[0][0],COLUMNAS,nuevaFila,nuevaColumna,'K')){
        tieneLlave= 1;

        mapa[nuevaFila][nuevaColumna]= '.';
    }

    mapa[fJugador][cJugador]= '.';

    fJugador= nuevaFila;
    cJugador= nuevaColumna;

    pasos++;

    mapa[fJugador][cJugador]= 'P';

    
}

void cargarNivel(int nivel){
    int i, j;

    for(i=0; i<FILAS; i++){
        for(j =0; j<COLUMNAS; j++){
            if(nivel == 1){
                mapa[i][j]= nivel1[i][j];
            }

            else if(nivel == 2){
                mapa[i][j]= nivel2[i][j];
            }

            else if(nivel == 3){
                mapa[i][j]= nivel3[i][j];
            }

            if(mapa[i][j] == 'P'){
                fJugador= i;
                cJugador= j;
            }
        }
    }

    int libres;
    int monedas;

    libres= contarCeldasLib(
        &mapa[0][0],
        FILAS * COLUMNAS
    );

    monedas= contarCaracter(&mapa[0][0], FILAS * COLUMNAS, 'M');
    
    printf("Celdas libres: %d\n", libres);
    printf("Monedas en el nivel: %d\n", monedas);

}

void iniciarJuego(){
    char tecla;

    cargarNivel(nivelActual);

    while(1){
        system("cls");

        mostrarVentana();
        
        printf("\nMonedas: %d", monedasRec);
        printf("\nLlave: %s", tieneLlave ? "SI" : "NO");

        printf("\n\nW= Arriba | A: Izquierda | S: Abajo | D: Derecha\n");
        printf("Q: Salir\n");

        scanf(" %c", &tecla);

        if(tecla == 'q' || tecla == 'Q'){
            break;
        }

        moverJugador(tecla);
    }
}