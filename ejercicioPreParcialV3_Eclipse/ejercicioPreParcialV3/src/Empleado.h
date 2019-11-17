#ifndef EMPLEADO_H_INCLUDED
#include "LinkedList.h"
#define EMPLEADO_H_INCLUDED

struct S_Empleado
{
  int id;
  char nombre[128];
  int horasTrabajadas;
  int sueldo;
};
typedef struct S_Empleado Employee;


void em_calcularSueldo(void* p);



Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);
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
Employee* emp_findEmployeeById(LinkedList* pArrayListEmployee,int idEmployee);
Employee* employee_getDatosEmployee(LinkedList* pArrayListEmployee);//
Employee* employee_EditEmployee(LinkedList* pArrayListEmployee);
Employee* emp_subMenuEditEmployee(Employee* bEmpleado);
int employee_deleteEmployee(LinkedList* pArrayListEmployee);
int emp_sortEmployeById(void* a,void* b);
int emp_sortEmployeByName(void* a,void* b);
int emp_maximoId(LinkedList* pArrayListEmployee);
int emp_getNextId(LinkedList* pArrayListEmployee);
int emp_existeEmpleadoByName(LinkedList* pArrayListEmployee,char *bName);


#endif // EMPLEADO_H_INCLUDED
