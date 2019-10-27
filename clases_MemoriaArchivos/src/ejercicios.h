/*
 * ejerciciosPunteros.h
 *
 *  Created on: 27 oct. 2019
 *      Author: javijps
 */

#ifndef EJERCICIOSPUNTEROS_H_
#define EJERCICIOSPUNTEROS_H_

#include "utn.h"


struct sPersonaPunteros{

	int id;
	//-------------------------
	char nombrePersona[50];
	int edadPersona;
	int dniPersona;
}typedef sPersonaPunteros;


int funcionUno(int array[],int len);
int funcionDos(int array[],int len);
int funcionTres(int array[],int len);
int funcionCuatro(int array[],int len);

int loadPerson(sPersonaPunteros* pPerson);
char* getDynamicString(char* messagge);




struct sDAta{

	char* key;
	char* value;

}typedef sData;

sData* ped_new_Data();
void ped_deleteData(sData* this);
int ped_setKey(sData* this,char* key);
int ped_setValue(sData* this,char* value);

int loadDataFile(char* fileName,sData* array, int arrayLen);

#endif /* EJERCICIOSPUNTEROS_H_ */
