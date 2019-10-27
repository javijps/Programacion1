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
void printPerson(sPersonaPunteros* pPerson);
char* getDynamicString(char* messagge);


#endif /* EJERCICIOSPUNTEROS_H_ */
