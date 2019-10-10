/*
 * Pantallas.h
 *
 *  Created on: 28 sep. 2019
 *      Author: javijps
 */

#ifndef PANTALLAS_H_
#define PANTALLAS_H_
#include "Publicidades.h"

typedef struct pantalla {

	int id;
	int status;
	int tipoPantalla;
	char nombrePantalla[50];
	char direccionPantalla[50];
	float precioPorDia;
} pantalla;

int initPantalla(pantalla *aPantalla, int cantidad);
int getDatosPantalla(struct pantalla *aPantalla,int cantidad);
int buscarPantallaLibre(pantalla *aPantalla,int cantidad);
int altaPantalla(struct pantalla *aPantalla, int cantidad);
int imprimirPantallas(pantalla *aPantalla, int cantidad);//activas. cambiar si se necesita inactivas o pausadas
int buscarPantallaPorId(pantalla *aPantalla,int cantidad,int id);
int modificarPantallaPorId(pantalla *aPantalla, int cantidad,int id);
int bajaPantallaPorId(pantalla *aPantalla,int cantidad,int id);
void imprimirUnaPantallaPorId(pantalla *aPantalla,int cantidad,int id);
int imprimirPantallasPorCuitYmodificarDiasContratados(pantalla *aPantalla,
		                                              int lenApantalla,
													  publicidad *aPublicidad,
													  int lenApublicidad,
													  char *cuitCliente);
int imprimirPantallasPorCuitYcancelarContratacion(pantalla *aPantalla,
		                                          int lenApantalla,
												  publicidad *aPublicidad,
												  int lenApublicidad,
												  char *cuitCliente);
int imprimirPantallasPorCuitConFacturacionPorPublicidad(pantalla *aPantalla,
		                                          int lenApantalla,
												  publicidad *aPublicidad,
												  int lenApublicidad,
												  char *cuitCliente);
int listarDatosPantallaYpublicidad(pantalla *aPantalla,int lenApantalla,publicidad *aPublicidad,int lenApublicidad);

void pantallaForzada(pantalla *aPantalla,int cantidad);

#endif /* PANTALLAS_H_ */
