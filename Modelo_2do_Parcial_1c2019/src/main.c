/*
 ============================================================================
 Name        : Modelo_2do_Parcial_1c2019.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Venta.h"
#include "utn.h"

int main()	//VALIDAR TIPO DE ARCHIVO Y FECHA DE VENTA
{

	int option;
	LinkedList* listaVenta = ll_newLinkedList();

	do{
		//system("clear"); DESCOMENTAR DE SER NECESARIO
		if(getInt(&option,"\nIngrese opcion:\n1-Cargar los datos de las ventas desde el archivo data.csv (modo texto).\n"
				"2-Listar empleados\n"
				"3-Generar Archivo Informes\n"
				"10-Exit","Error\n",1,11,2)==0)
		{
			switch(option)
			{
			case 1:
				controller_loadFromText("data.csv",listaVenta);
				break;
			case 2:
				controller_ListVenta(listaVenta);
				break;
			case 3:
				controller_generarInformes("informes.txt",listaVenta);
				//adentro tiene que tener una funcion para cada informe
				break;
//			case 4:
//				controller_loadFromText("data.csv",listaVenta);
//				break;
//			case 9:
////				if(flagBinario==0)
////					printf("No es posible guardar el archivo en modo binario si no se abrio un archivo de ese tipo!\n");
////				else
//					controller_saveAsBinary("data.bin",listaVenta);
//				break;
//			case 10:
//				if(controller_exitMenu(listaVenta)==0)
//					option=11;
//				break;
			}
		}
		}while(option!=10);
	printf("Programa cerrado!\n");
	return 0;
}
