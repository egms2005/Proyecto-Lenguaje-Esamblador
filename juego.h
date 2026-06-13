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

int contarCaracter(
    char* mapa,
    int totalCeldas,
    char caracter
);

int detectarObjeto(
    char* mapa,
    int columnas,
    int fila,
    int columna,
    int objeto
);

int contarCeldasLib(
    char* mapa,
    int totalCeldas
);

int calcularPuntaje(
    int monedas,
    int pasos,
    int niveles
);

#endif