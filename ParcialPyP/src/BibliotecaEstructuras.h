/*
 * clase11.h
 *
 *  Created on: 24 sep. 2019
 *      Author: alumno
 */

#ifndef CLASE11_H_
#define CLASE11_H_

struct estructura {

	int idEstructura;
	int status;
	char nombreEstructura[50];
};

int initLugarLibreEstructura(struct estructura *aestructura, int cantidad);
int buscarPrimerOcurrencia(struct estructura aestructura[],int cantidad,int valor);//sirve como lugar libre
int imprimirArrayEstructura(struct estructura *aestructura, int cantidad);
int buscarLugarLibreEstructura(struct estructura *aestructura, int cantidad);//lo mismo q 1er ocurrencia
int buscarEstructuraPorId(struct estructura *aestructura, int cantidad,int id);
int bajaEstructuraPorId(struct estructura *aestructura, int cantidad,int id);
int altaArrayEstructuraPorID(struct estructura *aestructura, int cantidad, int id);
int modificarEstructuraPorId(struct estructura *aestructura, int cantidad,int id, int index);//es necesario el index como argumento devuelto en modificarEstructuraPor Id?
int ordenarArrayEstructura(struct estructura *aestructura, int cantidad);//cambiar por insert

/* FALTAN
 * LISTAR ARRAY(LISTAR PANTALLA)POR CUIT
 * LAS DE PUBLICACION SE MODIFICAN TODASPOR CUIT?
 * PEDIR DATOS ESTRUCTURA
 * ALTA PUBLICIDAD
 * PONER ESTRUCTURA COMO CAMPO DE OTRA ESTRUCTURA(PANTALA/ID PANTALLA EN PUBLICACION)
 * BAJA PUBLICIDAD
 * LISTAR IMPORTE POR CADA PUBLICACION. IMPRIMIR PRECIO PUBLICACION. CUIT COMO INPUT
 * LISTAR TODAS LAS PUBLICACIONES(CONTRATACIONES)
 * LISTAR PANTALLAS
 * INFORMAR -LISTA CADA CLIENTE CON TODAS CONTRATACIONES E IMPORTE A PAGAR POR CADA CONTRATACION
 * CLIENTE CON IMPORTE MAS ALTO A FACTURAR. ACUMULADOR DE PRECIOS POR CONTRATACIONES DE CLIENTE Y MAXIMO.
 * DOCUMENTAR TODAS LAS FUNCIONES HECHAS
 * CADA ENTIDAD DEBE TENER SU .C Y .H
 * UNA BIBLIOTECA MAS PARA OTRAS FUNCIONES?

 */

#endif /* CLASE11_H_ */
