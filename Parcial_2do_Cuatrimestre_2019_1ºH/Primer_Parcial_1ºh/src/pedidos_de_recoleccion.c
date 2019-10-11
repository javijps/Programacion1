/*
 * pedidos_de_recoleccion.c
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "pedidos_de_recoleccion.h"
#define STATUS_EMPTY -1
#define STATUS_PENDIENTE 0
#define STATUS_COMPLETADO 1



/**
* \brief Imprime la informacion correspondiente a pedidos
* \param pedidos *aPedidos puntero a una array de estructuras pedidos.
* \param len Cantidad del array a imprimir
* \return Si tuvo exito al imprimir devuelve [0] o si fallo [-1]
*/
int imprimirPedidosActivos(pedidoCliente *aPedido, int len){

	int i;
	int retorno = -1;
	if(aPedido != NULL && len>0)
	{
		retorno = 0;
		for(i=0;i<len;i++)
		{
			if(aPedido[i].statusPedido==STATUS_EMPTY)
				continue;
			printf("Id Pedido: %d\n"
					"Id Cliente: %d\n"
					" - Status Pedido: %d\n"
					" - Kilos totales: %d\n"
					" - kg HDPE: %d\n"
					" - kg LDPE: %d\n"
					" - kg PP: %d\n",
					aPedido[i].id_pedido,
					aPedido[i].idCliente,
					aPedido[i].statusPedido,
					aPedido[i].kgTotalesArecolectar,
					aPedido[i].kgHDPE,
					aPedido[i].kgLDPE,
					aPedido[i].kgPP);

		}
	}
	return retorno;
}

/**
* \brief Genera el ID correspondiente a una pedido.
* \return Devuelve el ID correspondiente.
*/
static int generarIdpedido(void){
	static int id = 0;
	id++;
	return id;
}

/**
* \brief Inicializa los pedidos con STATUS_EMPTY.
* \param pedidos *apedidos puntero a una xxxxx de la estructura pedidos.
* \param cantidad Cantidad de pedidos a inicializar
* \return Si tuvo exito al inicializar devuelve [0] o si fallo [-1]
*/
int initPedido(pedidoCliente *aPedido, int cantidad)
{

	int i;
	int retorno = -1;

	if(aPedido != NULL && cantidad > 0)
	{
		for(i=0;i<cantidad;i++)
		{
			aPedido[i].statusPedido = STATUS_EMPTY;
		}
		retorno = 0;
	}
	return retorno;
}

/**
* \brief Solicita los datos correspondientes a una pedido.
* \param pedido *apedido puntero a una xxxxx de la estructura pedido.
* \param cantidad Cantidad de pedido.
* \return Si tuvo exito al completar todos los campos devuelve [0] o si fallo [-1]
*/
int getDatosPedido(pedidoCliente *aPedido,int cantidad){

	int retorno = -1;
	pedidoCliente bPedidoCliente;
	int i;

	for(i=0;i<cantidad;i++)
	{

		if(getInt(&bPedidoCliente.idCliente,"Ingrese id del cliente\n","Id incorrecto!\n",1,100,2)!=0)
			break;
		if(getInt(&bPedidoCliente.kgTotalesArecolectar,"Ingrese la cantidada de kg totales a recolectar\n","Id incorrecto!\n",1,100,3)!=0)
				break;
		aPedido[i].idCliente = bPedidoCliente.idCliente;
		aPedido[i].kgTotalesArecolectar = bPedidoCliente.kgTotalesArecolectar;
		aPedido[i].statusPedido = STATUS_PENDIENTE;
		aPedido[i].id_pedido = generarIdpedido();

		retorno = 0;
	}
	return retorno;
}

/**
* \brief Busca una pedido sin datos cargados.
* \param pedidoCLiente *acliente puntero a una xxxxx de la estructura pedido.
* \param cantidad Cantidad de pedido.
* \return Si tuvo exito al encontrar un pedido vacio devuelve [0] o si fallo [-1]
*/
int buscarPedidoLibre(pedidoCliente *aPedido,int cantidad)
{
	int retorno = -1;
	int i;

	if(aPedido != NULL && cantidad > 0)
	{
		for(i=0;i<cantidad;i++)
		{
			if(aPedido[i].statusPedido==STATUS_EMPTY)
				return i;
		}
	}
	return retorno;
}

