#ifndef MASCOTA_H_INCLUDED
#define MASCOTA_H_INCLUDED
#include "tipos.h"
#include "servicios.h"
#include "colores.h"
#include "cliente.h"

typedef struct
{
    int id;
    char nombre[20];
    int edad;
    char vacunado;

    int idTipo;
    int idColor;
    int idCliente;

    int isEmpty;
}eMascota;



#endif // MASCOTA_H_INCLUDED


/** \brief Despliega el menu de opciones del ABM de veterinaria y pide el ingreso de una opcion
 *
 * \return Retorna el caracter de la opcion ingresada
 *
 */
char menu();


/** \brief Le asigna el valor 1 a isEmpty y 0 al id del vector mascota en el indice i
 *
 * \param eMascota mascota[]  Recibe el vector de tipo estructura eMascota
 * \param int tam  Recibe el tamaño de iteraciones a recorrer en el for
 * \return Retorna 1 si la funcion se ejecuto correctamente, 0 en caso contrario
 *
 */
int inicializarMascotas(eMascota mascota[], int tam);


/** \brief Busca las posiciones de isEmpty en 1 del vector mascota
 *
 * \param eMascota mascota[] Recibe el vector de tipo estructura eMascota
 * \param int tam Recibe el tamaño de la cantidad de veces para iterar dentro del for
 * \return Retorna -1 si todas las posiciones de isEmpty estan en 0, caso contrario, retorna el indice del vector mascota en donde el valor de isEmpty es 1
 *
 */
int buscarLibre(eMascota mascota[],int tam);

/** \brief Ejecuta la carga de los datos de una variable de estructura eMascota
 *
 * \param eMascota lista[] Recibe la variable de tipo estructura eMascota
 * \param int tam Recibe el tamaño para pasarle por valor a la funcion buscarLibre
 * \param eTipo tipos[] Recibe el vector de tipo estructura eTipo
 * \param eColor colores[] Recibe el vector de tipo estructura eColor
* \param eCliente clientes[] Recibe el vector de tipo estructura eCliente
 * \param int tamB Recibe el tamaño para pasar como valor a las funciones mostrarColores, validarIdColores, mostrarTipos, validarIdTipo
 * \param int* pId Recibe por referencia el id de la mascota para hacerlo autoincremental
 * \return Retorna 1 si la funcion se ejecuto correctamente, 0 en caso contrario
 *
 */
int altaMascota(eMascota lista[], int tam, eTipo tipos[], eColor colores[], eCliente clientes[], int tamB, int* pId);


/** \brief Se encarga de mostrar en pantalla el valor de todas las variables de la variable de estructura eMascota
 *
 * \param eMascota mascota Recibe la variable de tipo estructura eMascota
 * \param eTipo tipos[] Recibe el vector de tipo estructura eTipo
 * \param eColor colores[] Recibe el vector de tipo estructura eColor
 * \param eCliente clientes[] Recibe el vector de tipo estructura eCliente
  * \param eCliente clientes[] Recibe el vector de tipo estructura eCliente
 * \param int tam Recibe el tamaño para pasar su valor a las funciones cargarDescripcionTipos y cargarDescripcionColores
 * \return Retorna 1 si la funcion se ejecuto correctamente, 0 en caso contrario
 *
 */
int mostrarMascota(eMascota mascota, eTipo tipos[], eColor colores[], eCliente clientes[], int tam);


/** \brief Se encarga de mostrar en pantalla todas las mascotas (si las hay) en todos los indices iterados
 *
 * \param eMascota lista[] Recibe el vector de tipo estructura eMascota
 * \param int tam Recibe el tamaño de la cantidad de veces que evalua el valor de isEmpty en un indice del vector mascota
 * \param eTipo tipos[] Recibe el vector de tipo estructura eTipo
 * \param eColor colores[] Recibe el vector de tipo estructura eColor
 * \param eCliente clientes[] Recibe el vector de tipo estructura eCliente
 * \param int tamB Recibe el tamaño para pasarle como valor a la funcion mostrarMascota
 * \return Retorna 1 si la funcion se ejecuto correctamente, 0 en caso contrario
 *
 */
int mostrarMascotas(eMascota lista[], int tam, eTipo tipos[], eColor colores[], eCliente clientes[], int tamB);

/** \brief Busca si el id recibido corresponde a un id del vector de tipo estructura eMascota
 *
 * \param eMascota lista[] Recibe el vector de tipo estructura eMascota
 * \param int tam Recibe el tamaño de la cantidad de veces que busca el id
 * \param int id Recibe el id a buscar
 * \return Retorna -1 si el id no existe, caso contrario, retorna el indice del vector mascota en donde el id es igual al recibido
 *
 */
int buscarMascotaId(eMascota lista[], int tam, int id);


