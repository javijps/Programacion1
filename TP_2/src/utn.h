/*
 * utn.h
 *
 *  Created on: 23 sep. 2019
 *      Author: javijps
 */

#ifndef UTN_H_
#define UTN_H_

int getInt(   int *pNumero,
		      char mensaje[],
			  char mensajeError[],
			  int minimo,
			  int maximo,
			  int reintentos);
int getFloat(   float *pNumero,
		      char *mensaje,
			  char *mensajeError,
			  int minimo,
			  int maximo,
			  int reintentos);
int getChar(   char *pChar,
		      char *mensaje,
			  char *mensajeError,
			  int minimo,
			  int maximo,
			  int reintentos);
int getLetter(   char *pChar,
		      char *mensaje,
			  char *mensajeError,
			  int reintentos);
int getString(char *pResultado,
		      char *pMensaje,
			  char *pMensajeError,
			  int minimo,
			  int maximo,
			  int reintentos);
int initArrayInt(int array[],int limite,int valor);
int imprimeArrayInt(int array[],int limite);
int esNumerica(char *cadena);
int getArrayInt(	int array[],//no deberia construirla con getString y es numero?
					int limite,
					char *pMensaje,
					char *pMensajeError,
					int minimo,
					int maximo,
					int reintentos);
int imprimeArrayString(char aArray[][50],int limite);//esta bien el dato array?
int getNombre(char *pResultado,int limite);
int esNombre(char *pNombre);
int getCuit(char *pCuit,int limite);//resolver contador barra
int esCuit(char *pCuit);
int getEmail(char *pEmail,int limite);//resolver contador barra
int esEmail(char *pEmail);

int getMenuOptions(void);


//int getStringToInt(int *pResultado);



#endif /* UTN_H_ */
