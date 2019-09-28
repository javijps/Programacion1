/*
 * Pantallas.c
 *
 *  Created on: 28 sep. 2019
 *      Author: javijps
 PENDIENTES_ REEMPLAZAR GETINT, GET STRING Y GET FLOAT*/

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Pantallas.h"
#define STATUS_EMPTY  0
#define STATUS_NOT_EMPTY 1

int imprimirPantallas(pantalla *aPantalla, int cantidad){

	int i;
	int retorno = -1;
	if(aPantalla != NULL && cantidad>0)
	{
		retorno = 0;
		for(i=0;i<cantidad;i++)
		{
			if(aPantalla[i].status==STATUS_EMPTY)
				continue;
			printf("Id: %d - Nombre: %s - Direccion: %s - Tipo: %d - Status: %d - Precio: %.2f \n",
					aPantalla[i].id,aPantalla[i].nombrePantalla,aPantalla[i].direccionPantalla,aPantalla[i].tipoPantalla,
					aPantalla[i].status,aPantalla[i].precioPorDia);
		}
	}
	return retorno;
}

static int generarIdPantalla(void){
	static int id = 0;
	id++;
	return id;
}

int initPantalla(pantalla *aPantalla, int cantidad)
{

	int i;
	int retorno = -1;

	if(aPantalla != NULL && cantidad > 0)
	{
		for(i=0;i<cantidad;i++)
		{
			aPantalla[i].status = STATUS_EMPTY;
		}
		retorno = 0;
	}
	return retorno;
}

int getDatosPantalla(pantalla *aPantalla,int cantidad){

	int retorno = -1;
	struct pantalla bPantalla;
	int i;

	for(i=0;i<cantidad;i++)
	{
		aPantalla[i].id = generarIdPantalla();
		aPantalla[i].status = STATUS_NOT_EMPTY;

		getInt(&bPantalla.tipoPantalla,"Ingrese tipo de pantalla: 1-LCD 2-LED",
				"Error, el numero ingresado no corresponde"
				,1,2,3);//getTipo
		getString(bPantalla.nombrePantalla,"Ingrese el nombre de la pantalla en minuscula",
				"Nombre Incorrecto",
				1,49,3);//getNombre
		getString(bPantalla.direccionPantalla,"Ingrese la direccion de la pantalla en minuscula",
				"Nombre Incorrecto",
				1,49,3);//getDIreccion(getAlfanumerico)
		getFloat(&bPantalla.precioPorDia,"Ingrese precio de pantalla por dia",
				"Error, el precio ingresado es incorrecto",
				500,10000,3);


		aPantalla[i].tipoPantalla = bPantalla.tipoPantalla;
		aPantalla[i].precioPorDia = bPantalla.precioPorDia;
		strncpy(aPantalla[i].nombrePantalla,bPantalla.nombrePantalla,50);
		strncpy(aPantalla[i].direccionPantalla,bPantalla.direccionPantalla,50);

		retorno = 0;
	}
	return retorno;
}

int buscarPantallaLibre(pantalla *aPantalla,int cantidad)
{
	int retorno = -1;
	int i;

	if(aPantalla != NULL && cantidad > 0)
	{
		for(i=0;i<cantidad;i++)
		{
			if(aPantalla[i].status==0)
			{
				return i;
			}

		}
		return retorno;
	}
	return retorno;
}

int altaPantalla(pantalla *aPantalla, int cantidad)
{

	int retorno = -1;
	int index=0;

	if(aPantalla != NULL && cantidad>0)
	{
		index = buscarPantallaLibre(aPantalla,cantidad);

		if(index!=-1)
		{
			getDatosPantalla(aPantalla,cantidad);
			retorno = 0;
		}
	}
	return retorno;
}

