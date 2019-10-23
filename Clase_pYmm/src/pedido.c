/*
 * pedido.c
 *
 *  Created on: 22 oct. 2019
 *      Author: alumno
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pedido.h"



//rehacer los set si estan al reves y chequear con codigo de mauricio




static int isValidIdCliente(int idCliente)
{
	return 1;
}

static float isValidKgTotales(float kgTotales)
{
	return 1;
}

static float isValidKgR1(float kgR1)
{
	return 1;
}

static float isValidKgR2(float kgR2)
{
	return 1;
}

static float isValidKgR3(float kgR3)
{
	return 1;
}




sPedido* cli_new_Pedido()
{
	return malloc(sizeof(sPedido));
}

void ped_deletePedido(sPedido* this)
{
	free(this);
}

int ped_setIdCliente(sPedido* this,int idCliente)
{
	int retorno = -1;

	if(this!=NULL && isValidIdCliente(idCliente))
	{
		idCliente = this->idClienteP ;
		retorno = 0;
	}
	return retorno;
}

int ped_getIdCliente(sPedido* this,float kgTotales)
{
	int retorno = -1;

	if(this!=NULL)
	{
		this->idClienteP = kgTotales;
		retorno = 0;
	}
	return retorno;
}

int ped_setkgTotales(sPedido* this,float kgTotales)
{
	int retorno = -1;

	if(this!=NULL && isValidKgTotales(kgTotales))
	{
		this->kgTotales = kgTotales;
		retorno = 0;
	}
	return retorno;
}

int ped_getkgTotales(sPedido* this,float kgTotales)
{
	int retorno = -1;

	if(this!=NULL)
	{
		this->kgTotales = kgTotales;
		retorno = 0;
	}
	return retorno;
}

int ped_setkgR1(sPedido* this,float kgR1)
{
	int retorno = -1;

	if(this!=NULL && isValidKgR1(kgR1))
	{
		this->kgR1 = kgR1;
		retorno = 0;
	}
	return retorno;
}

int ped_getkgR1(sPedido* this,float kgR1)
{
	int retorno = -1;

	if(this!=NULL)
	{
		this->kgR1 = kgR1;
		retorno = 0;
	}
	return retorno;
}

int ped_setkgR2(sPedido* this,float kgR2)
{
	int retorno = -1;

	if(this!=NULL && isValidKgR2(kgR2))
	{
		this->kgR2 = kgR2;
		retorno = 0;
	}
	return retorno;
}

int ped_getkgR2(sPedido* this,float kgR2)
{
	int retorno = -1;

	if(this!=NULL)
	{
		this->kgR2 = kgR2;
		retorno = 0;
	}
	return retorno;
}

int ped_setkgR3(sPedido* this,float kgR3)
{
	int retorno = -1;

	if(this!=NULL && isValidKgR3(kgR3))
	{
		this->kgR3 = kgR3;
		retorno = 0;
	}
	return retorno;
}

int ped_getkgR3(sPedido* this,float kgR3)
{
	int retorno = -1;

	if(this!=NULL)
	{
		this->kgR3 = kgR3;
		retorno = 0;
	}
	return retorno;
}
/*
sPedido cli_new_ClienteParametros(int idPedido,int status,int idClienteP,float kgTotales,float kgR1,float kgR2,float kgR3)
{
	sCliente* retorno = NULL;
	sCliente* this;
	this = cli_new_Cliente();

	if(this!=NULL)
	{
		if(ped_setIdCliente(this,nombre)==0 &&
				ped_setkgR1(this,direccion)==0 &&
				ped_setkgR2(this,cuit)==0 &&
				ped_setkgR3(this,localidad)==0 &&
				ped_setkgTotales()(this,localidad)==0)
			retorno = this;
		else
			cli_deleteCliente(this);//funcion delete persona
	}
	return *retorno;
}
*/
