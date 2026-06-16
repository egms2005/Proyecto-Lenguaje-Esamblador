BitQuest

Compilación del juego:
Para compilar el juego en una computadora con el sistema operativo Windows se necesita:
•	NASM de 64 bits.
•	GCC de 64 bits.
Compilación manual:
1.	Abrir una terminal en la carpeta del proyecto y ejecutar: “nasm -f win64 rutinas.asm -o rutinas.obj”, Este comando traduce el código ensamblador contenido en rutinas.asm y genera el archivo objeto rutinas.obj.

2.	Una vez generado el archivo objeto, ejecutar: “gcc main.c juego.c rutinas.obj -o BitQuest.exe”, este comando compila los archivos escritos en C y los enlaza con las funciones implementadas en NASM, generando el ejecutable BitQuest.exe.

3.	Para iniciar el juego, ejecutar: “BitQuest.exe” o simplemente hacer doble clic sobre el archivo generado.

Compilación automática mediante archivo bat:
Para facilitar la compilación del proyecto se creó un archivo llamado “build.bat”, el cual automatiza todo el proceso. Para utilizarlo se necesita hacer doble clic sobre “build.bat”, esperar a que termine el proceso de compilación y después el juego se ejecutará automáticamente.
