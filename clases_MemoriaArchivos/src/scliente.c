/*
 * persona.c
 *
 *  Created on: 22 oct. 2019
 *      Author: alumno
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scliente.h"


static int isValidNombre(char* nombre)
{
	return 1;
}

static int isValidDireccion(char* direccion)
{
	return 1;
}

static int isValidCuit(char* cuit)
{
	return 1;
}

static int isValidLocalidad(char* localidad)
{
	return 1;
}


sCliente* cli_new_Cliente()
{
	return malloc(sizeof(sCliente));
}

void cli_deleteCliente(sCliente* this)
{
	free(this);
}


int cli_setNombre(sCliente* this,char* nombre)
{
	int retorno = -1;

	if(this!=NULL && isValidNombre(nombre))
	{
		strcpy(this->nombre,nombre);
		retorno = 0;
	}
	return retorno;
}


int cli_getNombre(sCliente* this,char* nombre)
{
	int retorno = -1;

	if(this!=NULL)
	{
		strcpy(nombre,this->nombre);
		retorno = 0;
	}
	return retorno;
}





int cli_setDireccion(sCliente* this,char* direccion)
{
	int retorno = -1;

	if(this!=NULL && isValidDireccion(direccion))
	{
		strcpy(this->direccion,direccion);
		retorno = 0;
	}
	return retorno;
}


int cli_getDireccion(sCliente* this,char* direccion)
{
	int retorno = -1;

	if(this!=NULL)
	{
		strcpy(direccion,this->direccion);
		retorno = 0;
	}
	return retorno;
}


int cli_setCuit(sCliente* this,char* cuit)
{
	int retorno = -1;

	if(this!=NULL && isValidCuit(cuit))
	{
		strcpy(this->cuit,cuit);
		retorno = 0;
	}
	return retorno;
}


int cli_getCuit(sCliente* this,char* cuit)
{
	int retorno = -1;

	if(this!=NULL)
	{
		strcpy(cuit,this->cuit);
		retorno = 0;
	}
	return retorno;
}





int cli_setLocalidad(sCliente* this,char* localidad)
{
	int retorno = -1;

	if(this!=NULL && isValidLocalidad(localidad))
	{
		strcpy(this->localidad,localidad);
		retorno = 0;
	}
	return retorno;
}


int cli_getLocalidad(sCliente* this,char* localidad)
{
	int retorno = -1;

	if(this!=NULL)
	{
		strcpy(localidad,this->localidad);
		retorno = 0;
	}
	return retorno;
}

sCliente cli_new_ClienteParametros(char *nombre,char *direccion,char *cuit,char *localidad)
{
	sCliente* retorno = NULL;
	sCliente* this;
	this = cli_new_Cliente();

	if(this!=NULL)
	{
		if(cli_setNombre(this,nombre)==0 &&
				cli_setDireccion(this,direccion)==0 &&
				cli_setCuit(this,cuit)==0 &&
				cli_setLocalidad(this,localidad)==0)
			retorno = this;
		else
			cli_deleteCliente(this);
	}
	return *retorno;
}


void printPerson(sCliente* pCliente)
{
	printf("ID Cliente: %d\nNombre persona %s\nCuit: %s\n:Direccion %s\n,Localidad %s\n",
			pCliente->idCliente,pCliente->nombre,pCliente->cuit,pCliente->direccion,pCliente->localidad);
}





