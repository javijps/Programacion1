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


/**
* \brief Imprime el array correspondiente al campo de una estructura
* \param *aestructura array a ser impreso.
* \param cantidad Limite del array
* \return Si tuvo exito al imprimir el array [0] o si fallo [-1]
*/
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

/**
* \brief Inicializa array correspondiente a una estructura.
* \param *aestructura array a ser inicializado.
* \param cantidad Limite del array
* \return Si tuvo exito al inicializar el array [0] o si fallo [-1]
*/
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

/**
* \brief Busca en array correspondiente a una estructura una primer ocurrencia.
* \param *aestructura array en el que la funcion buscara.
* \param cantidad Limite del array
* \param valor Valor de la ocurrencia.
* \return Si tuvo exito al buscar la ocurrencia [0] o si fallo [-1]
*/
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
/**Puede usarse 1er ocurrencia con id como valor?
* \brief Busca el id de la estructura correspondiente
* \param *aestructura array en el que la funcion buscara.
* \param cantidad Limite del array
* \param id Id a encontrar.
* \return Si tuvo exito al buscar el ID [0] o si fallo [-1]
*/
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

/**
* \brief Realiza una baja logica del "objeto" del tipo estructura señalada por medio del ID
* \param *aestructura array en el que la funcion buscara PARA REALIZAR LA BAJA.
* \param cantidad Limite del array
* \param id Id a encontrar.
* \return Si tuvo exito al buscar al dar la baja [0] o si fallo [-1]
*/
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

//array a modificar, id del estruct a modificar bestruct para usar de buffer

int modificarEstructuraPorId(struct estructura *aestructura, int cantidad,int id, int index)
{
	int retorno = -1;
	char opcion;
	struct estructura bEstructura;

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
		case 'a':
			getString(bEstructura.nombreEstructura,"Ingrese Nombre","Error",1,150,3);
			strncpy(aestructura[index].nombreEstructura,bEstructura.nombreEstructura,50);
			retorno = 0;
			break;

	}
	}


	return retorno;
}

int altaArrayEstructuraPorID(struct estructura *aestructura, int cantidad, int id)
{

	int retorno = -1;
	int index;
	/*1 buffer para cada campo de la estructura*/

	index = buscarPrimerOcurrencia(aestructura,cantidad,-1);

	if(index!=-1)
	{
		retorno = 0;
		//getDatosInputEstructura()ej datos de empleado
		//tomo todos los datos y los guardo en los buffer
		//paso los datos de buffer al elemento en el que voy  a dar el alta
		//retorno error en caso de no realizarlo

	}
	return retorno;
}

int ordenarArrayEstructura(struct estructura *aestructura, int cantidad)//cambiar por insert
{
	int i;
	int retorno = -1;
	struct estructura bBuffer[1000];
	int fSwap;
	if(aestructura != NULL && cantidad>0)
	{
		retorno = 0;
		do
		{
			fSwap = 0;
			for(i=0;i<cantidad-1;i++)
			{
				if(strcmp(aestructura[i].nombreEstructura,aestructura[i+1].nombreEstructura)>0)
				{
					fSwap = 1;
					bBuffer[i] = aestructura[i];
					aestructura[i] = aestructura[i+1];
					aestructura[i+1] = bBuffer[i];
				}
			}
		}while(fSwap);
	}

	return retorno;
}


