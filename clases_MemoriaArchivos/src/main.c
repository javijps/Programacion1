/*
 ============================================================================
 Name        : Clase_pYmm.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scliente.h"
#include "ejercicios.h"
#include "utn.h"


int main(void)
{
	sPeople p;
	int option;

	do
	{
	peo_loadDataPeople(&p);
		peo_savePeople(&p);
		getInt(&option,"Ingresar uno nuevo? 1-s\n2-n\n","Incorrecto!\n",1,3,2);

	}while(option==1);

	char surnameToFind[32];
	getNombre(surnameToFind,"Ingrese archivo a encontrar en el archivo\n","Los datos no corresponden a un apellido!\n",2);

	sPeople* pFound = peo_readPeople(surnameToFind);

	if(pFound!=NULL)
	{
		printf("Se encontro: nombre %s apellido %s edad: %d\r\n",pFound->namePeople,pFound->surnamePeople,pFound->agePeople);
		peo_deletePeople(pFound);
	}
	else
		printf("EL archivo no fue encontrado en el archivo!\n");

	return 0;
}




/*    struct sDAta array[16];
    int len = loadDataFile("dict.txt",array,16);
    int i;

    for(i=0; i<len;i++)
        printf("%s = %s\r\n",array[i].key,array[i].value);
 *
 */


/*	sCliente* aCliente[1000];

	FILE *pFile;
	int r;
	char var1[50],var3[50],var2[50],var4[50];

	pFile = fopen("clientes.txt","r");
	if(pFile == NULL)
	{
		printf("El archivo no existe");
		exit(EXIT_FAILURE);
	}
	do
	{
		r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
		if(r==4)//cantidad de cosas
		{
			printf("Lei: %s %s %s %s\n",var1,var2,var3,var4);
			//			cuando uso el new, voy generando las direcciones
			//			de memoria para cada unidad de la estructura(un cliente) array
			//			hacer un new para generar un clinete
			//			cargar los campos con los datos
			//			guardar la direccion en el array de punteros
			//el id lo tomo como string y lo paso a numero
			//sCliente* cliente = cli_new_ClienteParametros(var1,var2,var3,var4);//pongo las variables en el orden q corre
			//tengo q agregar id a las funciones
		}
		else
			break;

	}while(!feof(pFile));

	fclose(pFile);
 */
