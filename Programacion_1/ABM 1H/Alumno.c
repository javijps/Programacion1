#include "Alumno.h"

int buscarLibre(eAlumno listadoDeAlumnos[], int tam)
{

    int indice = -1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(listadoDeAlumnos[i].estado!=OCUPADO)
        {
            indice = i;
            break;
        }
    }
    return indice;

}

int buscarLocalidadPorId(eLocalidad listaLocalidades[], int tl, int id)
{
    int i;
    int retorno = -1;


    if(listaLocalidades!=NULL && tl>0)
    {

        for(i=0; i<tl; i++)
        {
            if(listaLocalidades[i].idLocalidad==id)
            {
                retorno = i;
                break;
            }
        }
    }


    return retorno;
}

void hardCodearAlumnos(eAlumno listadoDeAlumnos[], int tam)
{
    int i;
    int legajo[]= {101,102,103,104,105,106};
    float promedio[]= {6.66, 4,7.66,3,4,9};
    char nombre[][25]= {"Juan","Josefina","Maria","Marina","German","Mauricio"};
    int localidad[]= {1,1,3,2,1,3};
    for(i=0; i<6; i++)
    {
        listadoDeAlumnos[i].legajo = legajo[i];
        listadoDeAlumnos[i].promedio = promedio[i];
        strcpy(listadoDeAlumnos[i].nombre, nombre[i]);
        listadoDeAlumnos[i].estado = OCUPADO;
        listadoDeAlumnos[i].idLocalidad=localidad[i];

    }
}

void mostrarListadoAlumnos(eAlumno listadoDeAlumnos[], int ta, eLocalidad listaLocalidades[], int tl)
{
    int i;
    int j;
    int index;
    char descripcion[50];

    for(i=0; i<ta; i++)
    {
        if(listadoDeAlumnos[i].estado==OCUPADO)
        {
            index = buscarLocalidadPorId(listaLocalidades, tl, listadoDeAlumnos[i].idLocalidad);
            if(index!=-1)
            {
                strcpy(descripcion,listaLocalidades[index].localidad);
                printf("%d %s %f %s\n",listadoDeAlumnos[i].legajo,
                       listadoDeAlumnos[i].nombre,
                       listadoDeAlumnos[i].promedio,
                       descripcion);


            }


        }

        //mostrarUnAlumno(listadoDeAlumnos[i]);
    }


}

void cargarListadoAlumnos(eAlumno listadoDeAlumnos[], int tam)
{
    int i;
    int indice;

    indice = buscarLibre(listadoDeAlumnos, tam);
    printf("Indice: %d\n", indice);
    if(indice!=-1)
    {
        //hay lugar
        listadoDeAlumnos[indice] = cargarAlumno();
    }
    else
    {
        printf("No hay espacio disponible");
    }

}

eAlumno cargarAlumno(void)
{
    eAlumno miAlumno;

    printf("Ingrese legajo: ");
    scanf("%d", &miAlumno.legajo);
    printf("Ingrese nombre: ");
    fflush(stdin);
    scanf("%[^\n]", miAlumno.nombre);
    printf("Ingrese promedio: ");
    scanf("%f", &miAlumno.promedio);
    printf("En que localidad vive?");
    scanf("%d", &miAlumno.idLocalidad);


    miAlumno.estado = OCUPADO;

    return miAlumno;
}
void mostrarUnAlumno(eAlumno miAlumno)
{
    printf("%4d %25s %8.2f %4d\n",miAlumno.legajo,miAlumno.nombre, miAlumno.promedio, miAlumno.idLocalidad);
}

void sortStudentsByNameAndAverage(eAlumno listadoDeAlumnos[], int tam)
{
    int i;
    int j;
    eAlumno auxAlumno;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(listadoDeAlumnos[i].nombre,listadoDeAlumnos[j].nombre)>0)
            {
                auxAlumno = listadoDeAlumnos[i];
                listadoDeAlumnos[i] = listadoDeAlumnos[j];
                listadoDeAlumnos[j] = auxAlumno;
            }

            else
            {
                if(strcmp(listadoDeAlumnos[i].nombre,listadoDeAlumnos[j].nombre)==0)
                {
                    if(listadoDeAlumnos[i].promedio>listadoDeAlumnos[j].promedio)
                    {
                        auxAlumno = listadoDeAlumnos[i];
                        listadoDeAlumnos[i] = listadoDeAlumnos[j];
                        listadoDeAlumnos[j] = auxAlumno;
                    }
                }
            }
        }

    }
}


