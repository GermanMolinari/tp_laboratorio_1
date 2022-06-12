/*
 * validaciones.h
 *
 *  Created on: 7 abr 2022
 *      Author: bolsi uwu
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

/** \brief Pide un entero y lo devuelve validado en un rango, muestra un mensaje antes de pedirlo
 *
 *  \param int * pNumeroIngresado donde escribe el entero si es valido
 *  \param char* mensaje mensaje previo a pedir el dato
 *  \param char* mensajeError muestra el mensaje si se ingresa mal el dato
 *  \param int maximo el maximo aceptado para validar
 *  \param int minimo el minimo aceptado para validar
 *  \param int maximoDeReintentos el numero maximo de reintentos para ingresar un entero valido
 *  \return retorna si 1 si pudo hacerlo con exito
 *
 */
int getInt(int * pNumeroIngresado,char * mensaje,char * mensajeError,int maximo, int minimo, int maximoDeReintentos);

/** \brief Pide un entero y lo devuelve validado en un rango, muestra un mensaje antes de pedirlo
 *
 *  \param float * pNumeroIngresado donde escribe el entero si es valido
 *  \param char* mensaje mensaje previo a pedir el dato
 *  \param char* mensajeError muestra el mensaje si se ingresa mal el dato
 *  \param float maximo el maximo aceptado para validar
 *  \param float minimo el minimo aceptado para validar
 *  \param float maximoDeReintentos el numero maximo de reintentos para ingresar un entero valido
 *  \return retorna si 1 si pudo hacerlo con exito
 *
 */
int getFloat(float * pNumeroIngresado,char * mensaje,char * mensajeError, float maximo, float minimo, int maximoDeReintentos);

/** \brief swapea dos enteros
 *
 *  \param int * puntero a primer entero
 *  \param int * puntero a segundo entero
 *  \return retorna si 1 si pudo hacerlo con exito
 *
 */
int swapearEnteros (int* a, int* b);

/** \brief swapea dos enteros
 *
 *  \param float * puntero a primer flotante
 *  \param float * puntero a segundo flotante
 *  \return retorna si 1 si pudo hacerlo con exito
 *
 */
int swapearFloat (float* a, float* b);

/** \brief swapea dos chars
 *
 *  \param char * puntero a primer char
 *  \param char * puntero a segundo char
 *  \return retorna si 1 si pudo hacerlo con exito
 *
 */
int swapearChar (char* a, char* b);

/** \brief valida que la cadena solamente tenga letras
 *  \param  cadena[] cadena que se va a validar
 *  \return retorna si 1 si pudo hacerlo con exito
 *
 */
int validarLetras(char cadena[]);


/** \brief devuelve un entero valido
 *  \param  minimo
 *  \param maximo
 *	\return el numero validado
 */
int cargarInt(char message[],int min, int max);

/** \brief valida que se cargue un entero
 *  \param  cadena
 *	\return el numero validado
 */
int validarEntero(char numero[]);



/**
 * \brief valida que se cargue un float
 * @param mensaje
 * @param min
 * @param max
 * @return validacion
 */float cargarFloat(char mensaje[], int min, int max);

/**
 * \brief valida que sea una cadena alfanumerica
 * @param cadena
 * @return validacion
 */int validarAlfaNum(char cadena[]);

int cargarIntEnCadena(char message[], int min, int max,char cadena[]);
int validarFloat(char number[]);

#endif /* VALIDACIONES_H_ */
