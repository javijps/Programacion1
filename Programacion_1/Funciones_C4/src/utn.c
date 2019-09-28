/*
 * utn.c
 *
 *  Created on: 2 sep. 2019
 *      Author: Javi
 */

#include <stdio.h>
//#include stdio_ext.h
#include <stdlib.h>

int getInt(int *pResultado,
		   char *mensaje,
		   char *mensajeError,
		   int minimo,
		   int maximo,
		   int reintentos)

{
	int retorno=-1;
	int buffer;
	if(  pResultado != NULL &&
		 mensaje != NULL &&
		 mensajeError != NULL &&
		 minimo < maximo &&
		 reintentos >=0)
	{

		do{
			printf("%s",mensaje);
			fflush(stdin);
			if(scanf("%d",&buffer)==1)
			{
				if(buffer >= minimo && buffer <=maximo)
				{
					retorno = 0;
					*pResultado = buffer;
					break;
				}
			}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos>0);


	}
	return retorno;
}

int getFloat(float *pResultado,
		   char *mensaje,
		   char *mensajeError,
		   int minimo,
		   int maximo,
		   int reintentos)

{
	int retorno=-1;
	float buffer;
	if(  pResultado != NULL &&
		 mensaje != NULL &&
		 mensajeError != NULL &&
		 minimo < maximo &&
		 reintentos >=0)
	{

		do{
			printf("%s",mensaje);
			fflush(stdout);
			if(scanf("%f",&buffer)==1)
			{
				if(buffer >= minimo && buffer <=maximo)
				{
					retorno = -1;
					*pResultado = buffer;
					break;
				}
			}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos>=0);


	}
	return retorno;
}
