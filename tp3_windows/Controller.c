#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include  "parser.h"
#include "validaciones.h"
#include "Controller.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
	int retorno = 0;
	FILE* archivo;
	archivo = fopen(path ,"r");

	if(path != NULL && pArrayListPassenger != NULL && archivo != NULL)
	{
		retorno = parser_PassengerFromText(archivo, pArrayListPassenger);

		if(retorno == 1)
		{
			todoOk = 1;
		}
	}
	else
	{
		printf("ERROR. EL ARCHIVO NO EXISTE.\n");
	}

	fclose(archivo);

    return todoOk;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk = 0;

	FILE* archivo;
	archivo = fopen(path ,"rb");

	if(path != NULL && archivo != NULL && pArrayListPassenger != NULL && archivo != NULL)
	{
		parser_PassengerFromBinary(archivo, pArrayListPassenger);
		todoOk = 1;
	}
	else
	{
		printf("ERROR. EL ARCHIVO NO EXISTE.\n");
	}
	fclose(archivo);

    return todoOk;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* pPass = NULL;
	int auxIdInt;
	int auxTipoInt;
	char auxIdChar[50];
	char auxNombreChar[50];
	char auxApellidoChar[50];
	char auxPrecioChar[50];
	char auxCodigoChar[50];
	char auxTipo[10];
	char auxEstadoDeVueloChar[10];
	int auxEstado;
	int todoOk = 1;

	if(pArrayListPassenger != NULL)
	{

		printf("--------------------ALTA-----------------\n");
		auxIdInt = parser_setIdBinary("ultimoId.bin");
		sprintf(auxIdChar,"%d",auxIdInt);
		printf("Ingrese nombre: \n");
		scanf("%s",auxNombreChar);
		if(validarLetras(auxNombreChar) == 1)
		{
			printf("Ingrese apellido: \n");
			scanf("%s",auxApellidoChar);
			if(validarLetras(auxApellidoChar) == 1)
			{
				printf("Ingrese precio: \n");
				scanf("%s",auxPrecioChar);
				if(validarFloat(auxPrecioChar) == 1)
				{
					printf("Ingrese codigo: \n");
					scanf("%s",auxCodigoChar);
					printf("Ingrese tipo: \n1) para %s, 2) para %s, 3 para %s \n",ECOCLASS, EXECLASS, PRIMCLASS);
					scanf("%s",auxTipo);
					if(validarEntero(auxTipo) == 1)
					{
						auxTipoInt = atoi(auxTipo);
						switch(auxTipoInt)
						{
							case 1:
								break;
							case 2:
								break;
							case 3:
								break;
							default:
								todoOk = 0;
							break;
						}
						printf("Ingrese estado del vuelo: \n 1) Aterrizado, 2) En Horario \n");
						scanf("%s",auxEstadoDeVueloChar);
						if(validarEntero(auxEstadoDeVueloChar) == 1)
						{
							auxEstado = atoi(auxEstadoDeVueloChar);
							switch(auxEstado)
							{
								case 1:
									break;
								case 2:
									break;
								default:
									todoOk = 0;
									break;
							}
						}
					}
					else
					{
						todoOk = 0;
					}
				}
				else
				{
					todoOk = 0;
				}
			}
			else
			{
				todoOk = 0;
			}


		}
		else
		{
			todoOk = 0;
		}

		pPass = Passenger_newParametros(auxIdChar, auxNombreChar, auxTipo, auxCodigoChar, auxApellidoChar, auxPrecioChar, auxEstadoDeVueloChar);
		if(pPass != NULL && todoOk == 1)
		{
			ll_add(pArrayListPassenger, pPass);
		}
		else
		{
			printf("No hay espacio.\n");
		}

	}

	return todoOk;

}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* auxPass = NULL;
	int todoOk = 0;
	int idIngresado;
	int auxId;
	int ultimoId;
	int opcionConfirmacion;
	int opcionCampo;
	int flag = 0;
	char auxNombre[50];
	char auxApellido[50];
	char auxCodigoVuelo[50];
	int auxTipo;
	float auxPrecio;
	int retornoValidacion;

	printf("--------------------MODIFICACION-----------------\n");

	controller_ListPassenger(pArrayListPassenger);
	ultimoId = parser_GetLastId("Max_ID.bin");
	idIngresado = cargarInt("Ingrese el id que desea modificar: ", 1, ultimoId);

	for(int i = 0; i < ll_len(pArrayListPassenger); i++)
	{
			auxPass= ll_get(pArrayListPassenger, i);

			if(auxPass != NULL)
			{
				Passenger_getId(auxPass, &auxId);
				if(idIngresado == auxId)
				{
					mostrarPasajero(auxPass, auxPass->id, auxPass->nombre, auxPass->apellido, auxPass->codigoVuelo, auxPass->tipoPasajero, auxPass->estado, auxPass->precio);
					opcionConfirmacion = cargarInt("Desea modificar? \n 1.CONFIRMAR\n 2. CANCELAR\n", 1, 2);

					if(opcionConfirmacion == 1)
					{
						do {
							printf("*************************** M O D I F I C A C I O N   D E   E M P L E A D O ***************************\n");

							if(flag == 1)
							{
								printf("Campo modificado correctamente.\n");
							}

							 printf("//1. NOMBRE		//2. APELLIDO		//3. PRECIO		//4. TIPO DE PASAJERO //5. CODIGO DE VUELO 		//6. SALIR\n");
							 opcionCampo= cargarInt("Elija el campo que desea cambiar:",1,6);

							switch (opcionCampo)
							{

							 case 1:
								printf("Ingrese nombre del pasajero\n");
								fflush(stdin);
								scanf("%s", auxNombre);
								retornoValidacion = validarLetras(auxNombre);
								if(retornoValidacion == 1)
								{
									Passenger_setNombre(auxPass, auxNombre);
									todoOk=1;
								}
								else
								{
									printf("No se admiten numeros, espacios o simbolos en el nombre \n");
								}
								break;

							case 2:
								printf("Ingrese apellido del pasajero\n");
								fflush(stdin);
								scanf("%s", auxApellido);
								retornoValidacion = validarLetras(auxApellido);
								if(retornoValidacion == 1)
								{
									Passenger_setApellido(auxPass, auxApellido);
									todoOk=1;
								}
								else
								{

									printf("No se admiten numeros, espacios o simbolos en el nombre \n");
								}
								break;

							case 3:
								auxPrecio = cargarFloat("Ingrese el nuevo precio \n", 1, 999999999);
								Passenger_setPrecio(auxPass, auxPrecio);
								todoOk=1;
								break;

							case 4:
								auxTipo = cargarInt("Ingrese tipo de pasajero:\n1 - Economic class \n2- Executive Class \n 3- Primary Class ", 1, 3);
								Passenger_setTipoPasajero(auxPass, auxTipo);
								todoOk=1;
								break;

							case 5:
								printf("Ingrese codigo de vuelo\n");
								fflush(stdin);
								scanf("%s", auxCodigoVuelo);
								Passenger_setCodigoVuelo(auxPass, auxCodigoVuelo);
								todoOk=1;
								break;

						}
					}while(opcionConfirmacion != 6);
				}
						if(flag != 1)
						{
							printf("No se modifico ningun campo.");
						}
					}
				break;
				}
			}
	return todoOk;
}



