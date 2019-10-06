/*
 * utn.c
 *
 *  Created on: 23 sep. 2019
 *      Author: javijps
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define MAX_FLOAT 1000
#define QTY_CARACTERES 50
#include <stdio_ext.h>

//HACER FUNCION esNombre

/**
* \brief Solicita numero entero al usuario y lo valida.
* \param pNumero Se carga el numero ingresado.
* \param mensaje Mensaje a ser mostrado.
* \param mensajeError Mensaje a ser mostrado en caso de error.
* \param minimo Limite minimo a validar.
* \param maximo Limite maximo a validar.
* \param reintentos Reintentos permitidos en caso de error.
* \return Si tuvo exito al obtener el numero [0] o si fallo [-1]
*/

int getInt(   int *pNumero,
		      char *mensaje,
			  char *mensajeError,
			  int minimo,
			  int maximo,
			  int reintentos)
{
	int retorno = -1;
	int buffer;

	if(     pNumero != NULL &&
			mensaje != NULL &&
			mensajeError != NULL &&
			minimo < maximo &&
			reintentos>=0)
	{
		do
		{

			printf("%s",mensaje);
			__fpurge(stdin);
			if((scanf("%d",&buffer)==1) && buffer >= minimo && buffer <= maximo)//reemplazar x get
			{
				retorno = 0;
				*pNumero = buffer;
				break;

			}
			printf("%s",mensajeError);
			//__fpurge(stdin)
			reintentos--;
		}while(reintentos >= 0);

	}

	return retorno;
}


/**
* \brief Solicita numero float al usuario y lo valida.
* \param pNumero Se carga el numero ingresado.
* \param mensaje Mensaje a ser mostrado.
* \param mensajeError Mensaje a ser mostrado en caso de error.
* \param minimo Limite minimo a validar.
* \param maximo Limite maximo a validar.
* \param reintentos Reintentos permitidos en caso de error.
* \return Si tuvo exito al obtener el numero [0] o si fallo [-1]
*/
int getFloat(   float *pNumero,
		      char *mensaje,
			  char *mensajeError,
			  int minimo,
			  int maximo,
			  int reintentos)
{
	int retorno = -1;
	float buffer;

	if(     pNumero != NULL &&
			mensaje != NULL &&
			mensajeError != NULL &&
			minimo < maximo &&
			reintentos>=0)
	{
		do
		{

			printf("%s",mensaje);
			__fpurge(stdin);
			if((scanf("%f",&buffer)==1) && buffer >= minimo && buffer <= maximo)
			{
				retorno = 0;
				*pNumero = buffer;
				break;

			}
			printf("%s",mensajeError);
			//__fpurge(stdin)
			reintentos--;
		}while(reintentos >= 0);

	}

	return retorno;
}

/**
* \brief Solicita caracter al usuario y lo valida.
* \param pChar Se carga el caracter ingresado.
* \param mensaje Mensaje a ser mostrado.
* \param mensajeError Mensaje a ser mostrado en caso de error.
* \param minimo Limite minimo a validar.
* \param maximo Limite maximo a validar.
* \param reintentos Reintentos permitidos en caso de error.
* \return Si tuvo exito al obtener el caracter [0] o si fallo [-1]
*/
int getChar(   char *pChar,
		      char *mensaje,
			  char *mensajeError,
			  int minimo,
			  int maximo,
			  int reintentos)
{
	int retorno = -1;
	char buffer;

	if(     pChar != NULL &&
			mensaje != NULL &&
			mensajeError != NULL &&
			minimo < maximo &&
			reintentos>=0)

	{
		do
		{

			printf("%s",mensaje);
			__fpurge(stdin);
			if(scanf("%c",&buffer)==1 &&  buffer >= minimo && buffer <= maximo)
			{
				retorno = 0;
				*pChar = buffer;
				break;

			}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos >= 0);

	}

	return retorno;
}

