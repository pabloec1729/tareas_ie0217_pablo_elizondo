//===============================================
//Archivo: caso4.cpp
////===============================================
//// Curso de programación en C/C++
//// Profesor: Freddy Rojas.
//// Material de curso licencia GPL version 2.0
////===============================================
//// No se admiten responsabilidades por el
//// uso del material que no sea el planteado
//// inicialmente para material didactico.
////===============================================
//#include <stdio.h>
//#include <iostream>
//#include "funciones.h"
//using namespace std;
//int variable_global=10;
//
//extern float suma(float,float);
//
//int main(void)
//{
//   int variable_global=30;
//   cout << "La suma  de 20.3 y 40.2 da " << suma(20.3,40.2) << endl;
//   variable_global++;
//   getchar();
//}//________________________________________

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <math.h>
#include "clases.h"
#include <cmath>
using namespace std;
int variable_global=10;

extern float suma(float,float);

int main(void)
{
    float val_in = 1;
    float error_requerido = 0.001;
    funcion funcion1;


   cout << "Establezca valor de prueba inicial:\n";
//   cin >> val_in;
//   cout << "Ingrese el error maximo deseado:\n";
//   cin >> error_requerido;

//   funcion1.setpunto_inicial(val_in);
   funcion1.setvalor_funcion(val_in);
   funcion1.setvalor_derivada();
   funcion1.seterror_requerido(error_requerido);
   funcion1.setpunto_inicial(val_in);

   cout << funcion1.getpunto_actual()<<endl;
   cout << "El valor de la funcion es "<<funcion1.getvalor_funcion()<<endl;
   cout << "El valor de la derivada es "<<funcion1.getvalor_derivada()<<endl;
   funcion1.setpunto_actual();
   cout << "El cero esta en " <<funcion1.getpunto_actual()<<endl;

}//________________________________________
