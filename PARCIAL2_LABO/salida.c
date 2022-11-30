#include <stdio.h>
#include <stdlib.h>

int menu()
{
    int opcion;
    system("cls");
    printf("MOVIES\n\n");
    printf("1- Cargar archivo\n");
    printf("2- Imprimir lista\n");
    printf("3- Asignar tiempos\n");
    printf("4- Filtrar por tipo\n");
    printf("5- Mostrar duraciones\n");
    printf("6- Guardar peliculas\n");
    printf("7- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
