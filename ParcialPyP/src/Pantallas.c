/*
 * Pantallas.c
 *
 *  Created on: 28 sep. 2019
 *      Author: javijps
 PENDIENTES_ REEMPLAZAR GETINT, GET STRING Y GET FLOAT, poner nombre de lo q es una pantalla de la estructura pantalla. REVISAR XQ NO FUNCIONA
 LA PANTALLA FORZADA */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Pantallas.h"
#define STATUS_EMPTY  0
#define STATUS_NOT_EMPTY 1

/**
* \brief Imprime la informacion correspondiente a pantallas activas..
* \param pantalla *aPantalla puntero a una xxxxx de la estructura pantalla.
* \param cantidad Cantidad de pantallas a imprimir
* \return Si tuvo exito al imprimir devuelve [0] o si fallo [-1]
*/
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

/**
* \brief Genera el ID correspondiente a una pantalla.
* \return Devuelve el ID correspondiente.
*/
static int generarIdPantalla(void){
	static int id = 0;
	id++;
	return id;
}

/**
* \brief Inicializa las pantallas con STATUS_EMPTY.
* \param pantalla *aPantalla puntero a una xxxxx de la estructura pantalla.
* \param cantidad Cantidad de pantallas a inicializar
* \return Si tuvo exito al inicializar devuelve [0] o si fallo [-1]
*/
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
/**
* \brief Solicita los datos correspondientes a una pantalla.
* \param pantalla *aPantalla puntero a una xxxxx de la estructura pantalla.
* \param cantidad Cantidad de pantallas.
* \return Si tuvo exito al completar todos los campos devuelve [0] o si fallo [-1]
*/
int getDatosPantalla(pantalla *aPantalla,int cantidad){

	int retorno = -1;
	struct pantalla bPantalla;
	int i;

	for(i=0;i<cantidad;i++)
	{
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
		aPantalla[i].id = generarIdPantalla();//DEBERIA IR DENTRO DE ALTA, AL FINAL
		aPantalla[i].status = STATUS_NOT_EMPTY;

		retorno = 0;
	}
	return retorno;
}

/**
* \brief Busca una pantalla sin datos cargados.
* \param pantalla *aPantalla puntero a una xxxxx de la estructura pantalla.
* \param cantidad Cantidad de pantallas.
* \return Si tuvo exito al encontrar una pantalla vacia devuelve [0] o si fallo [-1]
*/
int buscarPantallaLibre(pantalla *aPantalla,int cantidad)
{
	int retorno = -1;
	int i;

	if(aPantalla != NULL && cantidad > 0)
	{
		for(i=0;i<cantidad;i++)
		{
			if(aPantalla[i].status==0)
				return i;
		}
	}
	return retorno;
}

/**
* \brief Realiza el alta de una nueva pantalla.
* \param pantalla *aPantalla puntero a una xxxxx de la estructura pantalla.
* \param cantidad Cantidad de pantallas.
* \return Si tuvo exito al realizar el alta devuelve [0] o si fallo [-1]
*/
int altaPantalla(pantalla *aPantalla, int cantidad)
{

	int retorno = -1;
	int index=0;

	if(aPantalla != NULL && cantidad>0)
	{
		index = buscarPantallaLibre(aPantalla,cantidad);

		if(index!=-1)
		{
			if(getDatosPantalla(aPantalla,cantidad)==0)
				retorno = 0;
		}
	}
	return retorno;
}

/**
* \brief Busca una pantalla existente por medio de su ID.
* \param pantalla *aPantalla puntero a una xxxxx de la estructura pantalla.
* \param cantidad Cantidad de pantallas.
* \param id ID de pantalla a ser encontrada.
* \return Si tuvo exito al encontrar la pantalla indicada devuelve [0] o si fallo [-1]
*/
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

/**
* \brief Modifica los campos de una pantalla existente por medio de su ID.
* \param pantalla *aPantalla puntero a una xxxxx de la estructura pantalla.
* \param cantidad Cantidad de pantallas.
* \param id ID de pantalla a ser modificada.
* \return Si tuvo exito al modificar la pantalla indicada devuelve [0] o si fallo [-1]
*/
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

/**
* \brief Da de baja una pantalla existente por medio de su ID.
* \param pantalla *aPantalla puntero a una xxxxx de la estructura pantalla.
* \param cantidad Cantidad de pantallas.
* \param id ID de pantalla a ser dada de baja.
* \return Si tuvo exito al realizar la baja de la pantalla indicada devuelve [0] o si fallo [-1]
*/
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


void pantallaForzada(pantalla aPantalla[],int cantidad){

	int aId[] = {1,2,3,4,5};
	int aStatus[] = {1,1,1,1,1};
	char aNombre[][50] = {"Belgrano","Palermo","Recoleta","Microcentro","Barrio Parque"};
	char aDireccion [][50] = {"Cabildo 5000","Santa Fe 4600","Callao 750","Suipacha 324", "Calle 435"};
	float aPrecioPorDia[] = {500,1000,1500,2000,2500};
	int aTipoPantalla[] = {1,1,2,2,1};
	int i;

	for(i=0;i<cantidad;i++)
	{
		strncpy(aPantalla[i].nombrePantalla,aNombre[i],50);
		strncpy(aPantalla[i].direccionPantalla,aDireccion[i],50);
		aPantalla[i].id = aId[i];
		aPantalla[i].status = aStatus[i];
		aPantalla[i].precioPorDia = aPrecioPorDia[i];
		aPantalla[i].tipoPantalla = aTipoPantalla[i];
	}



}

typedef struct sCliente{

	char cuit[15];
	int acumuladorFacturasApagar;
};

