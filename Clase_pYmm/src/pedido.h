/*
 * pedido.h
 *
 *  Created on: 22 oct. 2019
 *      Author: alumno
 */

#ifndef PEDIDO_H_
#define PEDIDO_H_

typedef struct
{
	int idPedido;
	int status;
	int idClienteP;
	float kgTotales;
	float kgR1;
	float kgR2;
	float kgR3;

}sPedido;

sPedido* cli_new_Pedido();
int ped_setIdCliente(sPedido* this,int idCliente);
int ped_getIdCliente(sPedido* this,float kgTotales);
int ped_getIdCliente(sPedido* this,float kgTotales);

void ped_deletePedido(sPedido* this);


#endif /* PEDIDO_H_ */