int buscarAlumnoPorLegajo(eAlumno* listaDeAlumnos, int cant, int legajo)
{
    int i;
    int retorno = -1;


    if(listaDeAlumnos!=NULL && cant>0)
    {

        for(i=0; i<cant; i++)
        {
            if(listaDeAlumnos[i].legajo==legajo && listaDeAlumnos[i].estado==OCUPADO)
            {
                retorno = i;
                break;
            }
        }
    }


    return retorno;
}

int modificarAlumno(eAlumno listaDeAlumnos[], int cant, int legajo)
{
    int index;
    char nombre[30];
    int quePaso = -1;
    char respuesta;
    eAlumno aux;

    index = buscarAlumnoPorLegajo(listaDeAlumnos,cant, legajo);
    if(index!=-1)
    {
        aux = listaDeAlumnos[index];
        mostrarUnAlumno(aux);
        printf("Ingrese el nuevo nombre: ");
        fflush(stdin);
        gets(aux.nombre);
        printf("Esta seguro que desea modificar este alumno? :");
        respuesta = getche();
        if(respuesta=='s')
        {
            listaDeAlumnos[index] = aux;
            quePaso = 1;
        }
        else
        {
            quePaso = 0;
        }

    }
    return quePaso;
}
int eliminarAlumno(eAlumno listadoDeAlumnos[], int tam)
{
    int legajo;
    int i;
    int flag = 0 ;
    char respuesta;

    int quePaso = -1;

    //mostrarListadoAlumnos(listadoDeAlumnos,tam);

    printf("Ingrese el legajo: ");
    scanf("%d", &legajo);

    for(i=0; i<tam; i++)
    {
        if(listadoDeAlumnos[i].legajo==legajo && listadoDeAlumnos[i].estado==OCUPADO)
        {
            mostrarUnAlumno(listadoDeAlumnos[i]);
            printf("Esta seguro que desea eliminar este alumno? :");
            respuesta = getche();
            if(respuesta=='s')
            {
                listadoDeAlumnos[i].estado = LIBRE;
                quePaso = 1;
            }
            else
            {
                quePaso = 0;
            }
            break;
        }

    }

    return quePaso;

}


void mostrarLocalidadesConSusAlumnos(eAlumno listaAlumnos[], int ta, eLocalidad listaLocalidades[], int tl)
{
    int i;
    int j;

    for(i=0; i<tl; i++)//
    {
        printf("--%s--\n", listaLocalidades[i].localidad);
        for(j=0; j<ta; j++)
        {
            if(listaAlumnos[j].estado==OCUPADO && listaLocalidades[i].idLocalidad == listaAlumnos[j].idLocalidad)
            {
                //mostrarListadoAlumnos(listaAlumnos, ta,listaLocalidades,tl);
                mostrarUnAlumno(listaAlumnos[j]);
            }
        }
    }
}


void buscarLocalidadConMayorAlumnos(eAlumno alumnos[], int ta, eLocalidad localidades[], int tl)
{
    eAuxLocalidad cuantosAlumnos[3];
    int i;
    int j;
    int maximo;
    int flag = 0;
    eLocalidad aux;
    int index;


    for(i=0; i<tl; i++)
    {
        cuantosAlumnos[i].idLocalidad =localidades[i].idLocalidad;
        cuantosAlumnos[i].cont = 0;
    }



    for(i=0; i<tl; i++)//
    {

        for(j=0; j<ta; j++)
        {
            if(alumnos[j].estado==OCUPADO && cuantosAlumnos[i].idLocalidad == alumnos[j].idLocalidad)
            {
              cuantosAlumnos[i].cont++;
            }
        }
    }

   /*for(i=0; i<tl; i++)//
    {
        printf("%d->%d\n", cuantosAlumnos[i].idLocalidad, cuantosAlumnos[i].cont);

    }*/

    for(i=0; i<tl; i++)
    {
        if(flag==0 || cuantosAlumnos[i].cont>maximo)
        {
            maximo = cuantosAlumnos[i].cont;
            flag = 1;
        }
    }

    for(i=0; i<tl; i++)
    {
        if(cuantosAlumnos[i].cont==maximo)
        {
           index = buscarLocalidadPorId(localidades,tl,cuantosAlumnos[i].idLocalidad);
           if(index!=-1)
           {
               aux = localidades[index];
               printf("--%s\n", aux.localidad);
           }


        }
    }



}


