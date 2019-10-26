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
void ped_deletePedido(sPedido* this);
int ped_setIdPedido(sPedido* this,int *idPedido);
int ped_getIdPedido(sPedido* this,int *idPedido);
int ped_setIdCliente(sPedido* this,int *idCliente);
int ped_getIdCliente(sPedido* this,int *idCliente);
int ped_setkgTotales(sPedido* this,float *kgTotales);
int ped_getkgTotales(sPedido* this,float *kgTotales);
int ped_setkgR1(sPedido* this,float *kgR1);
int ped_getkgR1(sPedido* this,float *kgR1);
int ped_setkgR2(sPedido* this,float *kgR2);
int ped_getkgR2(sPedido* this,float *kgR2);
int ped_setkgR3(sPedido* this,float *kgR3);
int ped_getkgR3(sPedido* this,float *kgR3);

#endif /* PEDIDO_H_ */
