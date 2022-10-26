#ifndef DATAWAREHOUSE_H_INCLUDED
#define DATAWAREHOUSE_H_INCLUDED
#include "mascota.h"


#endif // DATAWAREHOUSE_H_INCLUDED

/** \brief Hardcodea los datos de una estructura mascota
 *
 * \param eMascota lista[]
 * \param int tam Recibe un tamaño para validar que sea mayor a cero
 * \param int cant Recibe la cantidad de mascotas a hardcodear
 * \param int* pId Recibe por referencia el id para volverlo autoincremental
 * \param int* bandera Recibe por referencia la variable bandera para convertirla en 1
 * \return Retorna la cantidad de mascotas que fueron hardcodeadas, -1 si no se pudo ejecutar la funcion
 *
 */

int hardcodearMascotas(eMascota lista[], int tam, int cant, int* pId, int* bandera);
