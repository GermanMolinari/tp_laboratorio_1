/*
 * ArrayPassenger.h
 *
 *  Created on: 28 abr 2022
 *      Author: German Molinari
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

typedef struct{
	int id;
	char name [51];
	char lastname[51];
	float price;
	char flycode [10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}Passenger;

int menu();
int initPassengers(Passenger list[], int tam);
int recuestData(int* id, Passenger* pPassenger);
int findFree (Passenger list [], int tam);
int addPassenger (Passenger list [], int tam, int id, char name[], char lastName [], float price, int statusFlight, char flyCode[], int typePassenger);
void printPassenger(Passenger pasajero);
int printPassengers(Passenger list[], int tam);
int findPassengerById(Passenger list[], int tam, int id);
int modifyPassenger(Passenger list[], int tam);
int removePassenger(Passenger list[], int tam);
int menuInformes(Passenger list[], int tam);
int sortPassenger(Passenger* list, int tam, int order);
int sortPassengersByCode(Passenger* list, int tam, int order);
float promedyPrice(Passenger list[], int tam);
int showPromedy(Passenger list[], int tam);
int cargarPasajeros(Passenger list [], int * pId);







#endif /* ARRAYPASSENGER_H_ */
