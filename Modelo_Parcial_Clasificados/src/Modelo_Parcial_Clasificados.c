/*
 ============================================================================
 Name        : Modelo_Parcial_Clasificados.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Client.h"
#define MAX_CLIENT 100
#define STATUS_EMPTY  0
#define STATUS_NOT_EMPTY 1
#define EXIT_MENU 5

int main(void) {

	int option;
	//sClient bClient[MAX_CLIENT];
	sClient bClient[5];
	clienteForzado(bClient,5);
	int idClient;
	int fAlta=-1;

	//initClient(bClient,MAX_CLIENT);
	do
	{

		getInt(&option,"\n---------------------\n"
				"Ingrese:\n"
				"1-Alta Cliente\n"
				"2-Modificar Cliente\n"
				"5-EXIT",
				"Error",1,5,2);

		printClient(bClient,5);

		switch(option){
		case 1:
			if(addClient(bClient,1)==0)
			{
				fAlta=0;
				printf("ALta exitosa");
			}
			printClient(bClient,5);
			break;
		case 2:
			getInt(&idClient,"Ingrese ID del cliente a modificar\n","Error\n",1,1000,2);

			if(modifyClientById(bClient,5,idClient)!=0)
			{
				printf("no salio");
			}
			else
			{
				printf("Modificacion Exitosa!");
			}
			printClient(bClient,5);
			break;
		}
	}while(option!=5);
	printf("hola");
	return EXIT_SUCCESS;
}

