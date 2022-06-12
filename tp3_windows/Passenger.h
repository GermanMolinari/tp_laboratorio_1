/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_
#include "LinkedList.h"

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[4];
	int estado;

}Passenger;

#define PRIMCLASS "FristClass"
#define EXECLASS "ExecutiveClass"
#define ECOCLASS "EconomyClass"

#define ATERRIZADO 1
#define HORARIO 2

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajeroStr, char* codigoVuelo, char* apellidoStr, char* precioStr, char* estadoDeVueloStr);
void Passenger_delete();

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_getEstado (Passenger* this,int* estado);

int convertirTipo(char* tipoPasajero);
int mostrarPasajero(Passenger * this, int auxId, char* auxNombre, char* auxApellido, char* auxCodigo, int auxTipo, int auxEstado, float auxPrecio);
int compararPorApellido(void* unPasajero,void* otroPasajero);
int ordenarPorApellido(LinkedList* this);
int compararPorPrecio (void* unPasajero,void* otroPasajero);
int ordenarPorPrecio (LinkedList* this);


int menu();

#endif /* PASSENGER_H_ */
