#ifndef MASCOTA_H_INCLUDED
#define MASCOTA_H_INCLUDED
#include "tipos.h"
#include "servicios.h"
#include "colores.h"

typedef struct
{
    int id;
    char nombre[20];
    int edad;
    char vacunado;

    int idTipo;
    int idColor;

    int isEmpty;
}eMascota;






#endif // MASCOTA_H_INCLUDED

char menu();

int inicializarMascotas(eMascota mascota[], int tam);

int altaMascota(eMascota lista[], int tam, eTipo tipos[], eColor colores[], int tamB, int* pId);

int mostrarMascota(eMascota mascota, eTipo tipos[], eColor colores[], int tam);

int mostrarMascotas(eMascota lista[], int tam, eTipo tipos[], eColor colores[], int tamB);

int buscarMascotaId(eMascota lista[], int tam, int id);

int bajaMascota(eMascota lista[], int tam, eTipo tipos[], eColor colores[], int tamB);

int ordenarMascotas(eMascota lista[], eTipo tipo[], int tam);

int modificarMascota(eMascota lista[], int tam, eTipo tipos[], eTipo colores[], int tamB);

int menuModificacion();

int validarIdMascota(int id, eMascota mascota[], int tam);
