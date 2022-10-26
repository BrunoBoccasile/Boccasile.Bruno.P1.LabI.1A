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
    eFecha fecha[10];

    int isEmpty;
}eTrabajo;



#endif // TRABAJOS_H_INCLUDED


/** \brief Le asigna el valor 1 a isEmpty y 0 al id del vector trabajos en el indice i
 *
 * \param eTrabajo trabajos[]  Recibe el vector de tipo estructura eTrabajo
 * \param int tam  Recibe el tamaño de iteraciones a recorrer en el for
 * \return Retorna 1 si la funcion se ejecuto correctamente, 0 en caso contrario
 *
 */
int inicializarTrabajos(eTrabajo trabajos[], int tam);

/** \brief Busca las posiciones de isEmpty en 1 del vector trabajo
 *
 * \param eTrabajo trabajo[] Recibe el vector de tipo estructura eTrabajo
 * \param int tam Recibe el tamaño de la cantidad de veces para iterar dentro del for
 * \return Retorna -1 si todas las posiciones de isEmpty estan en 0, caso contrario, retorna el indice del vector trabajo en donde el valor de isEmpty es 1
 *
 */
int buscarLibreTrabajo(eTrabajo trabajo[],int tam);

/** \brief Ejecuta la carga de los datos de una variable de estructura eTrabajo
 *
 * \param eTrabajo lista[] Recibe la variable de tipo estructura eTrabajo
 * \param int tam Recibe el tamaño para pasarle por valor a la funcion buscarLibreTrabajo
 * \param eServicio servicios[] Recibe el vector de tipo estructura eServicio
 * \param eTipo tipos[] Recibe el vector de tipo estructura eTipo
 * \param eColor colores[] Recibe el vector de tipo estructura eColor
* \param eCliente clientes[] Recibe el vector de tipo estructura eCliente
 * \param int tamC Recibe un tamaño para pasarle por valor a la funcion mostrarServicios y validarIdServicio
 * \param int tamB Recibe un tamaño para pasarle por valor a la funcion mostrarMascotas
 * \param int* pId Recibe por referencia el id de trabajo para hacerlo autoincremental
 * \return Retorna 1 si la funcion se ejecuto correctamente, 0 en caso contrario
 *
 */
int altaTrabajo(eTrabajo lista[], int tam, eServicio servicios[], eMascota mascotas[], eTipo tipos[], eColor colores[], eCliente clientes[], int tamC, int tamB, int* pId);

/** \brief Se encarga de mostrar en pantalla el valor de todas las variables de la variable de estructura eTrabajo
 *
 * \param eTrabajo trabajo Recibe la variable de tipo estructura eTrabajo
 * \param eMascota mascotas[] Recibe el vector de tipo estructura eMascota
 * \param eServicio servicios[] Recibe el vector de tipo estructura eServicio
 * \param int tam Recibe el tamaño para pasar su valor a las funciones cargarDescripcionMascotas y cargarDescripcionServicios
 * \return Retorna 1 si la funcion se ejecuto correctamente, 0 en caso contrario
 *
 */
int mostrarTrabajo(eTrabajo trabajo, eMascota mascotas[], eServicio servicios[], int tam);

/** \brief Se encarga de mostrar en pantalla todos los trabajos (si los hay) en todos los indices iterados
 *
 * \param eTrabajo trabajo[] Recibe el vector de tipo estructura eTrabajo
 * \param int tam Recibe el tamaño de la cantidad de veces que evalua el valor de isEmpty en un indice del vector trabajo
 * \param eServicio servicios[] Recibe el vector de tipo estructura eServicio
 * \param eMascota mascotas[] Recibe el vector de tipo estructura eMascota
 * \return Retorna 1 si la funcion se ejecuto correctamente, 0 en caso contrario
 *
 */
int mostrarTrabajos(eTrabajo trabajo[], int tam, eServicio servicios[], eMascota mascotas[]);