/**
* \brief Solicita letra al usuario y valida que la misma sea entre 'a' y 'z',tanto mayuscula como minuscula.
* \param pChar Se carga la letra ingresada.
* \param mensaje Mensaje a ser mostrado.
* \param mensajeError Mensaje a ser mostrado en caso de error.
* \param reintentos Reintentos permitidos en caso de error.
* \return Si tuvo exito al obtener la letra [0] o si fallo [-1]
*/
int getLetter(   char *pChar,
		      char *mensaje,
			  char *mensajeError,
			  int reintentos)
{
	int retorno = -1;
	char buffer;
	char minimoLower='a';
	char maximoLower='z';
	char minimoUpper='A';
	char maximoUpper='Z';

	if(     pChar != NULL &&
			mensaje != NULL &&
			mensajeError != NULL &&
			reintentos>=0)

	{
		do
		{

			printf("%s",mensaje);
			__fpurge(stdin);
			if(scanf("%c",&buffer)==1 &&//reemplazar scanf
					((buffer >= minimoLower && buffer <= maximoLower) ||
					(buffer >= minimoUpper && buffer <= maximoUpper)))
			{
				retorno = 0;
				*pChar = buffer;
				break;

			}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos >= 0);

	}

	return retorno;
}
/**
* \brief Solicita  cadena de caracteres al usuario y lo valida.
* \param pResultado Se carga la cadena ingresada.
* \param mensaje Mensaje a ser mostrado.
* \param mensajeError Mensaje a ser mostrado en caso de error.
* \param minimo Limite minimo a validar.
* \param maximo Limite maximo a validar.
* \param reintentos Reintentos permitidos en caso de error.
* \return Si tuvo exito al obtener la cadena [0] o si fallo [-1]
*/
int getString(char *pResultado,
		      char *pMensaje,
			  char *pMensajeError,
			  int minimo,
			  int maximo,
			  int reintentos)
{
	int retorno = -1;
	char buffer[4098];

	if(pResultado != NULL &&
	   pMensaje != NULL &&
	   pMensajeError != NULL &&
	   minimo <= maximo &&
	   reintentos >=0)
	{
		do
		{
			printf("%s",pMensaje);
			__fpurge(stdin);
			fgets(buffer,sizeof(buffer),stdin);
			buffer[strlen(buffer)-1] = '\0';
			if(strlen(buffer)>=minimo && strlen(buffer)<=maximo)
			{
				strncpy(pResultado,buffer,maximo+1);
				retorno = 0;
				break;
			}
			printf("%s",pMensajeError);
			reintentos--;
		}while(reintentos>=0);
	}

	return retorno;
}



//VALIDACION


/**
* \brief Evalua si el float recibido es entero o tiene decimales.
* \param numero Numero flotante a ser evaluado.
* \return Si el numero float es entero [0] o si el numero float tiene decimales [-1]
*/
/*float esDecimal(float *numero)//CORREGIR
{
	int retorno;
	int numeroEntero;
	if(numero != 0)
	{
		retorno = -1;
		printf("No es decimal!");
	}
	else
	{
		printf("Es decimal!");
		retorno = 0;
	}
	return retorno;
}
*/

//ARRAY FUNCTIONS

/**
* \brief Inicializa todos los elementos de un array de enteros.
* \param array Array a ser inicializado.
* \param mensaje Mensaje a ser mostrado.
* \param limite Limite del array
* \param valor Valor utilizado para inicializar los elementos del array
* \return Si tuvo exito al inicializar el array [0] o si fallo [-1]
*/
int initArrayInt(int array[],int limite,int valor)
{
	int i;
	int retorno = -1;

	if(array != NULL && limite > 0)
	{
		retorno = 0;
		for(i=0;i<limite;i++)
		{
			array[i] = valor;//
		}
	}
	return retorno;
}
/**
* \brief Imprime todos los elementos de un array de enteros.
* \param array Array a ser inicializado.
* \param limite Limite del array
* \return Si tuvo exito al imprimir el array [0] o si fallo [-1]
*/
int imprimeArrayInt(int array[],int limite)
{
	int i;
	int retorno = -1;
	if(array != NULL && limite > 0)
	{
		retorno = 0;
		printf("\n\n-------\n");
		for(i=0;i<limite;i++)
		{
			printf("%d\n",array[i]);
		}

	}
	return retorno;
}

int imprimeArrayString(char aNombres[][50], int cantidad){
	int i;
	int retorno = -1;

	if(aNombres != NULL && cantidad>=0)
	{
		retorno = 0;
		for(i=0;i<cantidad;i++)
		{
			printf("Nombre: %s \n",aNombres[i]);
		}
	}
	return retorno;
}

int getStringToInt(int *pResultado)//string to int
{
	int retorno =-1;
	char buffer[64];
	fgets(buffer,sizeof(buffer),stdin);
	buffer[strlen(buffer)-1]='\0';
	if(esNumerica(buffer))
	{
		*pResultado = atoi(buffer);
		retorno = 1;

	}
	return retorno;
}





int getArrayInt(	int array[],
					int limite,
					char *pMensaje,
					char *pMensajeError,
					int minimo,
					int maximo,
					int reintentos)
{
	int i=0;
	int buffer;
	char respuesta = 'n';
	int retorno = -1;
	if(array != NULL && limite > 0)
	{
		do
		{
			if(getInt(	&buffer,
						pMensaje,
						pMensajeError,
						minimo,
						maximo,
						reintentos) == 0)

			{
				array[i] = buffer;
				i++;
				limite--;
			}
			printf("Continuar? (s/n)");
			__fpurge(stdin);
			scanf("%c",&respuesta);
		}while(respuesta == 's' && limite > 0);
		retorno = i;
	}
	return retorno;
}

//VALIDACION
/**
* \brief Evalua si la cadena de caracteres es numerica.
* \param cadena Array de caracteres a ser validado
* \return Si la cadena de caracteres recibida es numerica [1] o si no lo es[-1]
*/

int esNumerica(char *cadena)
{
	int retorno=-1;
	int i=0;

	if(cadena != NULL)
	{
		while(cadena[i]!= '\0')
		{
			if(cadena[i]<'0' || cadena[i]>'9')
			{
				break;
				i++;
			}
			if(cadena[i]=='\0')
				retorno = 1;
		}
	}
	return retorno;
}


