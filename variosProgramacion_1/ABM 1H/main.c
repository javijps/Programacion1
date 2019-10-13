#include <stdio.h>
#include <stdlib.h>
#include "Alumno.h"
#define A 10


/*
2. por cada localidad todos sus alumnos


3. cual/es son las localidades con mas alumnos
*/


int main()
{
    eAlumno listaDeAlumnos[A];
    eLocalidad listaLocalidades[3]={{1,"Avellaneda",1870},{2,"Wilde",1872},{3,"Lomas de Zamora",1700}};
    int i;
    int respuesta;
    int opcion;

    for(i=0; i<A; i++)
    {
        listaDeAlumnos[i].estado=LIBRE;
    }

    hardCodearAlumnos(listaDeAlumnos,A);

    do
    {
        printf("1.Cargar\n2.Mostrar\n3.Ordenar\n4.Eliminar\n5.Modificar\n6.Listar localidades c alumnos\n10.Salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            cargarListadoAlumnos(listaDeAlumnos,A);

            break;
        case 2:
            mostrarListadoAlumnos(listaDeAlumnos, A, listaLocalidades, 3);
            break;
        case 3:
            sortStudentsByNameAndAverage(listaDeAlumnos,A);
            break;
        case 4:
            respuesta = eliminarAlumno(listaDeAlumnos,A);
            switch(respuesta)
            {
                case 0:
                    printf("Accion cancelada por el usuario\n");
                    break;
                case 1:
                    printf("Alumno eliminado\n");
                    break;
                case -1:
                    printf("Dato no encontrado\n");
                    break;
            }

            break;
        case 5:

            respuesta = modificarAlumno(listaDeAlumnos,A,102);
            switch(respuesta)
            {
                case 0:
                    printf("Accion cancelada por el usuario\n");
                    break;
                case 1:
                    printf("Alumno modificado\n");
                    break;
                case -1:
                    printf("Dato no encontrado\n");
                    break;
            }
            break;
            case 6:
                    mostrarLocalidadesConSusAlumnos(listaDeAlumnos, A, listaLocalidades,3);
                    break;
            case 7:
                buscarLocalidadConMayorAlumnos(listaDeAlumnos, A, listaLocalidades,3);
                break;
        }

    }
    while(opcion!=10);
    return 0;
}


