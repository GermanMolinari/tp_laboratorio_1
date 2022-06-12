/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */


#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Passenger.h"
#include "validaciones.h"


int menu()
{
    int opcion;

    system("cls");
    printf("Menu:\n\n"
     "1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
     "2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n"
     "3. Alta de pasajero\n"
     "4. Modificar datos de pasajero\n"
     "5. Baja de pasajero\n"
     "6. Listar pasajeros\n"
     "7. Ordenar pasajeros\n"
     "8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
     "9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n"
    "10. Salir\n");
    opcion = cargarInt("Ingrese una opcion: \n", 1, 10);

    return opcion;
}

Passenger* Passenger_new()
{
	Passenger* espacioNuevoPasajero;

	espacioNuevoPasajero = (Passenger*) malloc(sizeof(Passenger));

	if(espacioNuevoPasajero != NULL)
	{
		Passenger_setApellido(espacioNuevoPasajero, " ");
		Passenger_setCodigoVuelo(espacioNuevoPasajero, " ");
		Passenger_setId(espacioNuevoPasajero, 0);
		Passenger_setNombre(espacioNuevoPasajero, " ");
		Passenger_setPrecio(espacioNuevoPasajero, 0);
		Passenger_setTipoPasajero(espacioNuevoPasajero, 0);
	}

	return espacioNuevoPasajero;
}

void Passenger_delete(Passenger* this)
{
	if(this!= NULL)
	{
		free(this);
		this = NULL;
	}

}

int Passenger_setId(Passenger* this,int id)
{
	int todoOk = 0;

	if(this != NULL && id > 0)
	{
		this->id = id;
		todoOk = 1;
	}

	return todoOk;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int todoOk = 0;
	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int todoOk = 0;
	if(this != NULL && apellido != NULL)
	{
		strcpy(this->apellido, apellido);
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int todoOk = 0;
	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(this->codigoVuelo, codigoVuelo);
		todoOk = 1;
	}
	return todoOk;
}


