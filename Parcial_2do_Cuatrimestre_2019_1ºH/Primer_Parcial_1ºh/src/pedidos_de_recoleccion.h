/*
 * pedidos_de_recoleccion.h
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#ifndef PEDIDOS_DE_RECOLECCION_H_
#define PEDIDOS_DE_RECOLECCION_H_

typedef struct {

	int id_pedido;
	int statusPedido;
	int idCliente;
	int kgTotalesArecolectar;
	int kgHDPE;
	int kgLDPE;
	int kgPP;


} pedidoCliente;

int imprimirPedidosActivos(pedidoCliente *aPedido, int len);
int getDatosPedido(pedidoCliente *aPedido,int cantidad);
int buscarPedidoLibre(pedidoCliente *aPedido,int cantidad);
int altaPedido(pedidoCliente *aPedido, int cantidad);
int initPedido(pedidoCliente *aPedido, int cantidad);
int buscarPedidoPorId(pedidoCliente *aPedido,int cantidad, int id);
int procesarResiduos(pedidoCliente *aPedido, int cantidad,int idPedido);

#endif /* PEDIDOS_DE_RECOLECCION_H_ */
