#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED



#endif // VALIDACIONES_H_INCLUDED

/** \brief Valida si un string esta compuesto por la cantidad de caracteres indicada segun el minimo y el maximo
 *
 * \param char string[] Recibe el string a validar
 * \param int min Recibe la cantidad minima de caracteres
 * \param int max Recibe la cantidad maxima de caracteres
 * \param char mensaje[] Recibe el mensaje que se muestra en caso de haber recibido un string no valido
 * \return Retorna 1 si la funcion se ejecuto correctamente, 0 en caso contrario
 *
 */
int validarString(char string[], int min, int max, char mensaje[]);

/** \brief Valida si en un string aparece un numero
 *
 * \param char string[] Recibe string a validar
 * \return Retorna 1 si el string contiene un numero, 0 en caso contrario
 *
 */
int validarNumeroString(char string[]);

/** \brief Valida si una respuesta ingresada es 's' o 'n'
 *
 * \param char* respuesta Recibe por referencia la respuesta ingresada
 *
 */
void validarSiNo(char* respuesta);

/** \brief Valida si un numero entero esta dentro del rango definido por el maximo y el minimo
 *
 * \param int* numero Recibe por referencia la variable del numero ingesado
 * \param int max Recibe el numero maximo aceptado
 * \param int min Recibe el numero minimo aceptado
 *
 */
void validarNumeroMaxMin(int* numero, int max, int min);


/** \brief Confirma si el usuario desea o no salir
 *
 * \return Retorna 1 si la respuesta es 's', 0 si es 'n'
 *
 */
int confirmarSalida();

/** \brief Valida si un numero flotante esta dentro del rango definido por el maximo y el minimo
 *
 * \param float* numero Recibe por referencia la variable del numero ingesado
 * \param int max Recibe el numero maximo aceptado
 * \param int min Recibe el numero minimo aceptado
 *
 * \return Retorna 1 si la funcion se ejecuto correctamente, 0 en caso contrario
 *
 */
int validarFlotanteMaxMin(float* numero, int max, int min);

/** \brief  Verifica si la cadena ingresada es numerica
 *
 * \param int *pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */
int getInt(int *pResultado);

/** \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadenaun máximo de 'longitud - 1' caracteres.
 *
 * \param char *cadena Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param int longitud  Define el tamaño de cadena
 * \return
 *
 */
int myGets(char *cadena, int longitud);

/** \brief Valida si una cadena esta compuesta solo por numeros
 *
 * \param char *cadena Recibe cadena a validar
 * \return Retorna 1 en caso de que el texto este compuesto solo por numeros, 0 en caso contrario
 *
 */
int esNumerica(char *cadena);
