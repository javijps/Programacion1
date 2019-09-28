#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#define QTY_EMPLEADOS 1000

int initArrayInt(int *array[],int limite,int valor)
{
	int i;
	int retorno = -1;
	if(array != NULL && limite > 0)
	{
		retorno = 0;
		for(i=0;i<limite;i++)
		{
			array[i]=valor+i;;
		}

	}
	return retorno;
}

int imprimeArray(int *array[],int limite)
{
	int i;
	int retorno = -1;
	if(array != NULL &&limite >0)
	{
		printf("%d",array[i])
	}
	return retorno;
}