/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	Passenger* auxPass = NULL;
	int todoOk = 0;
	int idIngresado;
	int opcion;
	int ultimoId;

	printf("--------------------------------BAJA--------------------------------\n");
	controller_ListPassenger(pArrayListPassenger);
	ultimoId = parser_GetLastId("ultimoId.bin");
	idIngresado = cargarInt("Ingrese el id que quiere dar de baja: ", 1, ultimoId);

	for(int i = 0; i<ll_len(pArrayListPassenger); i++)
	{
		auxPass = ll_get(pArrayListPassenger, i);

		if(auxPass != NULL)
		{
			if(idIngresado == auxPass->id)
			{
				mostrarPasajero(auxPass, auxPass->id, auxPass->nombre, auxPass->apellido, auxPass->codigoVuelo, auxPass->tipoPasajero, auxPass->estado, auxPass->precio);
				opcion = cargarInt("Confirma que desea dar de  baja?\n 1.CONFIRMAR\n 2. CANCELAR\n", 1, 2);
				if(opcion == 1)
				{
					todoOk = 1;
					ll_remove(pArrayListPassenger, i);
					Passenger_delete(auxPass);
				}
				else
				{
					printf("operacion cancelada.\n");
				}
				break;
			}
			else
			{
				printf("No se encontro vuelo con ese id \n");
			}
		}
	}
	return todoOk;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
		int todoOk = 0;
		int auxId;
		char auxNombre[55];
		char auxApellido[55];
		char auxCodigo[10];
		float auxPrecio;
		int auxTipo;
		int auxEstado;

		Passenger* pPassAux = NULL;
		if(pArrayListPassenger != NULL)
		{
			printf("      ***Pasajeros***\n\n");
			printf("------------------------------------------------\n");
			printf("ID      NOMBRE      APELLIDO        PRECIO      TIPO    	CODIGO DE VUELO			ESTADO DEL VUELO\n\n");

			for(int i = 0; i< ll_len(pArrayListPassenger); i++)
			{
				pPassAux = ll_get(pArrayListPassenger, i);

				if(Passenger_getApellido(pPassAux, auxApellido) == 1 &&
						Passenger_getId(pPassAux, &auxId) == 1 &&
						Passenger_getNombre(pPassAux, auxNombre) == 1 &&
						Passenger_getCodigoVuelo(pPassAux, auxCodigo) == 1 &&
						Passenger_getPrecio(pPassAux, &auxPrecio) == 1 &&
						Passenger_getTipoPasajero(pPassAux, &auxTipo) == 1 &&
						Passenger_getEstado(pPassAux, &auxEstado) == 1)
				{
					todoOk = 1;
					mostrarPasajero(pPassAux, auxId, auxNombre, auxApellido, auxCodigo, auxTipo, auxEstado,auxPrecio);
				}
			}
		}

		return todoOk;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int todoOk= 0;
	int opcion;

		if(pArrayListPassenger != NULL)
		{


			printf("----------------------------------------ORDENAR----------------------------------------\n");
			printf("1. Ordenar por apellido \n2. Ordenar por precio \n3. Volver\n");
			opcion = cargarInt("Ingrese 1, 2 o 3:", 1,3);
			system("cls");

			switch (opcion)
			{

				case 1:
					if(ordenarPorApellido(pArrayListPassenger) == 1)
					{
						todoOk= 1;
					}
					break;

				case 2:
					if(ordenarPorPrecio(pArrayListPassenger)== 1)
					{
						todoOk = 1;
					}
					break;

				case 3:
					break;

				case 4:
					break;
			}
		}
   return todoOk;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

