#ifndef JUEGO_H
#define JUEGO_H

#define FILAS 60
#define COLUMNAS 60

#define VENTANA_FILAS 20
#define VENTANA_COLUMNAS 20

void iniciarJuego();

int validarMovimiento(
    char* mapa,
    int columnas,
    int fila,
    int columna
);

void moverJugador(char tecla);

void cargarNivel(int nivel);

#endif