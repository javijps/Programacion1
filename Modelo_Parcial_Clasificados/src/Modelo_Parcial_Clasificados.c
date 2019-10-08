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
#include "Aviso.h"
#define MAX_CLIENT 100
#define STATUS_EMPTY  0
#define STATUS_NOT_EMPTY 1
#define EXIT_MENU 5

int main(void) {

	int option;
	//sClient bClient[MAX_CLIENT];
	sClient bClient[5];

	//sAviso aAviso[MAX_CLIENT];
	sAviso bAviso[5];

	clienteForzado(bClient,5);
	avisoForzado(bAviso,5);
	int idClient;
	int fAlta=-1;

	//initClient(bClient,MAX_CLIENT);
	//initAviso(aAviso,MAX_CLIENT);
	do
	{

		getInt(&option,"\n---------------------\n"
				"Ingrese:\n"
				"1-Alta Cliente\n"
				"2-Modificar Cliente\n"
				"3-Baja Cliente\n"
				"4-Alta Aviso\n"
				"5-Pausar Aviso\n"
				"6-EXIT\n",
				"Error\n",1,5,2);

		//printClient(bClient,5);

		switch(option){
		case 1:
			if(addClient(bClient,1)==0)
			{
				fAlta=0;
				printf("\nAlta exitosa\n");
			}
			else
			{
				printf("\nNo fue posible realizar el alta\n");
			}
			printClient(bClient,5);
			break;
		case 2:
			getInt(&idClient,"\nIngrese ID del cliente a modificar\n","Error\n",1,1000,2);

			if(modifyClientById(bClient,5,idClient)!=0)
			{
				printf("\nNo fue posible realizar la modificacion\n");
			}
			else
			{
				printf("\nModificacion Exitosa\n!");
			}
			printClient(bClient,5);
			break;
		case 3:
			getInt(&idClient,"Ingrese ID del cliente a dar de baja\n","Error\n",1,1000,2);

			if(removeClient(bClient,5,idClient)!=0)
			{
				printf("\nNo fue posible realiza la baja!\n");
			}
			else
			{
				printf("Baja Exitosa!");
			}
			printClient(bClient,5);
			break;
		case 4:
			printClient(bClient,5);//tiene que imprimir solo activos
			if(getDatosAviso(bAviso,1)!=0)
			{
				printf("\nNo fue posible publicar el aviso!\n");
			}
			else
			{
				printf("\nAviso publicado exitosamente!\n");
			}
			printAviso(bAviso,5);
			break;
		case 5:
			//getID publicacion
			//printUNa publicacion
			printAviso(bAviso,5);
			if(pauseAviso(bAviso,5,bClient,5)!=0)
				printf("Pausado Incorrecto!!\n");
			else
			{
				printf("ok");
				printAviso(bAviso,5);
			}

		}
	}while(option!=6);
	return EXIT_SUCCESS;
}

