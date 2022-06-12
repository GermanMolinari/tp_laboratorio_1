#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* auxPass = NULL;
	int todoOk = 0;
	int retorno = 0;
	char id[30];
	char nombre[50];
	char apellido[50];
	char codigoVuelo[10];
	char precio[100];
	char tipoPasajero[3];
	char estadoDeVuelo[3];

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		retorno = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n" ,id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoDeVuelo);

		if(retorno == 7)
		{
			while(!feof(pFile))
			{
				fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoDeVuelo);
				auxPass = Passenger_newParametros(id,nombre,tipoPasajero,codigoVuelo,apellido,precio,estadoDeVuelo);
				ll_add(pArrayListPassenger, auxPass);
				todoOk=1;
			}
		}
		else
		{
			printf("fallo en retorno parser linea 42 \n");
		}
	}
	fclose(pFile);
	return todoOk;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{


	int todoOk = 0;
	int retorno = 0;
	Passenger* auxPass = NULL;
	if(pFile!= NULL && pArrayListPassenger != NULL)
	{
		while(!feof(pFile))
		{
			auxPass = Passenger_new(auxPass);
			if(auxPass != NULL)
			{
				retorno = fread(auxPass, sizeof(Passenger), 1,pFile);
				if(retorno == 1)
				{
					ll_add(pArrayListPassenger, auxPass);
					todoOk = 1;
				}
			}
		}
	}
    return todoOk;
}

int parser_setIdBinary(char* pathId)
{

		FILE * pArchivo = NULL;
		int ultimoId = 0;
		int flag = 0;
		pArchivo = fopen(pathId, "rb");
		if(pArchivo != NULL)
		{
			fread(&ultimoId,sizeof(int),1, pArchivo);
			ultimoId++;
			flag = 1;
		}
		fclose(pArchivo);

		if(flag == 1)
		{
			pArchivo= fopen(pathId, "wb");
			if(pArchivo != NULL)
			{
				fwrite(&ultimoId,sizeof(int),1,pArchivo);
			}
			fclose(pArchivo);
		}

		return ultimoId;
}

int parser_GetLastId(char* pathId)
{

	FILE * pArchivo = NULL;
	int ultimoId = 0;

	pArchivo = fopen(pathId, "rb");

	if(pArchivo != NULL)
	{
		fread(&ultimoId,sizeof(int),1, pArchivo);
	}

	fclose(pArchivo);

	return ultimoId;
}
