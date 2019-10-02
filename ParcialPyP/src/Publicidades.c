/*
 * Publicidades.c
 *
 *  Created on: 28 sep. 2019
 *      Author: javijps
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Pantallas.h"
#include "Publicidades.h"
#define STATUS_EMPTY  0
#define STATUS_NOT_EMPTY 1


/**
* \brief Genera el ID correspondiente a una pantalla.
* \return Devuelve el ID correspondiente.
*/
static int generarIdPublicidad(void)
{
	static int id = 0;
	id++;
	return id;
}

/**
* \brief Imprime la informacion correspondiente a publicidades activas.
* \param publicidad *aPantalla puntero a una xxxxx de la estructura publicidad.
* \param cantidad Cantidad de publicidades a imprimir
* \return Si tuvo exito al imprimir devuelve [0] o si fallo [-1]
*/
int imprimirPublicidades(publicidad *aPublicidad, int cantidad)
{

	int i;
	int retorno = -1;
	if(aPublicidad != NULL && cantidad>0)
	{
		retorno = 0;
		for(i=0;i<cantidad;i++)
		{
			if(aPublicidad[i].status==STATUS_EMPTY)
				continue;//MODIFICAR TIPO DE DATO EL PRINTF PARA EL CUIT
			printf("Id: %d - Cuit: %s - Dias: %d - Archivo: %s - Status: %d - ID Pantalla: %d \n",
					aPublicidad[i].id,aPublicidad[i].cuitCliente,aPublicidad[i].diasPublicacion,aPublicidad[i].filePublicacion,
					aPublicidad[i].status,aPublicidad[i].idPantalla);
		}
	}
	return retorno;
}

/**
* \brief Inicializa las publicidades con STATUS_EMPTY.
* \param aPublicidad puntero a una xxxxx de la estructura publicidad.
* \param cantidad Cantidad de publicidades a imprimir
* \return Si tuvo exito al inicializar devuelve [0] o si fallo [-1]
*/
int initPublicidad(publicidad *aPublicidad, int cantidad)
{

	int i;
	int retorno = -1;

	if(aPublicidad != NULL && cantidad > 0)
	{
		for(i=0;i<cantidad;i++)
		{
			aPublicidad[i].status = STATUS_EMPTY;
		}
		retorno = 0;
	}
	return retorno;
}

/**
* \brief Busca una publicidad sin datos cargados.
* \param pantalla *aPublicidad puntero a una xxxxx de la estructura publicidad.
* \param cantidad Cantidad de publicidades.
* \return Si tuvo exito al encontrar una publicidad vacia devuelve [0] o si fallo [-1]
*/
int buscarPublicidadLibre(publicidad *aPublicidad,int cantidad)
{
	int retorno = -1;
	int i;

	if(aPublicidad != NULL && cantidad > 0)
	{
		for(i=0;i<cantidad;i++)
		{
			if(aPublicidad[i].status==STATUS_EMPTY)
				return i;
		}
	}
	return retorno;
}

int getDatosPublicidad(publicidad *aPublicidad,int cantidad){//falta getCuit, getFile,

	int retorno = -1;
	struct publicidad bPublicidad;
	int i;

	for(i=0;i<cantidad;i++)
	{

		getString(bPublicidad.cuitCliente,"Ingrese cuit\n",
						"Error, el cuit ingresado no corresponde\n"
						,1,50,3);//getTipo
		getInt(&bPublicidad.diasPublicacion,"Ingrese la cantidad de dias a contratar\n",
				"Numero incorrecto\n",
				1,49,3);
		getString(bPublicidad.filePublicacion,"Ingrese el archivo correspondiente a la publicacion\n",
				"Archivo Incorrecto\n",
				1,49,3);

		aPublicidad[i].diasPublicacion = bPublicidad.diasPublicacion;
		strncpy(aPublicidad[i].cuitCliente,bPublicidad.cuitCliente,50);
		strncpy(aPublicidad[i].filePublicacion,bPublicidad.filePublicacion,50);
		aPublicidad[i].id = generarIdPublicidad();
		aPublicidad[i].status = STATUS_NOT_EMPTY;

		retorno = 0;
	}
		return retorno;
}

/**
* \brief Realiza la contratacion de una publicidad en una pantalla especifica.
* \param publicidad *aPantalla puntero a una xxxxx de la estructura publicidad.
* \param cantidad Cantidad de publicidades a dar de alta.
* \param idPantalla Id de la pantalla en la que se contratara la publicidad.
* \return Si tuvo exito al realizar la contratacion devuelve [0] o si fallo [-1]
*/
int contratarPublicidad(publicidad *aPublicidad, int cantidad,int idPantalla)
{
	int retorno = -1;
	int index;

	if(aPublicidad!=NULL && cantidad==1)
	{
		index = buscarPublicidadLibre(aPublicidad,cantidad);
		if(index!=-1)
		{
			if(getDatosPublicidad(aPublicidad,1)==0)
			{
				aPublicidad[index].id = generarIdPublicidad();
				aPublicidad[index].status = STATUS_NOT_EMPTY;
				aPublicidad[index].idPantalla = idPantalla;
				retorno=0;
			}
		}
	}
	else
		printf("Solo puede darse de alta una publicidad a la vez");
	return retorno;
}

/**
* \brief Busca una pantalla existente por medio de su ID.
* \param pantalla *aPantalla puntero a una xxxxx de la estructura pantalla.
* \param cantidad Cantidad de pantallas.
* \param id ID de pantalla a ser encontrada.
* \return Si tuvo exito al encontrar la pantalla indicada devuelve [0] o si fallo [-1]
*/
int buscarPublicidadPorId(publicidad *aPublicidad, int cantidad,int cuit)
{
	int retorno = -1;
	int i;

	if(aPublicidad!=NULL && cantidad>0)
	{
		for(i=0;i<cantidad;i++)
		{
			if(aPublicidad[i].cuitCliente == cuit && aPublicidad[i].status == STATUS_NOT_EMPTY)
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

int bajaPublicidadPorId(publicidad *aPublicidad,int cantidad,int id)
{

	int retorno = -1;
	int index=0;

	if(aPublicidad != NULL && cantidad>0)
	{
		index = buscarPantallaPorId(aPublicidad,cantidad,id);

		if(index!=-1)
		{
			aPublicidad[index].status = STATUS_EMPTY;
			retorno = 0;
		}
	}
	return retorno;
}

void publicidadesForzadas(publicidad aPublicidad[],int cantidad){

	int aId[] = {1,2,3,4,5};
	int aStatus[] = {1,1,1,1,1};
	char aCuitCliente[][50] = {"20322670355","25322840657","15646543544","302763505","43241987256"};
	char  aFilePublicacion[][50] = {};
	int aDiasPublicacion[] = {5,4,9,2,3};
	int aIdPantalla[] = {};
	int i;

	for(i=0;i<cantidad;i++)
	{
		strncpy(aPublicidad[i].cuitCliente,aCuitCliente[i],50);
		strncpy(aPublicidad[i].filePublicacion,aFilePublicacion[i],50);
		aPublicidad[i].id = aId[i];
		aPublicidad[i].status = aStatus[i];
		aPublicidad[i].diasPublicacion = aDiasPublicacion[i];
		aPublicidad[i].idPantalla = aIdPantalla[i];
	}



}
