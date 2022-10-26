#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabajos.h"
#include "servicios.h"
#include "validaciones.h"

int inicializarTrabajos(eTrabajo trabajos[], int tam)
{
    int todoOk = 0;

    if(trabajos != NULL && tam > 0)
    {
        for(int i=0 ; i<tam ; i++)
        {
            trabajos[i].isEmpty = 1;
            trabajos[i].id = 0;
        }
        todoOk = 1;
    }


    return todoOk;
}

int buscarLibreTrabajo(eTrabajo trabajo[],int tam)
{
    int indice=-1;

    for(int i=0 ; i<tam ; i++)
    {
        if(trabajo[i].isEmpty)
        {
            indice = i;
            break;
        }
    }

    return indice;
}


int altaTrabajo(eTrabajo lista[], int tam, eServicio servicios[], eMascota mascotas[], eTipo tipos[], eColor colores[], eCliente clientes[], int tamC, int tamB, int* pId)
{
    int todoOk = 0;
    int indice;
    int i = 0;
    eTrabajo auxTrabajo;

    if(lista != NULL & tam > 0)
    {
        system("cls");
        printf("Alta Trabajo\n");
        indice = buscarLibreTrabajo(lista, tam);
        if(indice == -1)
        {
            printf("No hay lugar\n");
        }
        else
        {

            auxTrabajo.id = *pId;
            (*pId)++;

            mostrarMascotas(mascotas, tam, tipos, colores, clientes, tamB);

            printf("Ingrese id de la mascota: ");
            scanf("%d", &auxTrabajo.idMascota);


            while(validarIdMascota(auxTrabajo.idMascota, mascotas, tam) == 0 || auxTrabajo.idMascota == 0)
            {
                printf("Ingrese un id de mascota valido: ");
                fflush(stdin);
                scanf("%d", &auxTrabajo.idMascota);
            }

            mostrarServicios(servicios, tamC);

            printf("Ingrese id del servicio: ");
            scanf("%d", &auxTrabajo.idServicio);

            while(validarIdServicio(auxTrabajo.idServicio, servicios, tamC) == 0)
            {
                printf("Ingrese un id de servicio valido: ");
                fflush(stdin);
                scanf("%d", &auxTrabajo.idServicio);
            }


            printf("\nIngrese fecha DD/MM/AAAA: ");
            scanf("%d/%d/%d", &auxTrabajo.fecha->dia, &auxTrabajo.fecha->mes, &auxTrabajo.fecha->anio);
            while(!validarFecha(auxTrabajo.fecha->dia, auxTrabajo.fecha->mes, auxTrabajo.fecha->anio, 2022))
            {
                printf("\nError, ingrese una fecha valida DD/MM/AAAA: ");
                scanf("%d/%d/%d", &auxTrabajo.fecha->dia, &auxTrabajo.fecha->mes, &auxTrabajo.fecha->anio);
            }


            auxTrabajo.isEmpty = 0;

            lista[indice] = auxTrabajo;
        }




        todoOk = 1;
    }
    return todoOk;
}


int mostrarTrabajo(eTrabajo trabajo, eMascota mascotas[], eServicio servicios[], int tam)
{
    char nombreMascota[20];
    char descServicio[20];
    int precioServicio;



    if(cargarDescripcionPrecioServicios(servicios, tam, trabajo.idServicio, descServicio, &precioServicio) == 1 && cargarNombreMascotas(mascotas, tam, trabajo.idMascota, nombreMascota)==1)
    {
        printf("%-4d|%02d/%02d/%4d|%-20s|$%-4d     |%-10s|%-4d\n",
               trabajo.id,
               trabajo.fecha->dia, trabajo.fecha->mes, trabajo.fecha->anio,
               descServicio,
               precioServicio,
               nombreMascota,
               trabajo.idMascota
              );
    }


}

int mostrarTrabajos(eTrabajo trabajo[], int tam, eServicio servicios[], eMascota mascotas[])
{

    int todoOk = 0;
    int bandera = 0;
    if(trabajo != NULL && tam > 0)
    {
        system("cls");
        printf("              Lista de trabajos\n\n");
        printf(" Id |  Fecha   |      Servicio      |  Precio  | Mascota  | Id mascota\n");
        printf("----|----------|--------------------|----------|----------|------------\n");
        for(int i=0 ; i<tam ; i++)
        {
            if(trabajo[i].isEmpty == 0)
            {

                mostrarTrabajo(trabajo[i], mascotas, servicios, tam);
                bandera = 1;
            }

        }
        printf("----|----------|--------------------|----------|----------|------------\n");
        if(bandera == 0)
        {
            printf("No hay Trabajos para mostrar\n");
        }
        todoOk = 1;
    }
    return todoOk;
}
