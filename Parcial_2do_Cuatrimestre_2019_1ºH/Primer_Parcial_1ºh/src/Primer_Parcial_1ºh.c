/*
 ============================================================================
 Name        : Primer_Parcial_1ºh.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "clientes.h"
#include "pedidos_de_recoleccion.h"

#define MAX_CLIENTES 100
#define MAX_PEDIDOS 1000

int main(void) {

	cliente aCliente[MAX_CLIENTES];
	pedidoCliente aPedido[MAX_PEDIDOS];
	int option;
	int bId;

	initcliente(aCliente,MAX_CLIENTES);
	initPedido(aPedido,MAX_CLIENTES);
	do
	{

		getInt(&option,"\n---------------------\n"
				"Ingrese:\n"
				"1-Alta de cliente\n"
				"2-Modificar datos cliente\n"
				"3-Baja de cliente\n"
				"4-Crear pedido de recoleccion\n"
				"5-Procesar residuos\n"
				"6-\n"
				"7-\n"
				"8-\n"
				"9-EXIT\n",
				"Error\n",1,12,2);

		switch(option)
		{
		case 1:
			if(altaCliente(aCliente,1)!=0)
				printf("Alta no realizada!\n");
			imprimirClientesActivos(aCliente,5);
			break;
		case 2:
			if(getInt(&bId,"Ingrese ID de cliente","Error id",1,100,2)==0)
			{
				if(modificarClientePorId(aCliente,MAX_CLIENTES,bId)!=0)
				{
					printf("Modificacion no realizada!");
				}
			}
			imprimirClientesActivos(aCliente,5);
			break;
		case 3:
			if(getInt(&bId,"Ingrese ID de cliente","Error id",1,100,2)==0)
			{
				if(bajaClientePorId(aCliente,MAX_CLIENTES,bId)==0)
				{
					printf("Baja Exitosa!!\n");
				}
			}
			imprimirClientesActivos(aCliente,5);
			break;
		case 4:
			imprimirClientesActivos(aCliente,5);
			if(altaPedido(aPedido,1)!=0)
				printf("Alta fallida\n");
		imprimirPedidosActivos(aPedido,5);
		break;
		case 5:
			imprimirPedidosActivos(aPedido,5);
			if(getInt(&bId,"Ingrese ID de pedido","Error id",1,100,2)==0)
			{
				if(procesarResiduos(aPedido,MAX_PEDIDOS,bId)!=0)
					printf("No fue posible procesar!");
			}
			imprimirPedidosActivos(aPedido,5);
			break;
		}
	}while(option!=9);
	return EXIT_SUCCESS;
}

