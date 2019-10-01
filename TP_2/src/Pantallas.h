/*
 * Pantallas.h
 *
 *  Created on: 28 sep. 2019
 *      Author: javijps
 */

#ifndef PANTALLAS_H_
#define PANTALLAS_H_

typedef struct pantalla {

	int id;
	int status;
	int tipoPantalla;
	char nombrePantalla[50];
	char direccionPantalla[50];
	float precioPorDia;
} pantalla;

int initPantalla(pantalla *aPantalla, int cantidad);
int getDatosPantalla(struct pantalla *aPantalla,int cantidad);//reemplazar getstring por get nombre, get string x get direccion
int buscarPantallaLibre(pantalla *aPantalla,int cantidad);
int altaPantalla(struct pantalla *aPantalla, int cantidad);
int buscarPantallaLibre(pantalla *aPantalla,int cantidad);
int imprimirPantallas(pantalla *aPantalla, int cantidad);
void pantallaForzada(pantalla *aPantalla,int cantidad);
int buscarPantallaPorId(pantalla *aPantalla,int cantidad,int id);
int modificarPantallaPorId(pantalla *aPantalla, int cantidad,int id);
int bajaPantallaPorId(pantalla *aPantalla,int cantidad,int id);


#endif /* PANTALLAS_H_ */