/**
* \brief Realiza el alta de una nueva pedido.
* \param pedidoCliente *aPedido puntero a un array de estructuras pedido.
* \param cantidad Cantidad de altas a realizar.
* \return Si tuvo exito al realizar el alta devuelve [0] o si fallo [-1]
*/
int altaPedido(pedidoCliente *aPedido, int cantidad)
{

	int retorno = -1;
	int index=0;

	if(aPedido != NULL && cantidad>0)
	{
		index = buscarPedidoLibre(aPedido,cantidad);

		if(index!=-1)
		{
			if(getDatosPedido(aPedido,cantidad)==0)
				retorno = 0;
		}
	}
	return retorno;
}

/**
* \brief Busca una pedido en estado pendiente existente por medio de su ID.
* \param pedidoCliente *aPedido puntero a un array de la estructura pedidoCliente.
* \param cantidad Cantidad de pedidos.
* \param id ID de pedido a ser encontrado.
* \return Si tuvo exito al encontrar el pedido indicada devuelve [0] o si fallo [-1]
*/
int buscarPedidoPorId(pedidoCliente *aPedido,int cantidad, int id)
{
	int retorno = -1;
	int i;

	if(aPedido!=NULL && cantidad>0)
	{
		for(i=0;i<cantidad;i++)
		{
			if(aPedido[i].id_pedido == id && aPedido[i].statusPedido == STATUS_PENDIENTE)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/**
* \brief procesa el pedido de recolleccion de residuos para pasar de pendiente a completado
* \param pedidoCliente *aPedido puntero a un array de estructuras pedido.
* \param cantidad Cantidad de altas a realizar.
* \return Si tuvo exito al realizar el alta devuelve [0] o si fallo [-1]
*/
int procesarResiduos(pedidoCliente *aPedido, int cantidad,int idPedido)
{
	int retorno = -1;
	pedidoCliente bPedido;
	int index;
	int opcion;
	int sumaKilaje;

	index = buscarPedidoPorId(aPedido,cantidad,idPedido);

	if(index!=-1)
	{
		do
		{
			if(getInt(&opcion,"\nIngrese: \n1-Cargar kg  del residuo HDPE.\n"
					"2-Cargar kg  del residuo LDPE.\n"
					"3-Cargar kg  del residuo kgPP.\n \n"
					"4-EXIT\n",
					"Error, opcion incorrecta\n",
					1,4,2)==0)
			{
				switch(opcion)
				{
				case 1:
					if(getInt(&bPedido.kgHDPE,"Ingresar kg  del residuo HDPE\n",
							"kilaje incorrecto, maximo 1000kg\n",
							1,1000,2)==0)
					{
						aPedido[index].kgHDPE = bPedido.kgHDPE;
						retorno = 0;
					}
					break;
				case 2:
					if(getInt(&bPedido.kgLDPE,"Ingresar kg  del residuo LDPE\n",
							"kilaje incorrecto, maximo 1000kg\n",
							1,1000,2)==0)
					{
						aPedido[index].kgLDPE = bPedido.kgLDPE;
						retorno = 0;
					}

					break;
				case 3:
					if(getInt(&bPedido.kgPP,"Ingresar kg  del residuo PP\n",
							"kilaje incorrecto, maximo 1000kg\n",
							1,1000,2)==0)
					{
						aPedido[index].kgPP = bPedido.kgPP;
						retorno = 0;
					}
					break;
				}
			}/*
			sumaKilaje = (bPedido.kgHDPE + bPedido.kgLDPE + bPedido.kgPP);
			if(sumaKilaje>aPedido[index].kgTotalesArecolectar)
			{
				printf("Los kilos ingresados son mayores a los kilos totales a recolectar!!");
				retorno=-2;
			}*/

		}while(opcion!= 3);
	}

	return retorno;
}

