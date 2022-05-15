/*
 * ArrayPassenger.c
 *
 *  Created on: 28 abr 2022
 *      Author: German Molinari
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "validaciones.h"


int menu()
{
    int opcion;

    system("cls");
    printf("****Vuelos**** \n\n");
    printf("1) ALTA\n");
    printf("2) MODIFICAR\n");
    printf("3) BAJA\n");
    printf("4) INFORMAR\n");
    printf("5) CARGA FORZADA\n");
    printf("6) SALIR\n");
    opcion = cargarInt("Ingrese una opcion: \n", 1, 6);

    return opcion;
}

int initPassengers(Passenger list[], int tam)
{
    int todoOk=0;

    if(list != NULL && tam > 0)
    {
        for(int i= 0; i < tam; i++)
        {
            list[i].isEmpty = 1;
        }
        todoOk = 1 ;
    }

    return todoOk;
}

int recuestData(int* id, Passenger* pPassenger)
{
    Passenger data;
    char auxCadena[51];
    int todoOk = 1;
    int retornoValidacion;

    if(id != NULL && pPassenger != NULL)
    {
		system("cls");
		printf("Ingrese nombre del pasajero\n");
		fflush(stdin);
		scanf("%s", auxCadena);
		retornoValidacion = validarLetras(auxCadena);
		if(retornoValidacion == 1)
		{
			strncpy(data.name,auxCadena,sizeof(data.name));
		}
		else
		{

			printf("No se admiten numeros, espacios o simbolos en el nombre \n");
			todoOk = 0;
		}

		printf("Ingrese apellido del pasajero\n");
		fflush(stdin);
		scanf("%s", auxCadena);
		retornoValidacion = validarLetras(auxCadena);

		if(validarLetras(auxCadena) == 1)
			{
				strncpy(data.lastname,auxCadena,sizeof(data.lastname));
			}
		else
			{
				printf("No se admiten numeros, espacios o simbolos en el apellido\n");
				todoOk = 0;

			}


		data.price = cargarFloat("Ingrese el precio del vuelo\n", 100, 9999999);


		printf("Ingrese el codigo de vuelo\n");
		fflush(stdin);
		scanf("%s", auxCadena);
		strncpy(data.flycode,auxCadena, sizeof(data.flycode));
		data.typePassenger = cargarInt("Ingrese tipo de pasajero\n", 1, 3);
		data.statusFlight = cargarInt("Ingrese estado del vuelo\n 1. Activo\n 2. Inactivo\n", 1, 2);

		if(todoOk == 1)
		{
			*pPassenger = data;
			data.id = *id;
			(*id)++;
		}
    }
    return todoOk;
}

int findFree (Passenger list [], int tam)
{
	int posicion=-1;

	if(list != NULL && tam>0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(list[i].isEmpty == 1)
			{
				posicion = i;
				break;
			}
		}
	}
   return posicion;
}


int addPassenger (Passenger list [], int tam, int id, char name[], char lastName [], float price, int statusFlight, char flyCode[], int typePassenger)
{
    int todoOk = 0;
    int posicion;

    if(list != NULL && name != NULL && lastName!= NULL && flyCode != NULL && tam>0)
    {
        system("cls");
        printf("***Alta de vuelos***\n");
        posicion = findFree(list, tam);

        if(posicion != -1)
        {
            list[posicion].id = id;
            strcpy(list[posicion].name, name);
            strcpy(list[posicion].lastname, lastName);
            list[posicion].price = price;
            list[posicion].statusFlight = statusFlight;
            strcpy(list[posicion].flycode, flyCode);
            list[posicion].typePassenger = typePassenger;
            list[posicion].isEmpty = 0;
            todoOk=1;
        }
        else
        {
            printf("No hay espacio para mas vuelos.\n");
            system("pause");
        }
    }

    return todoOk;
}

void printPassenger(Passenger pasajero)
{

    printf("%04d      %s      %s           $%5.2f      %d			%d\n", pasajero.id, pasajero.name, pasajero.lastname, pasajero.price, pasajero.typePassenger, pasajero.statusFlight);
}

int printPassengers(Passenger list[], int tam)
{
    int todoOk = 0;
    int flag = 0;

    if(list != NULL && tam > 0)
    {
        system("cls");
        printf("      ***Pasajeros***\n\n");
        printf("------------------------------------------------\n");
        printf("ID      NOMBRE      APELLIDO        PRECIO      TIPO 		ESTADO DEL VUELO\n\n");

        for(int i=0; i<tam; i++)
        {
            if(list[i].isEmpty == 0)
            {
                printPassenger(list[i]);
                flag = 1;
            }
        }

        if(flag == 0)
        {
            system("cls");
            printf("No hay empleados registrados\n");
        }
        todoOk=1;
    }
    return todoOk;
}

int findPassengerById(Passenger list[], int tam, int id)
{
    int posicion = -1;

    if(list != NULL && tam > 0)
    {
        for(int i = 0; i < tam-1; i++)
        {
            if(id == list[i].id && list[i].isEmpty == 0)
            {
                posicion = i;
            }
        }
    }
    return posicion;
}

int modifyPassenger(Passenger list[], int tam)
{
    int todoOk = 0;
    char confirm;
    int idIngresado;
    int posicion;
    char auxCadena[51];
    int opcion;
    int retornoValidacion;

    printPassengers(list, tam);
    idIngresado = cargarInt("Ingrese id del pasajero que desea modificar", 0, 9999);
    posicion = findPassengerById(list, tam, idIngresado);

    if(list != NULL && tam > 0 && posicion != -1)
    {
        printPassenger(list[posicion]);
        printf("Desea modificar al empleado? s/n \n");
        fflush(stdin);
        scanf("%c", &confirm);

        while(confirm != 's' && confirm != 'n')
        {
            printf("Error.. ingrese solo s/n \n");
            scanf("%c", &confirm);
        }
        if (confirm == 's')
        {
        	do{
        	            printf("//1. NOMBRE		//2. APELLIDO		//3. PRECIO		//4. TIPO DE PASAJERO //5. ESTADO DE VUELO 		//6. SALIR\n");
        	            opcion= cargarInt("Elija el campo que desea cambiar:",1,6);
        	            switch(opcion)
        	            {
        	                case 1:
        	                	printf("Ingrese nombre del pasajero\n");
								fflush(stdin);
								scanf("%s", auxCadena);
								retornoValidacion = validarLetras(auxCadena);
								if(retornoValidacion == 1)
								{
									strncpy(list[posicion].name,auxCadena,sizeof(list[posicion].name));
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
								scanf("%s", auxCadena);
								retornoValidacion = validarLetras(auxCadena);
								if(retornoValidacion == 1)
								{
									strncpy(list[posicion].lastname,auxCadena,sizeof(list[posicion].lastname));
									todoOk=1;
								}
								else
								{

									printf("No se admiten numeros, espacios o simbolos en el nombre \n");
								}
								break;

        	                case 3:
        	                list[posicion].price = cargarFloat("Ingrese precio", 100, 9999999);
        	            	todoOk=1;
        	                	break;

        	                case 4:
        	                	list[posicion].typePassenger = cargarInt("Ingrese tipo de pasajero", 1, 3);
        	                	todoOk=1;
        	                	break;

        	                case 5:
        	                	list[posicion].statusFlight =  cargarInt("Ingrese estado del vuelo", 1, 3);
        	                	todoOk=1;
        	                	break;

        	            }
        	        }while(opcion!=6);
        }
        else
        {
        	printf("No se encontro pasajero con ese Id");
        }
    }
    return todoOk;
}

int removePassenger(Passenger list[], int tam)
{
    int todoOk = 0;
    char confirm;
    int idIngresado;

    printPassengers(list, tam);
	idIngresado = cargarInt("Ingrese id del pasajero que desea remover", 0, 9999);

    if(list != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(list[i].id == idIngresado && list[i].isEmpty == 0)
            {
                system("cls");
                printPassenger(list[i]);
                printf("\n Desea eliminar pasajero? s/n");
                fflush(stdin);
                scanf("%c", &confirm);

                while(confirm != 's' && confirm != 'n')
                {
                    printf("Error.. ingrese solo s/n \n");
                    scanf("%c", &confirm);
                }

                if(confirm == 's')
                {
                    list[i].isEmpty = 1;
                    todoOk = 1 ;
                    break;
                }
            }
        }
    }
    return todoOk;
}


int menuInformes(Passenger list[], int tam)
{
	int opcion;
	int todoOk = 0;
	int orden;

	if(list != NULL && tam > 0)
	{
		system("cls");
		printf("1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero\n."
				"2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n"
				"3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’\n"
				"4. Volver al menu \n\n");
		opcion = cargarInt("Seleccione una opcion", 1, 4);

		switch(opcion)
		{
			case 1:
				orden=cargarInt("Ingrese el orden en el que deses mostrar \n1. Ascendente\n2. Descendente \n", 1, 2);
				if (sortPassenger(list, tam, orden) == 1)
				{
					todoOk = 1;
					printPassengers(list, tam);
				}

				break;

			case 2:
				if(showPromedy(list, tam) == 1)
				{
					todoOk = 1;
				}

				break;

			case 3:
				orden=cargarInt("Ingrese el orden en el que deses mostrar \n1. Ascendente\n2. Descendente \n", 1, 2);
				if(sortPassengersByCode(list, tam, orden) == 1)
				{
					todoOk = 1;
					printPassengers(list, tam);
				}

				break;

			case 4:
				break;
		}

	}

	return todoOk;
}

int sortPassenger(Passenger* list, int tam, int order)
{
	int todoOk=0;
	Passenger aux;

	if(list != NULL && tam > 0)
	{
	    if(order==1)
	    {
	        for(int i=0; i<tam - 1; i++)
	        {
	            for(int j=i+1; j<tam; j++)
	            {
	                if(list[i].isEmpty == 0)
	                {
	                    if(strcmp(list[i].lastname,list[j].lastname)>0) //descendente?? revisar condicion
	                    {
							todoOk=1;
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
	                    }
						if(strcmp(list[i].lastname,list[j].lastname)==0)
						{
							if(list[i].typePassenger > list[j].typePassenger)
							{
								todoOk = 1;
								aux = list[i];
								list[i] = list[j];
								list[j] = aux;
							}
						}
	                }
	            }
	         }
	    }
	    if(order==2)
	    {
	                for(int i=0; i<tam -1 ; i++)
	                {
	            for(int j=i+1; j<tam; j++)
				{
					if(list[i].isEmpty == 0)
					{
						if(strcmp(list[i].lastname,list[j].lastname)<0)
						{
							todoOk=1;
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
						if(strcmp(list[i].lastname,list[j].lastname)==0)
						{
							if(list[i].typePassenger < list[j].typePassenger)
							{
								todoOk=1;
								aux = list[i];
								list[i] = list[j];
								list[j] = aux;
							}
						}
					}
				}
	         }
	    }
	}
	    return todoOk;
}



int sortPassengersByCode(Passenger* list, int tam, int order)
{
	int todoOk=0;
	Passenger aux;

	if(list != NULL && tam > 0)
	{
	    if(order==1)
	    {
	        for(int i=0; i<tam - 1; i++)
	        {
	            for(int j=i+1; j<tam; j++)
	            {
	                if(list[i].isEmpty==0 && list[i].statusFlight == 1)
	                {
	                    if(strcmp(list[i].flycode,list[j].flycode)>0) //descendente?? revisar condicion
	                    {
							todoOk=1;
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
	                    }
	                }
	            }
	         }
	    }
	    if(order==2)
	    {
	                for(int i=0; i<tam -1 ; i++)
	                {
	            for(int j=i+1; j<tam; j++)
				{
					if(list[i].isEmpty == 0 && list[i].statusFlight == 1)
					{
						if(strcmp(list[i].flycode,list[j].flycode)<0)
						{
							todoOk=1;
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
					}
				}
	         }
	    }
	}
	return todoOk;
}



float promedyPrice(Passenger list[], int tam)
{
   float resultado;
   int contador = 0;
   float total = 0;

   if(list != NULL && tam > 0)
   {
       for(int i = 0; i < tam; i++)
       {
           if(list[i].isEmpty == 0)
           {
               total += list[i].price;
               contador++;
           }
        resultado = (float) total/contador;
       }
       printf("El precio total de todos los pasajes es %2f", total);
       system("pause");
   }
    return resultado;
}

int showPromedy(Passenger list[], int tam)
{
	int contador = 0;
	int todoOk = 0;
	float promedioPrecios;

	if(list != NULL && tam>0)
	{
		promedioPrecios = promedyPrice(list, tam);
		for(int i = 0; i < tam; i++)
		{
			if (list[i].price > promedioPrecios)
			{
				contador++;
				todoOk = 1;
			}
		}
	}
	printf("La cantidad de pasajes que superan el promedio son %d \n", contador);
	system("pause");
	return todoOk;
}

int cargarPasajeros(Passenger list [], int * pId)
{
	int todoOk = 0;
	char nombres[10][20] =
	{
	    "Juan",
	    "Pedro",
	    "Sofia",
	    "Miguel",
	    "Valentina",
	    "Camila",
	    "Andrea",
	    "Luis",
	    "Diego",
	    "Analia"
	};

	char codigosDeVuelo[10][20] =
		{
		    "ASD 123",
		    "QWE 567",
		    "GSD 795",
		    "HKO 059",
		    "DJY 994",
		    "HSJ 000",
		    "GSJ 233",
		    "GSI 219",
		    "HLD 502",
		    "SHL 934"
		};

	char apellidos[10][20] =
		{
		    "Gomez",
		    "Molina",
		    "Guitierrez",
		    "Hernandez",
		    "Gomez",
		    "Colis",
		    "Andres",
		    "Lugones",
		    "Diaz",
		    "Gimenez"
		};

	int tiposDePasajeros[10] = {2,1,3,3,3,2,1,2,1,2};

	float precios[10] = {2151.65,15656.74,1684.68,1488.80,4861.64,6871.69,6881.75,7771.74,7861.73,7881.82};

	int estadosDeVuelos[10] = {1,1,2,2,2,2,1,1,1,2};

	//int ids[10] = {1,2,3,4,5,6,7,8,9,10};

	if (list != NULL && pId != NULL)
	    {
	        for (int i = 0; i < 10;  i++)
	        {
	            list[i].id = *pId;
	            (*pId)++;
	            strcpy(list[i].name, nombres[i]);
	            strcpy(list[i].lastname, apellidos[i]);
	            strcpy(list[i].flycode, codigosDeVuelo[i]);
	            list[i].price = precios[i];
	            list[i].statusFlight = estadosDeVuelos[i];
	            list[i].typePassenger = tiposDePasajeros[i];
	            list[i].isEmpty = 0;
	            todoOk = 1;
	        }
	    }
		return todoOk;;
}

