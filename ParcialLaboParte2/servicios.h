#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    int precio;
}eServicio;

#endif // SERVICIOS_H_INCLUDED

/** \brief Se encarga de cargar la descripcion de un servicio segun su id
 *
 * \param eServicio servicios[]  Recibe el vector de tipo estructura eServicio
 * \param int tam Recibe el tamaño de la cantidad de veces que compara el id recibido con el id del servicio en el indice correspondiente
 * \param int idServicios Recibe el id del servicio para mostrar su descripcion
 * \param char descripcion[]  Recibe la cadena de caracteres para asignarle el valor de la descripcion del servicio en el indice correspondiente
 *\param int* precio Recibe por referencia el precio para asignarle el valor del precio del servicio en el indice correspondiente
 * \return Retorna 1 si la funcion se ejecuto correctamente, 0 en caso contrario
 *
 */
int cargarDescripcionPrecioServicios(eServicio servicios[], int tam, int idServicios, char descripcion[], int* precio);


/** \brief Se encarga de mostrar una lista de servicios existentes
 *
 * \param eServicio servicios[] Recibe el vector de tipo estructura eServicio
 * \param int tam  Recibe el tamaño de la cantidad de servicios que se muestran
 * \return Retorna 1 si la funcion se ejecuto correctamente, 0 en caso contrario
 *
 */
int mostrarServicios(eServicio servicios[], int tam);


/** \brief Valida si el id recibido corresponde a algun id de la variable de tipo eServicio
 *
 * \param int id Recibe el id a verificar
 * \param eServicio servicios[] Recibe el vector de tipo estructura eServicio
 * \param int tam Recibe el tamaño de la cantidad de veces a iterar en el for
 * \return Retorna 1 si el id recibido corresponde a un id de servicio, 0 si no corresponde a ninguno
 *
 */
int validarIdServicio(int id, eServicio servicios[], int tam);
