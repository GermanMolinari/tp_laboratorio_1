/*
 * tp_uno.c
 *
 *  Created on: 14 abr 2022
 *      Author: bolsi uwu
 */
#include <stdio.h>
#include <stdlib.h>

int menu(float* kilometros, float* precioAerolineas, float* precioLatam)
{
	int opcion;

	printf("1- Ingresar Kilomentros: ( km = %.2f) \n", *kilometros);
	printf("2- Ingresar Precio de Vuelos: (Aerolineas = %.2f, Latam = %.2f) \n",*precioAerolineas, *precioLatam);
	printf("3- Calcular todos los costos \n");
	printf("4- Informar resultados \n");
	printf("5- Carga forzada de datos \n");
	printf("6- Salir \n");
	scanf("%d", &opcion);

	return opcion;
}

float calcularDescuento (float precio, float descuento)
{

	precio = precio - (precio * descuento);

	return precio;
}

float calcularInteres (float precio, float interes)
{
	precio = precio + (precio * interes);

	return precio;
}

int dividirFlotantes (float dividendo, float divisor, float* pResultado)
{
	int todoOk = -1;

	if (divisor != 0)
	{
		*pResultado  = dividendo / divisor;
		todoOk=0;
	}

	return todoOk;
}

float multiplicarFlotantes(float a, float b)
{
	return a * b;
}

float restarFlotantes (float a, float b)
{
	float resultado;
	resultado = a - b;

	if(resultado < 0)
	{
		resultado = resultado * (-1);
	}

	return resultado;
}

void cargarForzadamente (float kmIngresados, float precioAerolineas, float precioLatam)
{
	float precioUnitarioAerolineas;
	float precioUnitarioLatam;
	float precioDebitoAerolineas;
	float precioDebitoLatam;
	float precioCreditoAerolineas;
	float precioCreditoLatam;
	float diferenciaDePrecio;
	float precioBtcAerolineas;
	float precioBtcLatam;

	if (dividirFlotantes(precioAerolineas, kmIngresados,&precioUnitarioAerolineas) == -1)
	{
		printf("Error el divisor no puede ser 0 \n");
	}

	if(dividirFlotantes(precioLatam, kmIngresados,&precioUnitarioLatam) == -1)
	{
		printf("Error el divisor no puede ser 0 \n");
	}

	precioDebitoAerolineas = calcularDescuento(precioAerolineas, 0.10);
	precioDebitoLatam = calcularDescuento(precioLatam, 0.10);

	precioCreditoAerolineas = calcularInteres(precioAerolineas, 0.25);
	precioCreditoLatam = calcularInteres(precioLatam, 0.25);

	dividirFlotantes(precioAerolineas, 4606954.55,&precioBtcAerolineas);
	dividirFlotantes(precioLatam, 4606954.55,&precioBtcLatam);

	diferenciaDePrecio = restarFlotantes(precioAerolineas, precioLatam);


	printf("Informar Resultados \n\n"

							"Precio Aerolineas %.2f:\n"
							"a) Precio con tarjeta de débito: %.2f \n"
							"b) Precio con tarjeta de crédito: %.2f\n"
							"c) Precio pagando con bitcoin : %.8f\n"
							"d) Precio unitario: %.2f\n\n\n"
							"Precio Latam: %.2f\n"
							"a) Precio con tarjeta de débito: %.2f\n"
							"b) Precio con tarjeta de crédito: %.2f\n"
							"c) Precio pagando con bitcoin : %.8f\n"
							"d) Precio unitario: %.2f\n\n"
							"La diferencia de precio es : %.2f\n", precioAerolineas, precioDebitoAerolineas, precioCreditoAerolineas,
							precioBtcAerolineas, precioUnitarioAerolineas ,
							precioLatam, precioDebitoLatam, precioCreditoLatam,
							precioBtcLatam,precioUnitarioLatam,diferenciaDePrecio);

}
