#include <stdio.h>
#include <stdlib.h>
#include "mascota.h"
#include "tipos.h"
#include "colores.h"
#include "servicios.h"
#include "trabajos.h"
#include "cliente.h"
#include "validaciones.h"
#define TAM 10
#define TAM_B 5
#define TAM_C 3



int main()
{
    char salir = 'n';
    int nextId = 1000;
    int nextIdT = 1000;
    int bandera1 = 0;
    int bandera2 = 0;
    eMascota lista[TAM];
    eTrabajo listaT[TAM];
    inicializarMascotas(lista, TAM);
    inicializarTrabajos(listaT, TAM);


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

    eCliente clientes[TAM_B] =
    {
        {1000, "Pablo", 'm'},
        {1001, "Carlos", 'm'},
        {1002, "Alicia", 'f'},
        {1003, "Maria", 'f'},
        {1004, "Luis", 'm'}
    };

    //hardcodearMascotas(lista, TAM, 5, &nextId, &bandera1);

    do
    {
        switch(menu())
        {
        case 'a':
            altaMascota(lista, TAM, tipos, colores, clientes, TAM_B, &nextId);
            bandera1 = 1;
            break;
        case 'b':
            if(bandera1 == 1)
            {
                modificarMascota(lista, TAM, tipos, colores, clientes, TAM_B);
            }
            else
            {
                system("cls");
                printf("Primero debe hacer al menos un alta de mascota\n");
            }
            break;
        case 'c':
            if(bandera1 == 1)
            {
                bajaMascota(lista, TAM, tipos, colores, clientes, TAM_B, &bandera1);
            }
            else
            {
                system("cls");
                printf("Primero debe hacer al menos un alta de mascota\n");
            }
            break;
        case 'd':
            if(bandera1 == 1)
            {
                ordenarMascotas(lista, tipos, TAM);
                mostrarMascotas(lista, TAM, tipos, colores, clientes, TAM_B);
            }
            else
            {
                system("cls");
                printf("Primero debe hacer al menos un alta de mascota\n");
            }

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
            if(bandera1 == 1)
            {
                altaTrabajo(listaT, TAM, servicios, lista, tipos, colores, clientes, TAM_C, TAM_B, &nextIdT);
                bandera2 = 1;
            }
            else
            {
                system("cls");
                printf("Primero debe hacer al menos un alta de mascota\n");
            }


            break;
        case 'i':
            if(bandera2 == 1)
            {
                mostrarTrabajos(listaT, TAM, servicios, lista);
            }
            else
            {
                system("cls");
                printf("Primero debe hacer al menos un alta de trabajo\n");
            }

            break;
        case 'j':
            if(bandera1 == 1)
            {
                informesComplementarios(colores, lista, tipos, clientes, TAM, TAM_B);
            }
            else
            {
                printf("Primero debe hacer al menos un alta de mascota\n");
            }


            break;
        case 'x':
            if(confirmarSalida())
            {
                salir = 's';
            }
            break;
        default:
            printf("Opcion invalida\n");
            break;
        }
        system("pause");
    }
    while(salir == 'n');
    return 0;
}

