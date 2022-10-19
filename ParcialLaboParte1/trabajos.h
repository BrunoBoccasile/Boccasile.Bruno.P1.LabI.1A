#ifndef TRABAJOS_H_INCLUDED
#define TRABAJOS_H_INCLUDED
#include "mascota.h"
#include "servicios.h"
#include "tipos.h"
#include "colores.h"
typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int id;
    int idMascota;
    int idServicio;
    eFecha fecha;

    int isEmpty;
}eTrabajo;



#endif // TRABAJOS_H_INCLUDED

int buscarLibreTrabajo(eTrabajo trabajo[],int tam);

int altaTrabajo(eTrabajo lista[], int tam, eServicio servicios[], eMascota mascotas[], eTipo tipos[], eColor colores[], int tamC, int tamB, int* pId);
