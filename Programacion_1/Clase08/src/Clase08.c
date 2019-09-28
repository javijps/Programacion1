/*
 ============================================================================
 Name        : Clase08.c
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
#define QTY_EMPLEADOS 10
#define QTY_NOMBRES 10
#define QTY_CARACTERES 50
#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1

struct sEmpleado
{
	int idEmpleado;
	int status;
	//***************
	char nombre[50];
	char apellido[50];
};



int ordenaArrayEmpleados(struct sEmpleado *aEmpleado, int cantidad);
int imprimirArrayEmpleados(struct sEmpleado *aEmpleado, int cantidad);
int getString(	char *pResultado,
				char *pMensaje,
				char *pMensajeError,
				int minimo,
				int maximo,
				int reintentos);



int main(void)
{

	struct sEmpleado aEmpleados[1000];
	struct sEmpleado bEmpleado;
	int i;
	int idEmpleado = 0;

	for(i=0;i<3;i++){

		getString(bEmpleado.nombre,"Ingrese el nombre",
				"ERROR", 1, 49, 2);

		getString(bEmpleado.apellido,"Ingrese el apellido",
						"ERROR", 1, 49, 2);

		bEmpleado.idEmpleado = idEmpleado;
		idEmpleado++;
		bEmpleado.status = STATUS_NOT_EMPTY;

		aEmpleados[i] = bEmpleado;
	}
	imprimirArrayEmpleados(aEmpleados,3);
	ordenaArrayEmpleados(aEmpleados, 3);
	imprimirArrayEmpleados(aEmpleados,3);

	return EXIT_SUCCESS;
}

int imprimirArrayEmpleados(struct sEmpleado *aEmpleado, int cantidad){
	int i;
	int retorno = -1;
	if(aEmpleado != NULL && cantidad>0)
	{
		retorno = 0;
		for(i=0;i<cantidad;i++)
		{
			printf("Id: %d - Nombre: %s - Apellido: %s \n",aEmpleado[i].idEmpleado,aEmpleado[i].nombre,aEmpleado[i].apellido);
		}
	}
	return retorno;
}

int ordenaArrayEmpleados(struct sEmpleado *aEmpleado, int cantidad){
	int i;
	int retorno = -1;
	struct sEmpleado bBuffer[1000];
	int fSwap;
	if(aEmpleado != NULL && cantidad>0)
	{
		retorno = 0;
		do
		{
			fSwap = 0;
			for(i=0;i<cantidad-1;i++)
			{
				if(strcmp(aEmpleado[i].nombre,aEmpleado[i+1].nombre)>0)
				{
					fSwap = 1;
					bBuffer[i] = aEmpleado[i];
					aEmpleado[i] = aEmpleado[i+1];
					aEmpleado[i+1] = bBuffer[i];
				}
			}
		}while(fSwap);
	}
	return retorno;
}

int getString(	char *pResultado,
				char *pMensaje,
				char *pMensajeError,
				int minimo,
				int maximo,
				int reintentos)
{
	int retorno = -1;
	char buffer[4096];
	if(	pResultado != NULL &&
		pMensaje != NULL &&
		pMensajeError != NULL &&
		minimo <= maximo &&
		reintentos >= 0)
	{
		do
			{
				printf("%s",pMensaje);
				__fpurge(stdin);
				fgets(buffer,sizeof(buffer),stdin);
				buffer[strlen(buffer)-1] = '\0';
				if(strlen(buffer)>=minimo && strlen(buffer) <= maximo)
				{
					strncpy(pResultado,buffer,maximo+1);
					retorno = 0;
				 	break;
				}
				printf("%s",pMensajeError);
				reintentos--;
			}while(reintentos >= 0);
	}
	return retorno;
}

int ordenaArrayEmpleadosApellido(struct sEmpleado *aEmpleado,struct sEmpleado *aEmpleado, int cantidad){
	int i;
	int retorno = -1;
	struct sEmpleado bBuffer[1000];
	int fSwap;
	if(aEmpleado != NULL && cantidad>0)
	{
		retorno = 0;
		do
		{
			fSwap = 0;
			for(i=0;i<cantidad-1;i++)
			{
				if(strcmp(aEmpleado[i].nombre,aEmpleado[i+1].nombre)>0)
				{
					fSwap = 1;
					bBuffer[i] = aEmpleado[i];
					aEmpleado[i] = aEmpleado[i+1];
					aEmpleado[i+1] = bBuffer[i];
				}
				else if(strcmp(aEmpleado[i].nombre,aEmpleado[i+1].nombre)==0)//devuelve cero?
				{
					if(strcmp(aEmpleado[i].apellido,aEmpleado[i+1].apellido)>0)
					{
						fSwap = 1;
						bBuffer[i] = aEmpleado[i];
						aEmpleado[i] = aEmpleado[i+1];
						aEmpleado[i+1] = bBuffer[i];
					}
				}
			}
		}while(fSwap);
	}
	return retorno;
}
