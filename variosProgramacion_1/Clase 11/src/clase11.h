/*
 * clase11.h
 *
 *  Created on: 24 sep. 2019
 *      Author: alumno
 */

#ifndef CLASE11_H_
#define CLASE11_H_

#define QTY_EMPLEADOS 10
#define QTY_NOMBRES 10
#define QTY_CARACTERES 50

#define LCD 1
#define LED 2
#define EMPTY 0
#define NOT_EMPTY 1

int getString(	char *pResultado,
				char *pMensaje,
				char *pMensajeError,
				int minimo,
				int maximo,
				int reintentos);

struct estructura {

	int idEstructura;
	int status;
	char nombreEstructura[50];
};

struct alumno {

	int idAlumno;
	int status;
	char nombreAlumno[50];
};

int initLugarLibreEstructura(struct estructura *aestructura, int cantidad,int valor);
int buscarPrimerOcurrencia(struct estructura aestructura[],int cantidad,int valor);//sirve como lugar libre
int imprimirArrayEstructura(struct estructura *aestructura, int cantidad);
//int buscarLugarLibreEstructura(struct estructura *aestructura, int cantidad);
int buscarEstructuraPorId(struct estructura *aestructura, int cantidad,int id);
int bajaEstructuraPorId(struct estructura *aestructura, int cantidad,int id);
int imprimirArrayEstructura(struct estructura *aestructura, int cantidad);



//int altaEmpleadoPorId(struct sEmpleado *aArray, int cantidad,struct sEmpleado empleado);
//int ordenarArrayEmpleados(struct sEmpleado *aEmpleado, int cantidad);




#endif /* CLASE11_H_ */
