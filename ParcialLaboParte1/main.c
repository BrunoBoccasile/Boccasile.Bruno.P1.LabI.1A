#include <stdio.h>
#include <stdlib.h>
#include "mascota.h"
#include "tipos.h"
#include "colores.h"
#include "servicios.h"
#include "trabajos.h"
#define TAM 10
#define TAM_B 5
#define TAM_C 3



int main()
{
    char salir = 'n';
    int nextId = 1000;
    int nextIdT = 1000;
    eMascota lista[TAM];
    eTrabajo listaT[TAM];
    inicializarMascotas(lista, TAM);


    eTipo tipos[TAM_B] =
    {
        {1000, "Ave"},
        {1001, "Perro"},
        {1002, "Roedor"},
        {1003, "Gato"},
        {1004, "Pez"}
    };

    eColor colores[TAM_B] =
    {
        {1000, "Negro"},
        {1001, "Blanco"},
        {1002, "Rojo"},
        {1003, "Gris"},
        {1004, "Azul"}

    };

    eServicio servicios[TAM_C] =
    {
        {20000, "Corte", 450},
        {20001, "Desparasitado", 800},
        {20002, "Castrado", 600}
    };

    hardcodearMascotas(lista, TAM, 5, &nextId);

    do
    {
        switch(menu())
        {
        case 'a':
            altaMascota(lista, TAM, tipos, colores, TAM_B, &nextId);
            break;
        case 'b':
            modificarMascota(lista, TAM, tipos, colores, TAM_B);
            break;
        case 'c':
            bajaMascota(lista, TAM, tipos, colores, TAM_B);
            break;
        case 'd':
            ordenarMascotas(lista, tipos, TAM);
            mostrarMascotas(lista, TAM, tipos, colores, TAM_B);
            break;
        case 'e':
            mostrarTipos(tipos, TAM_B);
            break;
        case 'f':
            mostrarColores(colores, TAM_B);
            break;
        case 'g':
            mostrarServicios(servicios, TAM_C);
            break;
        case 'h':
            altaTrabajo(listaT, TAM, servicios, lista, tipos, colores, TAM_C, TAM_B, &nextIdT);
            break;
        case 'i':
            printf("Listar trabajo");
            break;
        case 'x':
            salir = 'n';
            printf("Confirma salida?: ");
            fflush(stdin);
            scanf("%c", &salir);

            break;
        default:
            printf("Opcion invalida");
            break;
        }
        system("pause");
    }
    while(salir == 'n');
    return 0;
}

