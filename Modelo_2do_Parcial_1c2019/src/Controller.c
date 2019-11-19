/*
 * Controller.c
 *
 *  Created on: 18 nov. 2019
 *      Author: javijps
 */
#include "Controller.h"
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Venta.h"
#include "Parser.h"



int controller_loadFromText(char* path , LinkedList* pArrayListVenta)
{
	int retorno = -1;
	FILE* pFile;
	pFile = fopen(path,"r");

	if(pFile!=NULL &&
			pArrayListVenta!=NULL &&
			parser_VentaFromText(pFile,pArrayListVenta)==0)
	{
		retorno = 0;
		printf("\nArchivo cargado!\n");
		fclose(pFile);
	}
	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario). Si no existe, lo crea
 *
 * \param path char*
 * \param pArrayListVenta LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListVenta)
{
	int retorno = -1;
	FILE* pFile;

	pFile = fopen(path,"rb");
	if(pFile!=NULL)
	{
		if(pArrayListVenta!=NULL &&
		   ll_len(pArrayListVenta)==0 &&
		   parser_VentaFromBinary(pFile,pArrayListVenta)==0)
		{
			retorno = 0;
			printf("Archivo cargado!\n");
		}
		fclose(pFile);
	}
	else
		printf("Archivo inexistente!\n");

	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListVenta LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListVenta)
{
	int retorno = -1;
	FILE* pFile;
	int lenLL;
	int i;
	Venta* pVenta;

	pFile = fopen(path,"w");
	lenLL = ll_len(pArrayListVenta);
	if(pFile!=NULL && pArrayListVenta!=NULL && lenLL>0)
	{
		fprintf(pFile,"Id,Nombre,HorasTrabajadas,Sueldo\n");
		for(i=0;i<lenLL;i++)
		{
			pVenta = ll_get(pArrayListVenta,i);
			if(pVenta!=NULL)
			{
//				fprintf(pFile,"%d,%s,%d,%d\n",
////						pVenta->id,
////						pVenta->nombre,
////						pVenta->horasTrabajadas,
////						pVenta->sueldo
//						);

				retorno = 0;
			}
			else
				break;
		}
		printf("Informacion guardada!\n");
	}
	else
		printf("No fue posible guardar la informacion!\n");
	fclose(pFile);
	return retorno;

}
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListVenta LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListVenta)
{
	int retorno = -1;
	FILE* pFile;
	int lenLL;
	int i;
	Venta* pVenta;

	pFile = fopen(path,"wb");
	lenLL = ll_len(pArrayListVenta);

	if(pFile!=NULL && pArrayListVenta!=NULL && lenLL>0)
	{
		for(i=0;i<lenLL;i++)
		{
			pVenta = ll_get(pArrayListVenta,i);

			if(pVenta!=NULL)
			{
				fwrite(pVenta,sizeof(Venta),1,pFile);
				retorno = 0;
			}
		}
		printf("Informacion guardada!\n");
		fclose(pFile);
	}
	else
		printf("No fue posible guardar la informacion!\nArchivo Inexistente!\n");
	return retorno;
}


/** \brief Listar ventas
 *
 * \param path char*
 * \param pArrayListVenta LinkedList*
 * \return int
 *
 */
int controller_ListVenta(LinkedList* pArrayListVenta)
{
	int retorno=-1;
	int i;
	int lenLL;
	Venta* pVenta;

	lenLL = ll_len(pArrayListVenta);
	if(pArrayListVenta!=NULL && lenLL>0)
	{
		for(i=0;i<lenLL;i++)
		{
			pVenta = ll_get(pArrayListVenta,i);
			printf("ID Venta: %d     Status: %4d     Fecha Venta %10s   Tipo Foto: %15s"
					"        Cantidad: %3d     Precio Unitario: %.2f   Cuit Cliente: %15s\n",
					pVenta->ID_Venta,pVenta->Status,pVenta->Fecha_Venta,pVenta->Tipo_Foto,pVenta->Cantidad,pVenta->Precio_Unitario
					,pVenta->CUIT_Cliente);
			retorno = 0;
		}
	}
	else
		printf("No fue posible imprimir la informacion!\n");
	return retorno;
}



/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListVenta LinkedList*
 * \return int
 *
 */
int controller_generarInformes(char* path , LinkedList* pArrayListVenta)
{
	int retorno = -1;
	FILE* pFile;
	int lenLL;
//	int cantidadFototsReveladas;

	pFile = fopen(path,"w");
	lenLL = ll_len(pArrayListVenta);

	//grabarinfo(char* path , LinkedList* pArrayListVenta)
	if(pFile!=NULL && pArrayListVenta!=NULL && lenLL>0)
	{
//		cantidadFototsReveladas = venta_total_fotos_reveladas(pArrayListVenta);
//		if(cantidadFototsReveladas>0)
//		{
//			fprintf(pFile,"- Cantidad de fotos reveladas totales: %d\n",cantidadFototsReveladas);
//			retorno = 0;
//			printf("Informacion guardada!\n");
//		}
//		else
//			return -1;

		//funcion2

		if(controller_grabarInfo(pFile,pArrayListVenta)!=0)
		{
			return -1;
		}
	}
	else
		printf("No fue posible guardar la informacion!\n");
	fclose(pFile);
	return retorno;

}


int controller_grabarInfo(FILE* pFile, LinkedList* pArrayListVenta)
{
	int retorno = -1;
	int cantidadFototsReveladas;
	int cantidadMontoMayorA150;
	int cantidadMontoMayorA300;
	int cantidadFotosPolaroid;

	cantidadFototsReveladas = venta_total_fotos_reveladas(pArrayListVenta);
	cantidadMontoMayorA150 = venta_mayor150(pArrayListVenta);
	cantidadMontoMayorA300 = venta_mayor300(pArrayListVenta);
	cantidadFotosPolaroid = venta_esPolaroid(pArrayListVenta);
	if(cantidadFototsReveladas>0 && cantidadMontoMayorA150>=0 && cantidadMontoMayorA300>=0 && cantidadFotosPolaroid>=0)
	{
		fprintf(pFile,"- Cantidad de fotos reveladas totales: %d\n",cantidadFototsReveladas);
		fprintf(pFile,"- Cantidad de ventas por un monto mayor a $150: %d\n",cantidadMontoMayorA150);
		fprintf(pFile,"- Cantidad de ventas por un monto mayor a $300: %d\n",cantidadMontoMayorA300);
		fprintf(pFile,"- Cantidad de fotos POLAROID totales: %d\n",cantidadFotosPolaroid);
		retorno = 0;
		printf("Informacion guardada!\n");
	}
	else
		return -1;
	return retorno;
}