int buscarPantallaPorId(pantalla *aPantalla,int cantidad,int id)
{
	int retorno = -1;
	int i;

	if(aPantalla!=NULL && cantidad>0)
	{
		for(i=0;i<cantidad;i++)
		{
			if(aPantalla[i].id == id && aPantalla[i].status == STATUS_NOT_EMPTY)
			{
				retorno = i;
				break;
			}
			//else
				//printf("ID no encontrado!!!\n");
		}
	}
	return retorno;
}

int modificarPantallaPorId(pantalla *aPantalla, int cantidad,int id)
{
	int retorno = -1;
	pantalla bPantalla;
	int index = buscarPantallaPorId(aPantalla,cantidad,id);
	int opcion;


	if(index!=-1)
	{
		do
		{
			if(getInt(&opcion,"\nIngrese: \n1-Modificar Tipo de pantalla. \n"
					"2-Modificar Nombre de pantalla\n"
					"3-Modificar Direccion de la pantalla\n"
					"4-Modificar Precio de la pantalla\n"
					"5-Salir \n",
					"Error, opcion incorrecta\n",
					1,5,2)==0)
			{
				switch(opcion)
				{
				case 1://getTipoPantalla
					if(getInt(&bPantalla.tipoPantalla,"Ingrese tipo de pantalla: 1-LCD 2-LED\n",
							"Error, el numero ingresado no corresponde\n"
							,1,2,2)==0)
					{
						aPantalla[index].tipoPantalla = bPantalla.tipoPantalla;
						retorno = 0;
					}
					else
						printf("Error!");
					break;

				case 2://getNombrePantalla
					if(getString(bPantalla.nombrePantalla,"Ingrese el nombre de la pantalla en minuscula\n",
							"nombre incorrecto\n",
							1,49,2)==0)
					{
						strncpy(aPantalla[index].nombrePantalla,bPantalla.nombrePantalla,50);
						retorno = 0;
					}
					else
						printf("Error!");
					break;

				case 3://getDireccionPAntalla
					if(getString(bPantalla.direccionPantalla,"Ingrese la direccion de la pantalla en minuscula\n",
							"direccion incorrecta\n",
							1,49,2)==0)
					{
						strncpy(aPantalla[index].direccionPantalla,bPantalla.direccionPantalla,50);
						break;
					}
					else
						printf("Error!");
					break;
				case 4://getPrecioPantalla
					getFloat(&bPantalla.precioPorDia,"Ingrese nuevo precio por dia\n",
							"Error, el precio ingresado es incorrecto\n"
							,500,10000,2);
					break;
				}
			}
		}while(opcion!= 5);
	}
	else
		printf("Pantalla no encontrada!!\n");
	return retorno;
}

int bajaPantallaPorId(pantalla *aPantalla,int cantidad,int id)
{

	int retorno = -1;
	int index=0;

	if(aPantalla != NULL && cantidad>0)
	{
		index = buscarPantallaPorId(aPantalla,cantidad,id);

		if(index!=-1)
		{
			aPantalla[index].status = STATUS_EMPTY;
			retorno = 0;
		}
	}
	return retorno;
}

/*
void pantallaForzada(pantalla *aPantalla,int cantidad){

	int aId[] = {1,2,3,4,5};
	int aStatus[] = {1,1,0,0,1};
	char aNombre[][50] = {"Belgrano","Palermo","Recoleta","Microcentro","Barrio Parque"};
	char aDireccion [][50] = {"Cabildo 5000","Santa Fe 4600","Callao 750","Suipacha 324", "Calle 435"};
	float aPrecioPorDia[] = {500,1000,1500,2000,2500};
	int aTipoPantalla[] = {1,1,2,2,1};
	int i;
	struct pantalla bPantalla;

	for(i=0;i<cantidad;i++)
	{
		strncpy(bPantalla.nombrePantalla,aNombre[i],50);
		strncpy(bPantalla.direccionPantalla,aDireccion[i],50);
		bPantalla.id = aId[i];
		bPantalla.status = aStatus[i];
		bPantalla.precioPorDia = aPrecioPorDia[i];
		bPantalla.tipoPantalla = aTipoPantalla[i];
	}
}
*/
