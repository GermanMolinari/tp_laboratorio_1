

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "validaciones.h"
#include "tp_uno.h"


int main(void)
{
	setbuf(stdout,NULL);

	float kmIngresados = 0;
	float precioAerolineas = 0;
	float precioLatam = 0;
	char salir;
	char confirma;
	int validacionCasoUno;
	int validacionCasoDos;
	int flagKilometros = 0;
	int flagCalculos = 0;
	char confirmacionSubMenu;
	float precioDebitoAerolineas;
	float precioDebitoLatam;
	float precioCreditoAerolineas;
	float precioCreditoLatam;
	float precioBtcAerolineas;
	float precioBtcLatam;
	float precioUnitarioAerolineas;
	float precioUnitarioLatam;
	float diferenciaDePrecio;


	do
	{

		switch (menu(&kmIngresados, &precioAerolineas, &precioLatam))
		{
			case 1:
					validacionCasoUno = getFloat(&kmIngresados, "Ingrese la cantidad de kilometors \n", "Error, ingrese una cantidad valida (entre 100 y 99999) \n", 99999, 100, 3);
					if(validacionCasoUno == 0)
					{
						flagKilometros = 1;
						printf("Kilometros cargados correctamente \n");
					}
					else
					{
						printf("Error al ingresar datos, no se pudo cargar los kilometros \n");
						system("pause");
					}
				break;

			case 2:
					system("cls");
					printf("------Ingresar precios------ \n \n");
					printf("a) Ingresar precio de Aerolineas \n");
					printf("b) Ingresar precio de Latam \n");
					fflush(stdin);
					scanf("%c", &confirmacionSubMenu);
					confirmacionSubMenu = toupper(confirmacionSubMenu);
					if(confirmacionSubMenu == 'A')
					{
						validacionCasoDos = getFloat(&precioAerolineas, "Ingresar precio de Aerolineas Argentinas \n", "Error, ingrese un precio mayor a 1000 y menor a 9999999" ,9999999,1000,3);
						if(validacionCasoDos == 0)
						{
							printf("Precio de Aerolineas Argentinas cargado correctamente \n");
						}
						else
						{
							printf("Error... No se pudo cargar el precio \n");
							system("pause");
						}

					}
					else if (confirmacionSubMenu == 'B')
					{
						validacionCasoDos = getFloat(&precioLatam, "Ingresar precio de Latam \n", "Error, ingrese un precio mayor a 1000 y menor a 9999999" ,9999999,1000,3);
						if(validacionCasoDos == 0)
							{
								printf("Precio de Latam cargado correctamente \n");
							}
							else
							{
								printf("Error... No se pudo cargar el precio \n");
								system("pause");
								system("cls");

							}

					}
					else
					{
						printf("Error... la opcion seleccionada no es valida \n");
						system("pause");
					}

				break;

			case 3:
				if(flagKilometros == 1 && precioAerolineas >= 20 && precioLatam >= 20)
				{
					printf("Calcular todos los costos: \n"
							"a) Tarjeta de débito (descuento 10 porciento)  \n"
							"b) Tarjeta de crédito (interés 25 porciento ) \n"
							"c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos) \n"
							"d) Mostrar precio por km (precio unitario) \n"
							"e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas) \n");
					system("pause");
					dividirFlotantes(precioAerolineas, kmIngresados,&precioUnitarioAerolineas);
					dividirFlotantes(precioLatam, kmIngresados,&precioUnitarioLatam);

					precioDebitoAerolineas = calcularDescuento(precioAerolineas, 0.10);
					precioDebitoLatam = calcularDescuento(precioLatam, 0.10);

					precioCreditoAerolineas = calcularInteres(precioAerolineas, 0.25);
					precioCreditoLatam = calcularInteres(precioLatam, 0.25);

					dividirFlotantes(precioAerolineas, 4606954.55,&precioBtcAerolineas);
					dividirFlotantes(precioLatam, 4606954.55,&precioBtcLatam);

					diferenciaDePrecio = restarFlotantes(precioAerolineas, precioLatam);

					flagCalculos = 1;

					system ("cls");
					printf("Costos calculados con exito! \n");
					system("pause");
				}
				else
				{
					printf("Primero ingrese la cantidad de kiilometros y el precio de los vuelos \n");
				}

				break;

			case 4 :
					if(flagCalculos == 1)
					{

						printf("Informar Resultados \n\n"

													"Precio Aerolineas %.2f:\n"
													"a) Precio con tarjeta de débito: %.2f \n"
													"b) Precio con tarjeta de crédito: %.2f\n"
													"c) Precio pagando con bitcoin : %.2f\n"
													"d) Precio unitario: %.8f\n\n\n"
													"Precio Latam: %.2f\n"
													"a) Precio con tarjeta de débito: %.2f\n"
													"b) Precio con tarjeta de crédito: %.2f\n"
													"c) Precio pagando con bitcoin : %.8f\n"
													"d) Precio unitario: %.2f\n\n"
													"La diferencia de precio es : %.2f\n", precioAerolineas, precioDebitoAerolineas, precioCreditoAerolineas,
													precioBtcAerolineas, precioUnitarioAerolineas ,
													precioLatam, precioDebitoLatam, precioCreditoLatam,
													precioBtcLatam,precioUnitarioLatam,diferenciaDePrecio);
								system("pause");

					}
					else
					{
						system("cls");
						printf("Error, primero debe calcular");
						system("pause");
					}
					break;
			case 5:
					cargarForzadamente(7090, 162965, 159339);
					system("pause");
				break;

			case 6:

				printf("Precione 's' para confirmar la salida\n");
				fflush(stdin);
				scanf("%c", &confirma);
				confirma = toupper(confirma);
				if(confirma == 'S')
				{
					salir = 's';
				}
				else
				{
					printf("Salida cancelada \n");
					system("pause");
				}
				break;

			default:
				printf("Error.. Ingrese una opcion correcta \n");
				break;

		}
	}while(salir != 's');

	return 0;
}

