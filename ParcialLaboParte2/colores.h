#ifndef COLORES_H_INCLUDED
#define COLORES_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[20];
}eColor;

#endif // COLORES_H_INCLUDED


/** \brief Se encarga de cargar la descripcion de un color segun su id
 *
 * \param eColor colores[]  Recibe el vector de tipo estructura eColor
 * \param int tam Recibe el tamaño de la cantidad de veces que compara el id recibido con el id del color en el indice correspondiente
 * \param int idColores Recibe el id del color para mostrar su descripcion
 * \param char descripcion[]  Recibe la cadena de caracteres para asignarle el valor de la descripcion del color en el indice correspondiente
 * \return Retorna 1 si la funcion se ejecuto correctamente, 0 en caso contrario
 *
 */
int cargarDescripcionColores(eColor colores[], int tam, int idColores, char descripcion[]);



/** \brief Se encarga de mostrar una lista de colores existentes
 *
 * \param eColor colores[] Recibe el vector de tipo estructura eColor
 * \param int tam  Recibe el tamaño de la cantidad de colores que se muestran
 * \return Retorna 1 si la funcion se ejecuto correctamente, 0 en caso contrario
 *
 */
int mostrarColores(eColor colores[], int tam);

/** \brief Valida si el id recibido corresponde a algun id de la variable de tipo eColor
 *
 * \param int id Recibe el id a verificar
 * \param eColor colores[] Recibe el vector de tipo estructura eColor
 * \param int tam Recibe el tamaño de la cantidad de veces a iterar en el for
 * \return Retorna 1 si el id recibido corresponde a un id de color, 0 si no corresponde a ninguno
 *
 */
int validarIdColor(int id, eColor colores[], int tam);
