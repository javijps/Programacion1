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
//	sData auxData;

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


//		ped_new_Data(auxData);
		char* key = (char*) malloc(keyLen);
		char* value = (char*) malloc(valueLen);


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









//PEOPLE

sPeople* peo_new_People()
{
	return malloc(sizeof(sPeople));
}

void peo_deletePeople(sPeople* this)
{
	free(this);
}


int peo_setNamePeople(sPeople* this,char* name)
{
	int retorno = -1;

	if(this!=NULL && esNombre(name))
	{
		strcpy(this->namePeople,name);
		retorno = 0;
	}
	return retorno;
}


int peo_getNamePeople(sPeople* this,char* name)
{
	int retorno = -1;

	if(this!=NULL)
	{
		strcpy(name,this->namePeople);
		retorno = 0;
	}
	return retorno;
}

int peo_setSurnamePeople(sPeople* this,char* surname)
{
	int retorno = -1;

	if(this!=NULL && esNombre(surname))
	{
		strcpy(this->surnamePeople,surname);
		retorno = 0;
	}
	return retorno;
}


int peo_getSursurnamePeople(sPeople* this,char* surname)
{
	int retorno = -1;

	if(this!=NULL)
	{
		strcpy(surname,this->surnamePeople);
		retorno = 0;
	}
	return retorno;
}

int peo_setAgePeople(sPeople* this,int* age)
{
	int retorno = -1;

	if(this!=NULL /*&& esInt(age)*/)
	{
		this->agePeople = *age;
		retorno = 0;
	}
	return retorno;
}


int peo_getAgePeople(sPeople* this,int* age)
{
	int retorno = -1;

	if(this!=NULL)
	{
		*age = this->agePeople;
		retorno = 0;
	}
	return retorno;
}


sPeople peo_new_PeopleParametros(char* namePeople,char* surnamePeople,int *agePeople)
{
	sPeople* retorno = NULL;
	sPeople* this;
	this = peo_new_People();

	if(this!=NULL)
	{
		if(peo_setNamePeople(this,namePeople)==0 &&
				peo_setSurnamePeople(this,surnamePeople)==0 &&
				peo_setAgePeople(this,agePeople)==0)
			retorno = this;
		else
			peo_deletePeople(this);
	}
	return *retorno;
}

 int peo_savePeople(sPeople *p)
 {
	 FILE* fp;
	 fp = fopen("bin.dat","ab+");//ab+ es para que apendee al final del archivo
	 if(fp==NULL)
	 {
		 printf("Error opening file\n");
		 return 0;
	 }
	 fwrite(p,sizeof(sPeople),1,fp);//puntero de lo que quiero escribir, tamaño del bloque a escribir, cantidad de bloques, puntero a que archivo

	 fclose(fp);
	 return 1;
 }

// BUSCAR DENTRO DEL ARCHIVO UN APELLIDO

 //LEER EL ARCHIVO ESTRUCTURA POR ESTRUCTURA, COMPARAR CON EL RECIBIDO POR ARGUMENTO




 void peo_loadDataPeople(sPeople* p)
 {
	 char bNombre[32];
	 char bApellido[32];
	 int bEdad;

	 if(getNombre(bNombre,"Ingrese Nombre\n","Error, nombre incorrecto\n",2) == 0 &&
			      getNombre(bApellido,"Ingrese Apellido\n","Error, apellido incorrecto\n",2) == 0 &&
			      getInt(&bEdad,"Ingrese Edad\n","Edad incorrecta",1,90,3)==0)
		 {
		 printf("carga ok\n");
		 *p = peo_new_PeopleParametros(bNombre,bApellido,&bEdad);
		 }
	 else
		 printf("Error al cargar!\n");
}



 sPeople* peo_readPeople(char* surnamePeople)
 {
	 FILE* fp;//CREO UN PUNTERO FILE
	 fp = fopen("bin.dat","rb");// ABRO ARCHIVO BINARIO.rb solo lectura de binario
	 if(fp==NULL)//SI ES NULL, NO ABRIO EL ARCHIVO
	 {
		 printf("Error opening file\n");
	}

	 //PODRIA SER UNA FUNCION, *sPeople FINDPEOPLE(char *surnamePeople){
	 sPeople *pRet = peo_new_People();//LIBERO DE FORMA DINAMICA ESPACIO EN LA MEMORIA PARA UN sPeople
	 int flagFound;//FLAG PARA CUANDO ENCUENTRO EL NOMBRE
	 while(fread(pRet,sizeof(sPeople),1,fp)!=0)//leo el archivo,recibe puntero a la estructura,tamaño del bloque estructura, cantidad de bloques y puntero file donde lee.
	 {
		 if(strncmp(surnamePeople,pRet->surnamePeople,32)==0)//si encuentra mediante comparacion el surname, falg found y break
		 {
			 flagFound = 1;
			 break;
		 }
	 }
	 fclose(fp);//cierra archivo
	 if(flagFound)//si lo encontro , devuleve el puntero a sPeople, si no, NULL
		 return pRet;
	 peo_deletePeople(pRet);
	 return NULL;
	 //HASTA ACA LA FUNCION
 }
