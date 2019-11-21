#ifndef employee_H_INCLUDED

#include "LinkedList.h"
#include "utn.h"
#include "Controller.h"

#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

void emp_printAemployee(Employee* employee);
Employee* emp_findEmployeeById(LinkedList* pArrayListEmployee,int idEmployee);//busqueda por ID











Employee* employee_getDatosEmployee(LinkedList* pArrayListEmployee);////interaccion con usuario
Employee* employee_EditEmployee(LinkedList* pArrayListEmployee);//interaccion con usuario
Employee* emp_subMenuEditEmployee(Employee* bEmpleado);//interaccion con usuario

int employee_deleteEmployee(LinkedList* pArrayListEmployee);//interaccion con usuario

int emp_sortEmployeById(void* a,void* b);//FUNCION CRITERIO SORT.
int emp_sortEmployeByName(void* a,void* b);//FUNCION CRITERIO SORT.
int emp_maximoId(LinkedList* pArrayListEmployee);
int emp_getNextId(LinkedList* pArrayListEmployee);
int emp_existeEmpleadoByName(LinkedList* pArrayListEmployee,char *bName);


#endif // employee_H_INCLUDED
