/*
 ============================================================================
 Name        : ParcialPantallasyPublicaciones.c
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
#include "Pantallas.h"
#include "Publicidades.h"
#include "utn.h"
#define QTY_PANTALLAS 100
#define CONTRATACIONES 1000

int main(void){

	char bCuitCLiente[50];
	int option;
	int idPantalla;
	//pantalla aPantalla[MAX_CLIENT];
	pantalla bPantalla[5];
	//publicidad apublicidad[MAX_CLIENT];
	publicidad bpublicidad[5];
	pantallaForzada(bPantalla,5);
	publicidadesForzadas(bpublicidad,5);
	//initPantalla(bPublicidad,MAX_CLIENT);
	//initPublicidad(aPublicidad,MAX_CLIENT);
	do
	{

		getInt(&option,"\n---------------------\n"
				"Ingrese:\n"
				"1-Alta Pantalla\n"
				"2-Modificar Pantalla\n"
				"3-Baja Pantalla\n"
				"4-Contratar Publicidad\n"
				"5-Modificar condiciones de publicidad\n"
				"6-Cancelar condiciones de publicidad\n"
				"7-Consulta de facturacion\n"
				"8-Listar Contrataciones\n"
				"9-Listar Pantallas Existentes\n"
				"10-Informar\n"
				"  a-Lista​r cliente​ ​ con contrataciones​ ​ e ​importe​ ​a pagar​ ​por​ ​contratacion\n."
				"  b-Cliente con importe mas alto a facturar\n"
				"11-EXIT\n",
				"Error\n",1,12,2);

		switch(option)
		{
		case 1:
			if(altaPantalla(bPantalla,5)==0)//que no sea forzada.aPantalla
				printf("\nAlta exitosa\n");
			else
				printf("\nNo fue posible realizar el alta\n");
			imprimirPantallas(bPantalla,5);
			break;
		case 2:
			getInt(&idPantalla,"\nIngrese ID de la pantalla a modificar\n","Error\n",1,1000,2);
			if(modificarPantallaPorId(bPantalla,5,idPantalla)!=0)
				printf("\nNo fue posible realizar la modificacion\n");
			else
				printf("\nModificacion Exitosa\n!");
			imprimirPantallas(bPantalla,5);//es para chequear, borrar de ser necesario
			break;
		case 3:
			if(bajaPantallaPorId(bPantalla,5,idPantalla)!=0)
				printf("\nNo fue posible realiza la baja!\n");
			else
				printf("Baja Exitosa!");
			imprimirPantallas(bPantalla,5);
			break;
		case 4:
			imprimirPantallas(bPantalla,5);
			if(getInt(&idPantalla,"Ingrese ID de la pantalla a contratar\n","Error\n",1,1000,2)==0)
			{
				if(getDatosPublicidad(bpublicidad,1,idPantalla)!=0)
					printf("\nNo fue posible contratar la publicidad!!\n");
				else
					printf("\nPublicidad contratada exitosamente!\n");
			}
			imprimirPublicidades(bpublicidad,5);
			break;
		case 5:
			if(getString(bCuitCLiente,"Ingrese cuit Cliente\n",
					"Error, el cuit ingresado no corresponde\n"
					,1,50,3)==0)//getcuit
			{
				if(imprimirPantallasPorCuit(bPantalla,5,bpublicidad,5,bCuitCLiente)!=0)
					printf("No fue posible imprimir las pantallas!\n");
			}
			break;
		case 6://mismas funciones punto 5 con modificacion para la baja
			break;
			//case 7. buscarPublicidadPOrCUit, despues calcular la facturacion
			//(publicidad.dias contratados * pantalla.precio por dia), guardarla en sAuxiliar e imprimir el array o similar.
			//case 8 listar contrataciones. Imprimir publicidad con los campos especificados.
			//case 9 listar pantallas con todos sus campos.
			//case 10_1 listar cliente(estructura auxiliar cliente con contador de contrataciones y monto de cada una) o similar
			//case 10_2 usar punto anteriror para hacer un acumulador de facturas para calcular la facturacion total por cliente y calcular maximo
		}
	}while(option!=11);
	/*
		imprimirPublicidades(bpublicidad,5);
		imprimirPantallas(bPantalla,5);
		if(getString(bCuitCLiente,"Ingrese cuit\n",
				"Error, el cuit ingresado no corresponde\n"
				,1,50,3)==0)
		{

				printf("FUNCIONA!");
			else
				printf("no funciona");
		}
*/	return EXIT_SUCCESS;
}
