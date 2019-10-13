#include <stdio.h>
#include <string.h>

#define LIBRE 0
#define OCUPADO 1

typedef struct
{

    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int idLocalidad;
    char localidad[30];
    int codigoPostal;
} eLocalidad;

typedef struct
{
    int idLocalidad;
    int cont;
}eAuxLocalidad;
typedef struct
{
    int legajo;
    char nombre[29];
    float promedio;
    int idLocalidad;
    int estado;
} eAlumno;

eAlumno cargarAlumno(void);
void mostrarUnAlumno(eAlumno);
int buscarLibre(eAlumno*, int);
void cargarListadoAlumnos(eAlumno[], int);
void mostrarListadoAlumnos(eAlumno[], int, eLocalidad[], int);
void hardCodearAlumnos(eAlumno[], int);
void sortStudentsByNameAndAverage(eAlumno[], int);

int eliminarAlumno(eAlumno[], int);
int modificarAlumno(eAlumno[], int, int);

int buscarAlumnoPorLegajo(eAlumno[], int, int);

int buscarLocalidadPorId(eLocalidad[], int, int);
void mostrarLocalidadesConSusAlumnos(eAlumno[], int, eLocalidad[], int);

void buscarLocalidadConMayorAlumnos(eAlumno[], int, eLocalidad[], int);
