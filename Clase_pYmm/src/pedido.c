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

static int isValidIdPedido(int *idPedido)
{
	return 1;
}


static int isValidIdCliente(int *idCliente)
{
	return 1;
}

static float isValidKgTotales(float *kgTotales)
{
	return 1;
}

static float isValidKgR1(float *kgR1)
{
	return 1;
}

static float isValidKgR2(float *kgR2)
{
	return 1;
}

static float isValidKgR3(float *kgR3)
{
	return 1;
}




sPedido* ped_new_Pedido()
{
	return malloc(sizeof(sPedido));
}

void ped_deletePedido(sPedido* this)
{
	free(this);
}

int ped_setIdPedido(sPedido* this,int *idPedido)//esta ok
{
	int retorno = -1;

	if(this!=NULL && isValidIdCliente(idPedido))
	{
		this->idClienteP = *idPedido;
		retorno = 0;
	}
	return retorno;
}

int ped_getIdPedido(sPedido* this,int *idPedido)
{
	int retorno = -1;

	if(this!=NULL)
	{
		*idPedido = this->idClienteP ;
		retorno = 0;
	}
	return retorno;
}

int ped_setIdCliente(sPedido* this,int *idCliente)
{
	int retorno = -1;

	if(this!=NULL && isValidIdPedido(idCliente))
	{
		this->idClienteP = *idCliente;
		retorno = 0;
	}
	return retorno;
}

int ped_getIdCliente(sPedido* this,int *idCliente)
{
	int retorno = -1;

	if(this!=NULL)
	{
		*idCliente = this->idClienteP ;
		retorno = 0;
	}
	return retorno;
}
















//CHEQUEAR



int ped_setkgTotales(sPedido* this,float *kgTotales)
{
	int retorno = -1;

	if(this!=NULL&& isValidKgTotales(kgTotales))
	{
		this->kgTotales = *kgTotales;
		retorno = 0;
	}
	return retorno;
}

int ped_getkgTotales(sPedido* this,float *kgTotales)
{
	int retorno = -1;

	if(this!=NULL)
	{
		*kgTotales = this->kgTotales;
		retorno = 0;
	}
	return retorno;
}




int ped_setkgR1(sPedido* this,float *kgR1)
{
	int retorno = -1;

	if(this!=NULL && isValidKgR1(kgR1))
	{
		this->kgR1 = *kgR1;
		retorno = 0;
	}
	return retorno;
}

int ped_getkgR1(sPedido* this,float *kgR1)
{
	int retorno = -1;

	if(this!=NULL)
	{
		*kgR1 = this->kgR1;
		retorno = 0;
	}
	return retorno;
}

int ped_setkgR2(sPedido* this,float *kgR2)
{
	int retorno = -1;

	if(this!=NULL && isValidKgR2(kgR2))
	{
		this->kgR2 = *kgR2;
		retorno = 0;
	}
	return retorno;
}

int ped_getkgR2(sPedido* this,float *kgR2)
{
	int retorno = -1;

	if(this!=NULL)
	{
		*kgR2 = this->kgR2;
		retorno = 0;
	}
	return retorno;
}

int ped_setkgR3(sPedido* this,float *kgR3)
{
	int retorno = -1;

	if(this!=NULL && isValidKgR3(kgR3))
	{
		this->kgR3 = *kgR3;
		retorno = 0;
	}
	return retorno;
}

int ped_getkgR3(sPedido* this,float *kgR3)
{
	int retorno = -1;

	if(this!=NULL)
	{
		*kgR3 = this->kgR3;
		retorno = 0;
	}
	return retorno;
}


sPedido cli_new_PedidoParametros(int *idPedido,int *status,int *idClienteP,float *kgTotales,float *kgR1,float *kgR2,float *kgR3)
{
	sPedido* retorno = NULL;
	sPedido* this;
	this = ped_new_Pedido();

	if(this!=NULL)
	{
		if(ped_setIdCliente(this,idClienteP)==0 &&
				ped_setIdPedido(this,idPedido)==0 &&
				ped_setkgTotales(this,kgTotales)==0 &&
				ped_setkgR1(this,kgR1)==0 &&
				ped_setkgR2(this,kgR2)==0 &&
				ped_setkgR3(this,kgR3)==0)
			retorno = this;
		else
			ped_deletePedido(this);
	}
	return *retorno;
}


