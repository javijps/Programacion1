/*
 * clase11.c
 *
 *  Created on: 24 sep. 2019
 *      Author: alumno
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "clase11.h"
#define EMPTY 0
#define NOT_EMPTY 1

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

int imprimirArrayEstructura(struct estructura *aestructura, int cantidad){
	int i;
	int retorno = -1;
	if(aestructura != NULL && cantidad>0)
	{
		retorno = 0;
		for(i=0;i<cantidad;i++)
		{
			printf("Id: %d - Nombre: %s \n",aestructura[i].idEstructura,aestructura[i].nombreEstructura);
		}
	}
	return retorno;
}

int initLugarLibreEstructura(struct estructura *aestructura, int cantidad,int valor){

	int i;
	int retorno = -1;

	if(aestructura != NULL && cantidad > 0)
	{
		retorno = 0;

		for(i=0;i < cantidad; i++)
		{
			aestructura[i].idEstructura = valor;
		}
	}
	return retorno;
}

int buscarPrimerOcurrencia(struct estructura aestructura[],int cantidad,int valor)
{
    int i;
    for(i=0;i < cantidad; i++)
    {
        if(aestructura[i].idEstructura == valor)//corregir id Empleado x array generico
        {
            return i;
        }
    }
    return -1;
}

int buscarEstructuraPorId(struct estructura *aestructura, int cantidad,int id)
{
	int i;
	    for(i=0;i < cantidad; i++)
	    {
	        if(aestructura[i].idEstructura == id)
	        {
	            return i;
	        }
	    }
	    return -1;
}

int bajaEstructuraPorId(struct estructura *aestructura, int cantidad,int id)
{
	int retorno = -1;
	int resultado;

	resultado = buscarEstructuraPorId(aestructura,cantidad,id);
	if(resultado!=-1)
	{
		retorno = 0;
		aestructura[resultado].status  = EMPTY;

	}
	return retorno;
}
/*
//array a modificar, id del estruct a modificar bestruct para usar de buffer
int modificarEestructuraPorId(struct estructura *aestructura, int cantidad,int id, struct bEstruct)
{
	int retorno = -1;
	int index;
	char opcion;
	void buffer_1;
	void buffer_2;
	void buffer_3;

	//getInt da el id
	index = buscarEstructuraPorId(aestructura,cantidad,id);
	if(index!=-1)
	{
		retorno = 0;
		/*
		printf("Que campo desea modificar?");
					__fpurge(stdin);
					scanf("%s",&opcion);
					switch(opcion)
					{
					case "campo_1":
						/*if(funcion que toma el dato del campo 1, almacena en buffer_1)==1)
						 {
						      bestruct.campo_1 = buffer_1;
						      aestructura.campo_1 = bEstruct.campo_1
						 }


					case "campo_2":
						/*if(funcion que toma el dato del campo 2, almacena en buffer_2)==1)
					    {
						      bestruct.campo_2 = buffer_2;
						      aestructura.campo_2 = bestruct.campo_2
						}

					case "campo_3":
						/*if(funcion que toma el dato del campo 3, almacena en buffer_3)==1)
						{
							  bestruct.campo_3 = buffer;
							  aestructura.campo_3 = bestruct.campo_3
						}

					}*/
	//}


	//return retorno;
//}

/*int modificarAlumnoPorId(struct alumno *aestructura, int cantidad,int id, int index)
{
	int retorno = -1;
	char datoAmodificar;
	char opcion;
	struct alumno bAlumno;

	//getInt da el id
	//encapsular en do while
	index = buscarEstructuraPorId(aestructura,cantidad,id);
	if(index!=-1)
	{
		retorno = 0;

		printf("Que campo desea modificar?");
		__fpurge(stdin);
		scanf("%s",&opcion);
		switch(opcion)
		{
		case "a":
			getString(bEmpleado.nombre,"Ingrese Nombre","Error",1,150,3)
			strncpy(aestructura[index].nombre,bEmpleado.nombre,50);
			retorno = 0;
			break;

	}
	}


	return retorno;
}
*/