/** \brief Se encarga de dar de baja a una mascota
 *
 * \param eMascota lista[] Recibe el vector de tipo estructura eMascota
 * \param int tam Recibe el tamaño de la cantidad de veces que evalua el valor de isEmpty en un indice del vector mascota, y tambien para pasarlo por valor a la funcion buscarMascotaId
 * \param eTipo tipos[] Recibe el vector de tipo estructura eTipo
 * \param eColor colores[] Recibe el vector de tipo estructura eColor
 * \param eCliente clientes[] Recibe el vector de tipo estructura eCliente
 * \param int tamB Recibe el tamaño para pasarselo por valor a la funcion mostrarMascota
 * \return Retorna 1 si la funcion se ejecuto correctamente, 0 en caso contrario
 *
 */
int bajaMascota(eMascota lista[], int tam, eTipo tipos[], eColor colores[], eCliente clientes[], int tamB, int* pBandera);

/** \brief Ordena las mascotas por tipo y nombre
 *
 * \param eMascota lista[] Recibe el vector de tipo estructura eMascota
 * \param eTipo tipo[] Recibe el vector de tipo estructura eTipo
 * \param int tam Recibe el tamaño de la cantidad de veces que se debe iterar para hacer el ordenamiento correspondiente
 * \param int* pBandera Recibe por referencia el valor de la bandera del alta para volverla 0 en caso de confirmar la baja
 * \return Retorna 1 si la funcion se ejecuto correctamente, 0 en caso contrario
 *
 */

int ordenarMascotas(eMascota lista[], eTipo tipo[], int tam);

/** \brief Permite, pidiendo el id, modificar el estado de vacunacion y el tipo de una mascota
 *
 * \param eMascota lista[] Recibe el vector de tipo estructura eMascota
 * \param int tam Recibe el tamaño de la cantidad de veces que evalua el valor de isEmpty en un indice del vector mascota, para pasarlo por valor a la funcion buscarMascotaId y para pasarlo por valor a la funcion validarTipos
 * \param eTipo tipos[] Recibe el vector de tipo estructura eTipo
 * \param eColor colores[] Recibe el vector de tipo estructura eColor
 * \param eCliente clientes[] Recibe el vector de tipo estructura eCliente
 * \return Retorna 1 si la funcion se ejecuto correctamente, 0 en caso contrario
 *
 */
int modificarMascota(eMascota lista[], int tam, eTipo tipos[], eColor colores[], eCliente clientes[], int tamB);

/** \brief Despliega el menu de opciones de modificacion
 *
 * \return Retorna el numero de opcion ingresado
 *
 */
int menuModificacion();

/** \brief Valida si el id recibido corresponde a algun id de la variable de tipo eMascota
 *
 * \param int id Recibe el id a verificar
 * \param eMascota mascota[] Recibe el vector de tipo estructura eMascota
 * \param int tam Recibe el tamaño de la cantidad de veces a iterar en el for
 * \return Retorna 1 si el id recibido corresponde a un id de mascota, 0 si no corresponde a ninguno
 *
 */
int validarIdMascota(int id, eMascota mascota[], int tam);

/** \brief Se encarga de cargar el nombre de una mascota segun su id
 *
 * \param eMascota mascotas[]  Recibe el vector de tipo estructura eMascota
 * \param int tam Recibe el tamaño de la cantidad de veces que compara el id recibido con el id de la mascota en el indice correspondiente
 * \param int idMascotas Recibe el id de la mascota para cargar su nombre
 * \param char nombre[]  Recibe la cadena de caracteres para asignarle el valor del nombre de la mascota en el indice correspondiente
 * \return Retorna 1 si la funcion se ejecuto correctamente, 0 en caso contrario
 *
 */
int cargarNombreMascotas(eMascota mascotas[], int tam, int idMascotas, char nombre[]);

/** \brief Despliega un menu de opciones de informes complementarios
 *
 * \return Retorna la opcion ingresada
 *
 */

char menuInformesComplementarios();

/** \brief Evalua la opcion ingresada de la funcion menuInformesComplementarios y ejecuta su respectivo funcionamiento
 *
 * \param eColor colores[] Recibe el vector de tipo estructura eColor
 * \param eMascota mascota[] Recibe el vector de tipo estructura eMascota
 * \param eTipo tipos[] Recibe el vector de tipo estructura eTipo
 * \param eCliente clientes[] Recibe el vector de tipo estructura eCliente
 * \param int tam Recibe el tamaño usado para la cantidad total de mascotas ingresables, y se lo utiliza para diversas iteraciones y funciones
 * \param int tamB Recibe el tamaño usado para la cantidad total de colores y tipos, y se lo utiliza para diversas iteraciones y funciones
 * \return Retorna 1 si la funcion se ejecuto correctamente, 0 en caso contrario
 *
 */

int informesComplementarios(eColor colores[], eMascota mascota[], eTipo tipos[], eCliente clientes[], int tam, int tamB);