int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int todoOk = 0;
	if(this != NULL && tipoPasajero > 0)
	{
		this->tipoPasajero= tipoPasajero;
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_setEstado(Passenger* this, int estado)
{
	int todoOk = 0;
	if(this != NULL && estado > 0)
	{
		this->estado= estado;
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int todoOk = 0;
	if(this != NULL && precio > 0)
	{
		this->precio= precio;
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_getId(Passenger* this,int* id)
{
	int todoOk = 0;
	if(this != NULL)
	{
		*id = this->id;
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int todoOk = 0;
	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int todoOk = 0;
	if(this != NULL && apellido != NULL)
	{
		strcpy(apellido, this->apellido);
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int todoOk = 0;
	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo, this->codigoVuelo);
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int todoOk = 0;
	if(this != NULL)
	{
		*tipoPasajero = this->tipoPasajero;
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_getEstado (Passenger* this,int* estado)
{
	int todoOk = 0;
	if(this != NULL)
	{
		*estado = this->estado;
		todoOk=1;
	}
	return todoOk;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int todoOk = 0;
	if(this != NULL)
	{
		*precio = this->precio;
		todoOk = 1;
	}
	return todoOk;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajeroStr, char* codigoVuelo, char* apellidoStr, char* precioStr, char* estadoDeVueloStr)
{
	Passenger* espacioNuevoPasajero;
	espacioNuevoPasajero = Passenger_new();
	int tipoPasajeroInt;
	int idInt;
	int estadoVueloInt = 0;
	float precioFloat;
	int validacionNombre = 0;
	int validacionApellido = 0;

	idInt = validarEntero(idStr);
	estadoVueloInt = validarEntero(idStr);
	tipoPasajeroInt = convertirTipo(tipoPasajeroStr);
	validacionNombre = validarLetras(nombreStr);
	validacionApellido = validarLetras(apellidoStr);

	if(estadoDeVueloStr != NULL && estadoVueloInt != 0 && idStr != NULL && tipoPasajeroInt != 0 &&
		nombreStr != NULL && espacioNuevoPasajero != NULL && tipoPasajeroStr != NULL &&
		idInt == 1 && validacionApellido == 1 && validacionNombre == 1)
	{
		idInt = atoi(idStr);
		estadoVueloInt = atoi(estadoDeVueloStr);
		Passenger_setNombre(espacioNuevoPasajero, nombreStr);
		Passenger_setApellido(espacioNuevoPasajero, apellidoStr);
		Passenger_setTipoPasajero(espacioNuevoPasajero, tipoPasajeroInt);
		Passenger_setId(espacioNuevoPasajero, idInt);
		precioFloat = atof(precioStr);
		Passenger_setPrecio(espacioNuevoPasajero, precioFloat);
		Passenger_setCodigoVuelo(espacioNuevoPasajero, codigoVuelo);

	}
	return espacioNuevoPasajero;
}

int convertirTipo(char* tipoPasajero)
{
	int retorno = 0;

	if(tipoPasajero != NULL)
	{
		if(strcmp(tipoPasajero, ECOCLASS) == 0)
		{
			retorno = 1;
		}
		else if (strcmp(tipoPasajero, EXECLASS) == 0)
		{
			retorno = 2;
		}
		if(strcmp(tipoPasajero, PRIMCLASS) == 0)
		{
			retorno = 3;
		}
	}

	return retorno;
}

int mostrarPasajero(Passenger * this, int auxId, char* auxNombre, char* auxApellido, char* auxCodigo, int auxTipo, int auxEstado, float auxPrecio)
{
	int todoOk = 0;

	if(this != NULL)
	{
	    printf("%04d      %s      %s           $%5.2f      %d		 %s		%d\n", auxId, auxNombre, auxApellido, auxPrecio, auxTipo, auxCodigo, auxEstado);
		todoOk = 1;
	}
	return todoOk;
}

int ordenarPorApellido(LinkedList* this)
{

	int criterio;
	int todoOk = 0;

	printf("Como desea ordenar? :\n1.Ascendentemente (A-Z)\n2.Descendentemente(Z-A)\n");
	criterio = cargarInt("Ingrese 1 o 2", 1, 2);

	printf("\n Ordenando por apellido... \n");

	if(ll_sort(this, compararPorApellido, criterio) == 0)
	{
		todoOk = 1;
	}

	return todoOk;
}

int compararPorApellido(void* unPasajero,void* otroPasajero)
{

	int  todoOk = -1;
	char auxApellidoPasajero[50];
	char auxOtroApellidoPasajero[50];

	if(unPasajero != NULL && otroPasajero != NULL)
	{
		Passenger_getNombre(unPasajero, auxApellidoPasajero);
		Passenger_getNombre(otroPasajero, auxOtroApellidoPasajero);

		todoOk = strcmp(auxApellidoPasajero, auxOtroApellidoPasajero);
	}

	return todoOk;
}

int ordenarPorPrecio (LinkedList* this)
{

	int opcion;
	int retorno =-1;

	printf("Ordenar por precio: \n1.Descendente \n2 .Ascendente \n");
	opcion = cargarInt("Ingrese 1 o 2 :", 1, 2);
	printf("\n Ordenando por precio... \n");

	if(ll_sort(this, compararPorPrecio, opcion) ==0)
	{
		retorno = 0;
	}

	return retorno;

}

int compararPorPrecio (void* unPasajero,void* otroPasajero)
{

	int  todoOk = -1;
	float auxPrimerSalario;
	float auxSegundoSalario;
	if(unPasajero != NULL && otroPasajero != NULL)
	{
		Passenger_getPrecio(unPasajero, &auxPrimerSalario);
		Passenger_getPrecio(otroPasajero, &auxSegundoSalario);



		if(auxPrimerSalario > auxSegundoSalario)
		{
			todoOk= 1;
		}
		else
		{
			if(auxPrimerSalario < auxSegundoSalario)
			{
				todoOk = -1;
			}
		}
	}

	return todoOk;
}
