#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
    int option = 0;
    setbuf(stdout,NULL);
    LinkedList* listaPasajeros = ll_newLinkedList();
    do{
    	option = menu();
        switch(option)
        {
            case 1:
                if(controller_loadFromText("data.csv",listaPasajeros) == 1)
                {
                	printf("Se realizo con exito \n");
                }
                else
                {
                	printf("Fallo la carga desde el .csv \n");
                }
                break;
            case 2 :
            	if(controller_loadFromBinary("data.bin" , listaPasajeros) == 1)
            	{
                	printf("Se realizo con exito \n");
				}
				else
				{
                	printf("Fallo la carga del .bin \n");
				}
            	break;
            case 3:
            	if(controller_addPassenger(listaPasajeros) == 1)
            	{
                	printf("Se realizo con exito \n");
            	}
            	else
            	{
                	printf("No se pudo dar de alta \n");
            	}
            	break;

            case 4:
            	if(controller_editPassenger(listaPasajeros) == 1)
            	{
                	printf("Se realizo con exito \n");
            	}
            	else
            	{
                	printf("No se pudo modificar \n");
            	}
            	break;

            case 5:
            	if(controller_removePassenger(listaPasajeros) == 1)
            	{
                	printf("Se realizo con exito \n");
            	}
            	else
				{
					printf("No se pudo dar la baja \n");
				}
            	break;

            case 6:
            	if(controller_ListPassenger(listaPasajeros) != 1)
            	{
            		printf("No se pudo mostrar \n");
            	}

            	break;

            case 7:
            	if(controller_sortPassenger(listaPasajeros) == 1)
            	{
            		printf("Se ordeno con exito\n");
            	}
            	else
            	{
            		printf("No se pudo ordenar\n");
            	}
            	break;

            case 8:

            	break;

            case 9:

            	break;
            case 10:

            	break;

        }
    }while(option != 10);
    return 0;
}

