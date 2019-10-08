/*
 * Client.c
 *
 *  Created on: 6 oct. 2019
 *      Author: javijps
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Client.h"
#define STATUS_EMPTY  0
#define STATUS_NOT_EMPTY 1

/** \brief To indicate that all position in the array are empty,
*this function put the flag (isEmpty) in TRUE in all
*position of the array
* \param list Client* Pointer to array of Clients
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initClient(sClient *list, int len){

	int i;
	int retorno = -1;

	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			list[i].statusClient = STATUS_EMPTY;

		}
		retorno = 0;
	}
	return retorno;

}


/** \brief print the content of Clients array
*
* \param list Client*
* \param length int
* \return int
*/
int printClient(sClient *list, int len)
{
	int i;
	int retorno = -1;
	if(list != NULL && len>0)
	{

		for(i=0;i<len;i++)
		{
			//if(list[i].statusClient==STATUS_EMPTY)//PARA IMPRIMIR SOLO ACTIVOS
				//continue;
			printf("\n Id: %d - Name: %s - Last name: %s - Cuit: %s - Status: %d \n",
					list[i].idCLient,list[i].name,list[i].lastName,list[i].cuit,list[i].statusClient);
		}
		retorno = 0;
	}
	return retorno;
}

/**
* \brief Genera el ID correspondiente a una pantalla.
* \return Devuelve el ID correspondiente.
*/

static int idClient(void){
	static int id = 0;
	id++;
	return id;
}

int getDatosClient(sClient* list,int len){

	int retorno = -1;
	sClient bcliente;
	int i;

	for(i=0;i<len;i++)
	{

		if(getString(bcliente.name,"Ingrese el nombre del cliente\n",
				"Nombre Incorrecto\n",
				1,49,3)!=0)//reemplazar get nombre
			break;
		getString(bcliente.lastName,"Ingrese el apellido del cliente\n",
				"Nombre Incorrecto\n",
				1,49,3);//reemplazar get apellido
		if(getString(bcliente.cuit,"Ingrese cuit del cliente, sin - ni /\n",
				"Error, el cuit ingresado es incorrecto\n",
				1,49,2)!=0)//get cuit
			break;


		strncpy(list[i].name,bcliente.name,50);
		strncpy(list[i].lastName,bcliente.lastName,50);
		strncpy(list[i].cuit,bcliente.cuit,50);
		list[i].statusClient = STATUS_NOT_EMPTY;
		list[i].idCLient = idClient();
		retorno = 0;
	}
	return retorno;
}

/** \brief find an Client by Id en returns the index position in array.
*
* \param list Client*
* \param len int
* \param id int
* \return Return Client index position or (-1) if [Invalid length or NULL
pointer received or Client not found]
*
*/
int findClientById(sClient* list, int len,int id)
{
	int retorno = -1;
	int i;

	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].idCLient == id && list[i].statusClient == STATUS_NOT_EMPTY)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int findEmptyClient(sClient* list,int len)
{
	int retorno = -1;
	int i;

	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].statusClient==STATUS_EMPTY)
				return i;
		}
	}
	return retorno;
}


/** \brief add in a existing list of Clients the values received as parameters
in the first empty position
* \param list Client*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/

int addClient(sClient* list,int len)
{

	int retorno = -1;
	int index=0;

	if(list != NULL && len>0)
	{
		index = findEmptyClient(list,len);

		if(index!=-1)
		{
			if(getDatosClient(list,len)==0)
			{
				retorno = 0;
			}
		}
	}
	return retorno;
}



void clienteForzado(sClient *list,int cantidad){

	int aId[] = {1,2,3,4,5};
	int aStatus[] = {1,1,1,1,1};
	char aName[][50] = {"Melina","Camila","Gabriela","Rosa","Cristian"};
	char aLastName [][50] = {"Scian","Castro","Diaz","Simonetti", "Diaz"};
	char aCuit[][15] = {"30342670355","30341364355","20341364302","30954362022","20381264402"};
	int i;

	for(i=0;i<cantidad;i++)
	{
		strncpy(list[i].name,aName[i],50);
		strncpy(list[i].lastName,aLastName[i],50);
		strncpy(list[i].cuit,aCuit[i],50);
		list[i].idCLient = aId[i];
		list[i].statusClient = aStatus[i];
	}
}


int modifyClientById(sClient* list,int len,int id)
{
	int retorno = -1;
	char option;
	sClient bClient;

	int index = findClientById(list,len,id);

	if(index!=-1)
	{
		do
		{

			getChar(&option,"a-Modificar nombre\n"
					"b-Modificar apellido\n"
					"c-Modificar cuit\n"
					"e-SALIR\n",
					"Error,opcion incorrecta\n",
					'a','e',2);

			switch(option)
			{
			case 'a':
				if(getNombre(bClient.name,50,2)!=0)
				{
					printf("No se pudo modificar el nombre");
					retorno = -1;
				}
				else
				{
					strncpy(list[index].name,bClient.name,50);
					retorno = 0;
					printf("cambio");
				}
				break;
			case 'b':
				if(getApellido(bClient.lastName,50,2)!=0)
				{
					printf("No se pudo modificar el apellido");
					retorno = -1;
				}
				else
				{
					strncpy(list[index].lastName,bClient.lastName,50);
					retorno = 0;
					printf("cambio");
				}
				break;
			case 'c':
				if(getCuit(bClient.cuit)!=0)
				{
					printf("No se pudo modificar el apellido");
					retorno = -1;
				}
				else
				{
					strncpy(list[index].cuit,bClient.cuit,15);
					retorno = 0;
					printf("cambio");
				}
				break;

			}
		}while(option!='e');

	}
	return retorno;

}

/** \brief Remove a Client by Id (put isEmpty Flag in 1)
*
* \param list Client*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a Client] - (0) if Ok
*
*/
int removeClient(sClient* list, int len, int id)
{

	int retorno = -1;
	int index=0;

	if(list != NULL && len>0)
	{
		index = findClientById(list,len,id);

		if(index!=-1)
		{
			list[index].statusClient = STATUS_EMPTY;
			retorno = 0;
		}
	}
	return retorno;

}
