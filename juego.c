#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

#include "juego.h"
#include "mapas.h"

//Matriz principal donde se almacena el mapa actual
char mapa[FILAS][COLUMNAS];

//Variables para la posicion del jugador
int fJugador= 5;
int cJugador= 5;

int nivelActual= 1;

//Variables para el control de monedas
int monedasNivel= 0;
int monedasNivelRec= 0;
int monedasRec= 0;
int monedasTotal= 0;

int tieneLlave= 0;

//Estadisticas generales del juego
int pasos= 0;
int nivelesComp= 0;

/*
    Funcion para mostrar una ventana de 20x20
    centrada alrededor de la posicion actual
    del juegador.
*/
void mostrarVentana(){
    int inicioFila;
    int inicioColumna;
    int i, j;

    printf("Mostrando ventana: \n");

    inicioFila= fJugador - 10;
    inicioColumna= cJugador - 10;

    //Evita que la ventana salga por arriba o la izquierda
    if(inicioFila < 0){
        inicioFila= 0;
    }

    if(inicioColumna < 0){
        inicioColumna= 0;
    }

    //Evita que la ventana salga por abajo o la derecha
    if(inicioFila > FILAS - VENTANA_FILAS){
        inicioFila= FILAS - VENTANA_FILAS;
    }

    if(inicioColumna > COLUMNAS - VENTANA_COLUMNAS){
        inicioColumna= COLUMNAS - VENTANA_COLUMNAS;
    }

    //Imprime la seccion visible del mapa
    for(i= inicioFila; i<inicioFila + VENTANA_FILAS; i++){
        for(j = inicioColumna; j < inicioColumna + VENTANA_COLUMNAS; j++){
            printf("%c", mapa[i][j]);
        }

        printf("\n");
    }
}

/*
    Funcion para procesar el movimiento del jugador, 
    validar colisiones, recoger monedas y detectar la
    finalizacion de un nivel y del juego.
*/
void moverJugador(char tecla){
    int nuevaFila = fJugador;
    int nuevaColumna = cJugador;

    tecla= tolower(tecla);
    
    /*
        Seccion para determinar la nueva posicion segun
        la tecla presionada.
    */
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
    
    //Verifica que el movimiento sea valido
    if(!validarMovimiento(&mapa[0][0],COLUMNAS,nuevaFila,nuevaColumna)){
        return;
    }

    //Recoleccion de monedas
    if(detectarObjeto(&mapa[0][0],COLUMNAS,nuevaFila,nuevaColumna,'M')){
            monedasRec++;
            monedasNivelRec++;

            mapa[nuevaFila][nuevaColumna]= '.';
        }
    
    //Recoleccion de la llave
    if(detectarObjeto(&mapa[0][0],COLUMNAS,nuevaFila,nuevaColumna,'K')){
        tieneLlave= 1;

        mapa[nuevaFila][nuevaColumna]= '.';
    }

    //Validacion de la puerta
    if(detectarObjeto(&mapa[0][0], COLUMNAS, nuevaFila, nuevaColumna, 'D')){
        if(!tieneLlave){
            printf("\nNecesitas una llave\n");
            return;
        }
    }

    char objetoDestino;

    //Guarda el contenido de la celda destino
    objetoDestino= mapa[nuevaFila][nuevaColumna];  

    //Actualiza la posicion del jugador
    mapa[fJugador][cJugador]= '.';

    fJugador= nuevaFila;
    cJugador= nuevaColumna;

    pasos++;

    mapa[fJugador][cJugador]= 'P';

    //Verifica si se alcanzo la salida
    if(objetoDestino == 'E'){
        printf("\nNivel completado\n");

         nivelesComp++;

        int puntaje;
        char opc;
        
        //Llama a la rutina para calcular el puntaje
        puntaje= calcularPuntaje(monedasRec, pasos, nivelesComp);
        
        //Resumen del nivel
        printf("\n===== Resumen del nivel =====\n");
        printf("Monedas recolectadas: %d\nMonedas en el nivel: %d\n", monedasNivelRec, monedasNivel);
        printf("Pasos realizados hasta ahora: %d\n", pasos);
        printf("Niveles completados: %d\n", nivelesComp);
        printf("Puntaje actual: %d\n", puntaje);
        printf("=============================\n");

        do{
            printf("Presione c para continuar...\n");
            scanf(" %c", &opc);

        }while(opc != 'c' && opc != 'C');
        
        nivelActual++;

        //Carga el nivel si existe
        if(nivelActual <= 3){
                tieneLlave= 0;
                monedasNivelRec= 0;
                cargarNivel(nivelActual);
            
        }else{
            int puntajeFinal;

            puntajeFinal= calcularPuntaje(monedasRec, pasos, nivelesComp);

            //Resumen final del juego
            printf("\n===== Juego completado =====\n");
            printf("Monedas recolectadas: %d\nMonedas totales: %d\n", monedasRec, monedasTotal);
            printf("Pasos realizados totales: %d\n", pasos);
            printf("Niveles completados: %d\n", nivelesComp);
            printf("Puntaje final: %d\n", puntajeFinal);
            printf("============================\n");

            do{
                printf("Presione c para terminar el juego...\n");
                scanf(" %c", &opc);

            }while(opc != 'c' && opc != 'C');

            exit(0);
        }
    }
}

/*
    Funcion para cargar uno de los mapas definidos 
    en mapas.h y obtener la informacion del nivel
    mediante las funciones implementadas en NASM.
*/
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

            //Busca la posicion inicial del jugador
            if(mapa[i][j] == 'P'){
                fJugador= i;
                cJugador= j;
            }
        }
    }

    int libres;

    //Cuenta las celdas libres del nivel usando la rutina en NASM
    libres= contarCeldasLib(&mapa[0][0],FILAS * COLUMNAS);

    //Cuenta las monedas del nivel usando la rutina en NASM
    monedasNivel= contarCaracter(&mapa[0][0], FILAS * COLUMNAS, 'M');
    
    monedasTotal+= monedasNivel;

    printf("Celdas libres en el nivel: %d\n", libres);
    printf("Monedas en el nivel: %d\n", monedasNivel);

    system("pause");

}

/*
    Funcion principal del juego, controla el ciclo
    de ejecucion y la lectura de teclas del jugador.
*/

void iniciarJuego(){
    char tecla;

    cargarNivel(nivelActual);

    while(1){
        system("cls");

        mostrarVentana();

        printf("\nMonedas: %d/%d", monedasNivelRec, monedasNivel);
        printf("\nLlave: %s", tieneLlave ? "Si" : "No");

        printf("\n\nW: Arriba | A: Izquierda | S: Abajo | D: Derecha\n");
        printf("Q: Salir\n");

        tecla = getch();

        if(tecla == 'q' || tecla == 'Q'){
            break;
        }

        moverJugador(tecla);
    }
}