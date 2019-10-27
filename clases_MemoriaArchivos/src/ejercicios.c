/*
 * ejerciciosPunteros.c
 *
 *  Created on: 27 oct. 2019
 *      Author: javijps
 */

#include <stdio.h>
#include <stdlib.h>
#include "ejercicios.h"
#include <string.h>

static float isValidKey(char *value)
{
	return 1;
}

static float isValidValue(char* value)
{
	return 1;
}


//MEMORIA

/*
1) Construir una función llamada "getDynamicString" que permita al usuario ingresar un texto y devuelva un puntero
   a un espacio de memoria donde esta almacenado el texto ingresado. Se requiere el uso de memoria dinámica.

//imprime mensaje, asigna memoria para 1024 caracteres, toma el texto, mide su largo con strlen y despues hace
//un realloc con el texto, para ajustar el espacion de memoria a ocupar a lo que da el strlen*/

char* getDynamicString(char* messagge)
{
	printf(messagge);
	char* pData = (char*)malloc(sizeof(char)*1024);
	int len;

	if(messagge!=NULL)
	{
		len = strlen(pData);
		scanf("%1023s",pData);
		pData = (char*)realloc(pData,sizeof(char)*(len+1));
	}
	return pData;
}


//ARCHIVOS

sData* ped_new_Data(void)
{
	return malloc(sizeof(sData));
}

void ped_deleteData(sData* this)
{
	free(this);
}

int ped_setKey(sData* this,char* key)
{
	int retorno = -1;

	if(this!=NULL && isValidKey(key))
	{
			strcpy(this->key,key);
			retorno = 0;
	}
	return retorno;
}

int ped_setValue(sData* this,char* value)
{
	int retorno = -1;

	if(this!=NULL && isValidValue(value))
	{
			strcpy(this->value,value);
			retorno = 0;
	}
	return retorno;
}


int loadDataFile(char* fileName,sData* array, int arrayLen)
{
	FILE *pArch;
	char lineStr[128];//buffer para leer las lineas
	int index=0;
	int indexDivider;
	int keyLen;
	int valueLen;
	//sData auxData;

	pArch=fopen(fileName,"r");//abro el archivo para lectura
	if(pArch==NULL)
	{
		printf("Error\n");
		return -1;
	}
	while( fgets(lineStr,128,pArch)!=NULL )//LEE LA LINEA Y LA CARGA EN EL BUFFER DE CARACTERES.
	{
		//separo las palabras por el =
		indexDivider = strcspn(lineStr,"=");//devuelve la ṕosicion donde esta el igual
		keyLen = indexDivider+1;//calculo cuanto mide key, lo saco porque es hasta donde este el igual
		valueLen = strlen(lineStr) -indexDivider-1;//calculo el largo del valor, es desde el igual en adelante


		//ped_new_Data(auxData);
		char* key = (char*) malloc(keyLen);
		char* value = (char*) malloc(valueLen);

		//todo esto menos poner al final deberia hacerlo con set
		strncpy(key,lineStr,keyLen-1);//copio el string con la clave
		key[keyLen-1] = 0x00;//pongo esto para el final
		strncpy(value,&lineStr[keyLen],valueLen-1);//copio el string con el valor
		value[valueLen-1] = 0x00;
		array[index].key = key;
		array[index].value = value;

		index++;
		 // contamos la cantidad de items en el array, si se llega al maximo pemitido, se sale
		if(index>=arrayLen)
			break;
	}
	return index;
}
