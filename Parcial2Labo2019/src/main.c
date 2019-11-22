/*
 ============================================================================
 Name        : TP4_uso_ll.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

#include "Cachorro.h"
#include "LinkedList.h"
#include "Controller.h"
#include "utn.h"


/****************************************************
    Menu:
     1. Cargar los datos de los cachorros desde el archivo.
     2. Imprimir Lista.
     3. Filtrar menores de 45 dias.
     4. Filtrar machos.
     5. Generar listado de callejeros.
     6. Salir
 *****************************************************/

int main()
{

	int option;
	LinkedList* listaCachorros = ll_newLinkedList();

	do{
		//system("clear"); DESCOMENTAR DE SER NECESARIO
		if(getInt(&option,"\nIngrese opcion:\n1-Cargar los datos de los cachorros desde el archivo.\n"
				"2-Imprimir Lista.\n"
				"3-Filtrar menores de 45 dias.\n"
				"4-Filtrar machos\n"
				"5-Generar listado de callejeros.\n"
				"6-Salir","Error\n",1,6,2)==0)
		{
			switch(option)
			{
			case 1:
				controller_loadFromText("cachorros.csv",listaCachorros);
				break;
			case 2:
				controller_ListsCachorro(listaCachorros);
				break;
			case 3:
				controller_Filter45(listaCachorros);
				break;
			case 4:
				controller_FilterMachos(listaCachorros);
				break;
			case 5:
				controller_FilterCallejeros(listaCachorros);
				break;
			}
		}
		}while(option!=6);
	printf("Programa cerrado!\n");
	return 0;
}
