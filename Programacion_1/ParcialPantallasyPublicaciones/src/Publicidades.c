/*
 * Publicidades.c
 *
 *  Created on: 28 sep. 2019
 *      Author: javijps
 */
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Publicidades.h"
#define STATUS_EMPTY  0
#define STATUS_NOT_EMPTY 1

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
				continue;//MODIFICAR TIPO DE DATON EL PRINTF PARA EL CUIT
			printf("Id: %d - Cuit: %d - Dias: %d - Archivo: %s - Status: %d - ID Pantalla: %d \n",
					aPublicidad[i].id,aPublicidad[i].cuitCliente,aPublicidad[i].diasPublicacion,aPublicidad[i].filePublicacion,
					aPublicidad[i].status,aPublicidad[i].idPantalla);
		}
	}
	return retorno;
}


