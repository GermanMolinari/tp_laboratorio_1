/*
 ============================================================================
 Name        : TP_2_MolinariGerman.c
 Author      : German Molinari
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"

#define TAM 2000

int main(void) {
	setbuf(stdout, NULL);
	int id = 1000;
	char salir = 'n';
	int flag = 0;
	Passenger list [TAM];
	Passenger auxPassenger;
	initPassengers(list, TAM);


	do {
		switch (menu())
		{
			case 1:
				if (recuestData(&id, &auxPassenger) == 1)
				{
					 addPassenger(list, TAM, id, auxPassenger.name, auxPassenger.lastname, auxPassenger.price, auxPassenger.statusFlight, auxPassenger.flycode, auxPassenger.typePassenger);
					 flag = 1;
				}
				else
				{
					printf("La carga de datos fallo \n");
					system("pause");
				}
				break;

			case 2:
				if (flag == 1)
				{
					if(modifyPassenger(list, TAM) == 1)
					{
						printf("Modificacion exitosa! \n");
					}
					else
					{
						printf("No se pudo modificar \n");
					}
				}
				else
				{
					printf("Primero debe cargar vuelos \n");
				}
				break;

			case 3:
				if (flag == 1)
				{
					if(removePassenger(list, TAM) == 1)
					{
						printf("Baja exitosa! \n");
					}
					else
					{
						printf("No se pudo dar la baja. \n");

					}
				}
				else
				{
					printf("Primero debe cargar vuelos \n");
				}
				break;

			case 4:
				if (flag == 1)
				{
					if(menuInformes(list, TAM) == 1)
					{
						printf("Informes completados!");
					}
					else
					{
						printf("No se pudo informar. \n");
					}
				}
				else
				{
					printf("Primero debe cargar vuelos \n");
				}
				break;

			case 5:
				if(cargarPasajeros(list, &id)==1)
				{
					printf("Se cargaron 10 pasajeros!");
				}
				flag = 1;
				break;
			case 6:
				salir = 's';
				break;
		}
	} while(salir != 's');

	return 0;
}

