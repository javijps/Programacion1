/*
 ============================================================================
 Name        : ParcialPantallasyPublicaciones.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "Pantallas.h"
#include "Publicidades.h"
#include "utn.h"
#define QTY_PANTALLAS 100
#define CONTRATACIONES 1000

int main(void) {
//2. Cliente con importe más alto a facturar (si hay más de uno indicar el primero)

//como publicidad tiene a pantalla, recorro 1ro publicidad, xq tengo el ID de pantalla.. pantalla tiene el precio

	int mayorPrecioFacturado(pantalla *listPantalla, int lenPantalla, publicidad *listPublicidad,int lenPublicidad)
	{
		int retorno = -1;
		int i;
		int j;
		int posicionPantalla;
		int precioTotalPublicacion;
		struct sCliente bCliente;


		if((listPantalla!=NULL && lenPantalla>0) && (listPublicidad!=NULL && lenPublicidad>0))
		{
			for(i=0;i<lenPublicidad;i++)//con posicionPantalla macheo el id pantalla de la publicacion, con la pantalla de ese id. es la conexion
			//despues calculo el precio de esa publicidad
			{
				posicionPantalla = buscarPantallaPorId(listPantalla,lenPantalla,listPublicidad[i].idPantalla);
				precioTotalPublicacion = listPublicidad[i].diasPublicacion * listPantalla[posicionPantalla].precioPorDia;

			}
			//faltaria acumular
		}
		return retorno;
	}

//if cuit es igual, acumulo la facturacion
	return EXIT_SUCCESS;

}


