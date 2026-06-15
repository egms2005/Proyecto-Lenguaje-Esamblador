@echo off

echo Compilando archivo NASM...
nasm -f win64 rutinas.asm -o rutinas.obj

if errorlevel 1 (
    echo Error al compilar rutinas.asm
    pause
    exit /b
)

echo Compilando proyecto...
gcc main.c juego.c rutinas.obj -o BitQuest.exe

if errorlevel 1 (
    echo Error al generar juego.exe
    pause
    exit /b
)

echo.
echo Ejecutando juego...
BitQuest.exe

pause