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
