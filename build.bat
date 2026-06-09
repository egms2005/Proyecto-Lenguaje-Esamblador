@echo off

nasm -f win64 rutinas.asm -o rutinas.obj

gcc main.c juego.c -o BitQuest.exe rutinas.obj

pause