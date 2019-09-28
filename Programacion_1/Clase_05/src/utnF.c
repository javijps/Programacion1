
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "utnF.h"
#define EXIT_ERROR -1

int getInt(  int *pResultado,
		     char *mensaje,
			 char *mensajeError,
			 int minimo,
			 int maximo,
			 int reintentos)
{
	int retorno = EXIT_ERROR;
	int buffer;

	if( pResultado != NULL &&
		mensaje != NULL &&
		mensajeError != NULL &&
		minimo < maximo &&
		reintentos > 0)
	{
		do
		{
			printf("%s",mensaje);
			__fpurge(stdin);
			if(scanf("%d",&buffer)==1)
			{
				if(buffer >= minimo && buffer <= maximo)
				{
					retorno = EXIT_SUCCESS;
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



