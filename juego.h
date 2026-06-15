#ifndef JUEGO_H
#define JUEGO_H

// Dimensiones de los mapas
#define FILAS 60
#define COLUMNAS 60

//Tamano de la ventana para el jugador
#define VENTANA_FILAS 20
#define VENTANA_COLUMNAS 20

// Inicia la ejecucion principal del juego
void iniciarJuego();

/*
    Valida si una posicion del mapa puede ser 
    ocupada. Retorna 1 si el movimiento es
    valido, 0 si es invalido.
*/
int validarMovimiento(
    char* mapa,
    int columnas,
    int fila,
    int columna
);

/* 
    Mueve al jugador dependiendo de la tecla 
    presionada.
*/
void moverJugador(char tecla);

//Carga el nivel segun la progresion del juego.
void cargarNivel(int nivel);

/*
    Cuenta cuantas veces aparece un caracter
    dentro del mapa.
*/
int contarCaracter(
    char* mapa,
    int totalCeldas,
    char caracter
);


/*
    Verifica si un objeto se encuentra en 
    una posicion especifica del mapa.
    Retorna 1 si esta ahi, 0 si no lo esta.
*/
int detectarObjeto(
    char* mapa,
    int columnas,
    int fila,
    int columna,
    int objeto
);

/*
    Cuenta cuantas celdas libres existen
    dentro del mapa.
*/
int contarCeldasLib(
    char* mapa,
    int totalCeldas
);

/*
    Calcula el puntaje del jugador utilizando
    las monedas, pasos y niveles completados.
*/
int calcularPuntaje(
    int monedas,
    int pasos,
    int niveles
);

#endif