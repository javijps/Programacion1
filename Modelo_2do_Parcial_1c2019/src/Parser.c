/*
 * Parser.c
 *
 *  Created on: 18 nov. 2019
 *      Author: javijps
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Venta.h"


/** \brief Parsea los datos los datos de los ventas desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListVenta LinkedList*
 * \return int
 *
 */
int parser_VentaFromText(FILE* pFile , LinkedList* pArrayListVenta)
{
	int retorno = -1;

	char bId_Venta[1046];
	char bFecha_Venta[1046];
	char bTipo_Foto[1046];
	char bCantidad[1046];
	char bPrecio_Unitario[1046];
	char bCUIT_Cliente[1046];

	int flagCabecera=0;
	Venta* pVenta = NULL;
	int rd;

	if(pFile!=NULL && pArrayListVenta!=NULL)
	{
		while(!feof(pFile))
		{
			rd = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
					    bId_Venta,
					    bFecha_Venta,
						bTipo_Foto,
						bCantidad,
						bPrecio_Unitario,
						bCUIT_Cliente);
			if(rd==6)
			{
				if(flagCabecera==0)
				{
					flagCabecera=1;
					continue;
				}
				else if(flagCabecera!=0 && rd==6)
				{
					pVenta = venta_newParametros(bId_Venta,
							                     bFecha_Venta,
												 bTipo_Foto,
												 bCantidad,
												 bPrecio_Unitario,
												 bCUIT_Cliente);
					if(pVenta!=NULL && ll_add(pArrayListVenta,pVenta)==0)
					{
						retorno = 0;
					}
					else
					{
						retorno = -1;
						break;
					}
				}
			}
		}
	}
	else
		printf("Archivo inexistente\n");
	return retorno;
}

/** \brief Parsea los datos los datos de los ventas desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListVenta LinkedList*
 * \return int
 *
 */
int parser_VentaFromBinary(FILE* pFile , LinkedList* pArrayListVenta)
{
	int retorno = -1;
	Venta* pVenta;
	int cant =0;

	if(pFile!=NULL && pArrayListVenta!=NULL)
	{
		while(!feof(pFile))
		{
		//	pVenta = venta_new();
			cant = fread(pVenta,sizeof(Venta),1,pFile);
			if(cant==1)
			{
				ll_add(pArrayListVenta,pVenta);
				retorno = 0;
			}
		}
	}
	else
		printf("error de lectura");
	return retorno;
}

