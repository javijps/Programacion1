#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Cachorro.h"
#include "parser.h"



//MODIFICAR LOS DATOS PARA ADAPTARLO A LA ESTRUCTURA NUEVA

/* * brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListsCachorro(LinkedList* pArrayListsCachorro)
{
	int retorno=-1;
	int i;
	int lenLL;
	sCachorro* bCachorro;

	lenLL = ll_len(pArrayListsCachorro);
	if(pArrayListsCachorro!=NULL && lenLL>0)
	{
		for(i=0;i<lenLL;i++)
		{
			bCachorro = ll_get(pArrayListsCachorro,i);
			printf("\nID: %5d  Nombre: %15s Dias: %5d Raza: %15s Reservado: %5s Genero: %15s\n",
					bCachorro->ID_Cachorro,
					bCachorro->nombre,
					bCachorro->dias,
					bCachorro->raza,
					bCachorro->reservado,
					bCachorro->genero);
			retorno = 0;
		}
	}
	else
		printf("No fue posible imprimir la informacion!\n");
	return retorno;
}





/** \brief Carga los datos de los Cachorros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListsCachorro LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListsCachorro)//MENSAJE ACA EN LUGAR DEL MAIN?
{
	int retorno = -1;
	FILE* pFile;
	pFile = fopen(path,"r");

	if(pFile!=NULL &&
			pArrayListsCachorro!=NULL &&
			parser_sCachorroFromText(pFile,pArrayListsCachorro)==0)
	{
		retorno = 0;
		printf("Archivo cargado!\n");
		fclose(pFile);
	}
	else
		printf("No fue posible cargar el archivo\n");
	return retorno;
}


/** \Filtra los cachorros por dias
 *
 * \param path char*
 * \param  LinkedList*
 * \return int
 *
 */
int controller_Filter45(LinkedList* pArrayListsCachorro)
{
	LinkedList* lista_Filtrada = NULL;
	int retorno=-1;
	int lenLL;

	lenLL = ll_len(pArrayListsCachorro);
	if(pArrayListsCachorro!=NULL && lenLL>0)
	{
		lista_Filtrada = ll_filter(pArrayListsCachorro,cachorro_filtersCachorroByDias);//1 y 0 desc
		if(lista_Filtrada!=NULL)
		{
			controller_ListsCachorro(lista_Filtrada);
			controller_saveAsText("cachorros45dias.csv",lista_Filtrada);
			retorno = 0;
		}
	}
	else
	{
		printf("No existen datos cargados a filtrar!\n");
	}
	return retorno;
}


/** \brief Guarda los datos de los empleados en el archivo  tipo csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListsCachorro)
{
	int retorno = -1;
	FILE* pFile;
	int lenLL;
	int i;
	sCachorro* bCahorro;

	pFile = fopen(path,"w");
	lenLL = ll_len(pArrayListsCachorro);
	if(pFile!=NULL && pArrayListsCachorro!=NULL && lenLL>0)
	{
		fprintf(pFile,"ID_Cachorro,Nombre,Dias,Raza,Reservado,Genero\n");
		for(i=0;i<lenLL;i++)
		{
			bCahorro = ll_get(pArrayListsCachorro,i);
			if(bCahorro!=NULL)
			{
				fprintf(pFile,"%d,%s,%d,%s,%s,%s\n",
						bCahorro->ID_Cachorro,
						bCahorro->nombre,
						bCahorro->dias,
						bCahorro->raza,
						bCahorro->reservado,
						bCahorro->genero);
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


/** \Filtra los cachorros por genero
 *
 * \param path char*
 * \param  LinkedList*
 * \return int
 *
 */
int controller_FilterMachos(LinkedList* pArrayListsCachorro)
{
	LinkedList* lista_Filtrada = NULL;
	int retorno=-1;
	int lenLL;

	lenLL = ll_len(pArrayListsCachorro);
	if(pArrayListsCachorro!=NULL && lenLL>0)
	{
		lista_Filtrada = ll_filter(pArrayListsCachorro,cachorro_filtersCachorroByGenero);//1 y 0 desc
		if(lista_Filtrada!=NULL)
		{
			controller_ListsCachorro(lista_Filtrada);
			controller_saveAsText("cachorrosMachos.csv",lista_Filtrada);
			retorno = 0;
		}
	}
	else
	{
		printf("No existen datos cargados a filtrar!\n");
	}
	return retorno;
}

/** \Filtra los cachorros por callejero
 *
 * \param path char*
 * \param  LinkedList*
 * \return int
 *
 */
int controller_FilterCallejeros(LinkedList* pArrayListsCachorro)
{
	LinkedList* lista_Filtrada = NULL;
	int retorno=-1;
	int lenLL;

	lenLL = ll_len(pArrayListsCachorro);
	if(pArrayListsCachorro!=NULL && lenLL>0)
	{
		lista_Filtrada = ll_filter(pArrayListsCachorro,cachorro_filtersCachorroByCallejero);//1 y 0 desc
		if(lista_Filtrada!=NULL)
		{
			controller_ListsCachorro(lista_Filtrada);
			controller_saveAsText("cachorrosCallejeros.csv",lista_Filtrada);
			retorno = 0;
		}
	}
	else
	{
		printf("No existen datos cargados a filtrar!\n");
	}
	return retorno;
}
