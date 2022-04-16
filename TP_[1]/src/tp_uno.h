/*
 * tp_uno.h
 *
 *  Created on: 13 abr 2022
 *      Author: bolsi uwu
 */

#ifndef TP_UNO_H_
#define TP_UNO_H_

/** \brief Imprime el menu y devuelve la opcion ingresada
 *
 *  \param float* puntero a kilometros
 *  \param float* mensaje mensaje previo a pedir el dato
 *  \param float* mensajeError muestra el mensaje si se ingresa mal el dato
 *  
 *  \return retorna la opcion ingresada x el usuario
 *
 */
int menu(float* kilometros, float* precioAerolineas, float* precioLatam);


/** \brief calcula el descuento, debe ser ingresado con 0.cantidaDeDescuento
 *
 *  \param float precio
 *  \param float descuento a aplicar
 *  
 *  \return retorna el precio con el descuento aplicado
 *
 */

float calcularDescuento (float precio, float descuento);

/** \brief calcula el interes, debe ser ingresado con 0.cantidaDeInteres
 *
 *  \param float precio
 *  \param float interes a aplicar
 *  
 *  \return retorna el precio con el interes aplicado
 *
 */
float calcularInteres (float precio, float interes);

/** \brief divide dos flotantes
 *
 *  \param float divisor
 *  \param float dividendo
 *  \param float* escribe el resultado en la direccion de memoria
 *  \return retorna el 0 o 1 dependiendo si el divisor es != 0
 *
 */

int dividirFlotantes (float divisor, float dividendo, float* pResultado);

/** \brief Multiplica dos flotantes
 *
 *  \param float operando a
 *  \param float operando b
 *  
 *  \return retorna el resultado de la multiplicacion
 *
 */
float multiplicarFlotantes(float a, float b);

/** \brief resta dos flotantes y devuelve el resultado siempre positivo

 *  \param float operando a
 *  \param float operando b
 *  
 *  \return retorna el resultado positivo
 *
 */
float restarFlotantes (float a, float b);

/** \brief Realiza todos los calculos correspondientes y los muestra en pantalla
 *
 *  \param float Km
 *  \param float precio uno
 *  \param precio dos
 *
 */
void cargarForzadamente (float kmIngresados, float precioAerolineas, float precioLatam);

#endif /* TP_UNO_H_ */
