/*
 * Aviso.c
 *
 *  Created on: 7 oct. 2019
 *      Author: javijps
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Aviso.h"
#include "Client.h"
#define PUBLICACION_ACTIVA 2
#define PUBLICACION_PAUSADA 1
#define PUBLICACION_VACIA 0
#define STATUS_EMPTY  0
#define STATUS_NOT_EMPTY 1



/** \brief To indicate that all position in the array are empty,
*this function put the flag (isEmpty) in TRUE in all
*position of the array
* \param list Aviso* Pointer to array of Avisos
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initAviso(sAviso *list, int len){

	int i;
	int retorno = -1;

	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			list[i].statusAviso = PUBLICACION_VACIA;
		}
		retorno = 0;
	}
	return retorno;

}

/** \brief print the content of Avisos array
*
* \param list Aviso*
* \param length int
* \return int
*/
int printAviso(sAviso *list, int len)
{
	int i;
	int retorno = -1;
	if(list != NULL && len>0)
	{

		for(i=0;i<len;i++)
		{
			//if(list[i].statusAviso==STATUS_EMPTY)//PARA IMPRIMIR SOLO ACTIVOS
				//continue;
			printf("\n Id Aviso: %d - Texto del aviso: %s - Numero del rubro del aviso: %d - Id cliente: %d  - Status Aviso: %d \n",
					list[i].idAviso,list[i].textoAviso,list[i].numeroRubro,list[i].idCliente,list[i].statusAviso);
		}
		retorno = 0;
	}
	return retorno;
}

void mostrarUnAviso(sAviso miAviso)
{
    printf("ID Aviso%d - id Cliente %d - Numero de rubro %d - Status Aviso %d - Texto aviso %s\n",miAviso.idAviso,miAviso.idCliente,
    		miAviso.numeroRubro, miAviso.statusAviso,miAviso.textoAviso);
}



/**
* \brief Genera el ID correspondiente a una pantalla.
* \return Devuelve el ID correspondiente.
*/

static int idAviso(void){
	static int id = 0;
	id++;
	return id;
}

void avisoForzado(sAviso *list,int cantidad){

	int aIdAviso[] = {1,2,3,4,5};
	int aStatusAviso[] = {0,1,2,1,1};
	char aTextoAviso[][64] = {"Se busca camarero full time\n",
			                  "Vendo mueble antiguo. Perfecto estado\n",
							  "Alquilo departamento en San Bernardo\n",
							  "Se busca despachante de aduana\n",
							  "Se ofrece servicios de jardineria en zona sur\n"};
	int aNumeroRubro[5] = {3,3,9,1,5};
	int aIdCliente[5] = {1,2,3,4,5};
	int i;


	for(i=0;i<cantidad;i++)
	{
		strncpy(list[i].textoAviso,aTextoAviso[i],64);
		list[i].idAviso = aIdAviso[i];
		list[i].statusAviso = aStatusAviso[i];
		list[i].numeroRubro = aNumeroRubro[i];
		list[i].idCliente = aIdCliente[i];
	}
}

int getDatosAviso(sAviso* list,int len){

	int retorno = -1;
	sAviso bAviso;
	int i;

	for(i=0;i<len;i++)
	{

		if(getInt(&bAviso.idCliente,"Ingrese el ID del cliente\n",
				"Id incorrecto Incorrecto\n",
				1,100,3)!=0)
			break;
		if(getString(bAviso.textoAviso,"Ingrese texto del aviso","Texto incorrecto!!",1,64,2)!=0)//get aviso
			break;
		if(getInt(&bAviso.numeroRubro,"Ingrese numero de rubro del Aviso del 1 al 5\n",
				"Error, el numero de rubro ingresado es incorrecto\n",
				1,49,2)!=0)//imprimir rubros
			break;

		strncpy(list[i].textoAviso,bAviso.textoAviso,64);
		list[i].idCliente = bAviso.idCliente;
		list[i].statusAviso = bAviso.statusAviso;
		list[i].numeroRubro = bAviso.numeroRubro;
		list[i].statusAviso = PUBLICACION_ACTIVA;
		list[i].idAviso = idAviso();
		retorno = 0;
	}
	return retorno;
}

int findAvisoById(sAviso* list, int len,int id)
{
	int retorno = -1;
	int i;

	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].idAviso == id && list[i].statusAviso == PUBLICACION_ACTIVA)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}


int pauseAviso(sAviso* listAviso, int lenAviso, int idAviso,sClient* listClient,int lenCLient)
{
	int retorno = -1;
	sAviso bAviso;
	char respuesta;
	int index;
	int indexClient;

	if(listAviso!=NULL && lenAviso>0 && getInt(&bAviso.idAviso,"Ingrese Id de la publicacion","Error!",1,100,2)==0)
	{
		index = findAvisoById(listAviso,lenAviso,bAviso.idAviso);//busco el aviso y lo guardo en index.
		if(index!=-1)//si es un aviso que existe, para esto debo inicializar todo en -1
		{
			mostrarUnAviso(listAviso[index]);
			if(listAviso[index].statusAviso==PUBLICACION_ACTIVA)//busco en la posicion index si el aviso es activo
			{
				bAviso = listAviso[index];//guardo el aviso en un buffer
				indexClient = findClientById(listClient,lenCLient,bAviso.idCliente); //a partir del buffer, tomo el id de cliente y busco en el array cliente
				printf("encontrado!!\n");
				printClient(listClient,lenCLient);//hacer funcion printUNSOLOCLIENTE.
				getLetter(&respuesta,"Para confirmar el pausado de la publicacion ingrese s\n,"
						"de lo contrario, ingrese \n",
						"Error, respuesta incorrecta\n",2);
				if(respuesta=='s')
				{
					listAviso[index].statusAviso = PUBLICACION_PAUSADA;
					printf("Publicacion pausada!!\n");
					retorno = 0;
				}
				else
				{
					printf("OPeracion cancelada!!\n");
				}
			}
		}
	}
	return retorno;
}
