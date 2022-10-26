#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eTipo;

#endif // TIPOS_H_INCLUDED


/** \brief Se encarga de cargar la descripcion de un tipo segun su id
 *
 * \param eTipo tipos[] Recibe el vector de tipo estructura eTipos
 * \param int tam Recibe el tamaño de la cantidad de veces que compara el id recibido con el id del tipo en el indice correspondiente
 * \param int idTipos Recibe el id del tipo para mostrar su descripcion
 * \param char descripcion[]  Recibe la cadena de caracteres para asignarle el valor de la descripcion del tipo en el indice correspondiente
 * \return Retorna 1 si la funcion se ejecuto correctamente, 0 en caso contrario
 *
 */
int cargarDescripcionTipos(eTipo tipos[], int tam, int idTipos, char descripcion[]);


/** \brief Se encarga de mostrar una lista de tipos existentes
 *
 * \param eTipo tipos[] Recibe el vector de tipo estructura eTipos
 * \param int tam  Recibe el tamaño de la cantidad de tipos que se muestran
 * \return Retorna 1 si la funcion se ejecuto correctamente, 0 en caso contrario
 *
 */
int mostrarTipos(eTipo tipos[], int tam);


/** \brief Valida si el id recibido corresponde a algun id de la variable de tipo eTipo
 *
 * \param int id Recibe el id a verificar
 * \param eTipo tipos[] Recibe el vector de tipo estructura eTipos
 * \param int tam Recibe el tamaño de la cantidad de veces a iterar en el for
 * \return Retorna 1 si el id recibido corresponde a un id de tipo, 0 si no corresponde a ninguno
 *
 */
int validarIdTipo(int id, eTipo tipos[], int tam);
