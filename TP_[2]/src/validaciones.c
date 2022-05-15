/*
 * validaciones.c
 *
 *  Created on: 7 abr 2022
 *      Author: bolsi uwu
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"


int getInt(int * pNumeroIngresado,char * mensaje,char * mensajeError,
		int maximo, int minimo, int maximoDeReintentos)
{

	int auxNumeroIngresado;
	int retorno;
	retorno = -1;

	if(pNumeroIngresado != NULL && maximo >= minimo && maximoDeReintentos>= 0)
	{
		do
		{
			printf("%s", mensaje);
			scanf("%d", &auxNumeroIngresado);
			maximoDeReintentos--;

			if(auxNumeroIngresado >= minimo && auxNumeroIngresado <= maximo)
			{
						*pNumeroIngresado = auxNumeroIngresado;
						retorno = 0;
						break;
			}else
			{
				printf("%s", mensajeError);
			}

		}while(maximoDeReintentos > 0);
	}

	return retorno;
}

int getFloat(float * pNumeroIngresado,char * mensaje,char * mensajeError,
		float maximo, float minimo, int maximoDeReintentos){

	float auxNumeroIngresado;
	int retorno;
	retorno = -1;

	if(pNumeroIngresado != NULL && maximo >= minimo && maximoDeReintentos>= 0){
		do{
			printf("%s", mensaje);
			scanf("%f", &auxNumeroIngresado);
			maximoDeReintentos--;

			if(auxNumeroIngresado >= minimo && auxNumeroIngresado <= maximo){
						*pNumeroIngresado = auxNumeroIngresado;
						retorno = 0;
						break;
			}else{
				printf("%s", mensajeError);
			}

		}while(maximoDeReintentos > 0);
	}

	return retorno;
}

int ordenarArrayEnteros(int pArray[], int len) {

	int retorno = -1;
	int i;
	int aux;
	int estaOrdenado;

	if (pArray != NULL && len > 0) {

		do {
			estaOrdenado = 1;
			len--;
			for (i = 0; i < len; i++) {

				if (pArray[i] > pArray[i + 1]) {

					aux = pArray[i];
					pArray[i] = pArray[i + 1];
					pArray[i + 1] = aux;
					estaOrdenado = 0;
				}
			}
		}while(estaOrdenado == 0);

	}

	return retorno;
}

int swapearEnteros (int* a, int* b)
{
	int retorno = -1;
	int aux;

	if(a != NULL && b != NULL)
	{
		aux = *b;
		*b = *a;
		*a = aux;
		retorno = 0;
	}

	return retorno;
}

int swapearFloat (float* a, float* b)
{
	int retorno = -1;
	float aux;

	if(a != NULL && b != NULL)
	{
		aux = *b;
		*b = *a;
		*a = aux;
		retorno = 0;
	}

	return retorno;
}


int swapearChar (char* a, char* b)
{
	int retorno = -1;
	char aux;

	if(a != NULL && b != NULL)
	{
		aux = *b;
		*b = *a;
		*a = aux;
		retorno = 0;
	}

	return retorno;
}

int validarLetras(char cadena[])
{
	int retorno=1;
	int i=0;
	if(cadena!=NULL)
	{
		while(cadena[i]!='\0')
		{
			if(cadena[i]<'A' || (cadena[i]>'Z' && cadena[i]<'a') || cadena[i]>'z')
			{
				retorno=0;
				break;
			}
			i++;
		}
	}

	return retorno;
}

int validarEntero(char numero[])
{
    int i=0;
    int len;
    int retorno=1;

    len=strlen(numero);
    while(i<len && retorno==1)
    {
        if(isdigit(numero[i])!=0)
        {
            i++;
        }
        else
        {
            retorno=0;
        }
    }
    return retorno;
}

int cargarInt(char message[],int min, int max)
{
    char option[50];
    int retornoValidacion=0;
    int enteroValido;
    int flag=0;
    do
    {
		if (flag==1)
		{
			printf("ERROR.");
		}
		printf("%s", message);
		fflush(stdin);
		scanf("%[^\n]", option);
		retornoValidacion = validarEntero(option);

		while(retornoValidacion != 1)
		{
			printf("ERROR. '%s' no es una opcion, %s",option, message);
			fflush(stdin);
			scanf("%[^\n]", option);
			retornoValidacion = validarEntero(option);
		}

		enteroValido = atoi(option);
		flag=1;

    }while(enteroValido < min || enteroValido > max);

    return enteroValido;
}

int validarFloat(char number[])
{
    int i=0;
    int retorno=1;
    int len;
    int flag=1;

    len=strlen(number);

    while(i<len && retorno==0)
    {
        if(isdigit(number[i])!=0)
        {
            i++;
        }else if(flag && (number[i])=='.')
        {
            i++;
            flag=0;
        }else
        {
        	retorno=0;
        }

    }
    return retorno;
}

float cargarFloat(char mensaje[], int min, int max)
{
    char opcion[50];
    int retornoValidacion=0;
    float floatValido;
    int flag=0;
    do
    {
		if(flag == 1)
		{
			printf("ERROR.");
		}
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", opcion);

		retornoValidacion = validarFloat(opcion);

		while(retornoValidacion!=1)
		{
			printf("ERROR. '%s' no es un numero valido, %s",opcion, mensaje);
			 fflush(stdin);
			scanf("%[^\n]", opcion);
			retornoValidacion=validarFloat(opcion);
		}
		floatValido= atof(opcion);
		flag=1;
    }while(floatValido < min || floatValido > max);

    return floatValido;
}


