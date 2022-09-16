//===============================================
//Archivo: main.cpp
////===============================================
//// Curso de programación en C/C++
//// Estudiante: Juan Pablo Elizondo Calvo B52485
////===============================================

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <math.h>
#include "clases.h"
#include <cmath>
#include <string.h>
using namespace std;


int main(void)
{
    float val_in = 98;
    float error_requerido = 0.001;


//    funcion funcion1;

    grado3 hiperbolica;
    grado2 parabola;
    grado1 lineal;

   cout <<"\n=================Nueva funcion======================\n"<<endl;
   lineal.setfunc_tipo("lineal");
   lineal.setparametros(0,0,3,7);
   lineal.setpunto_inicial(val_in);
   lineal.seterror_requerido(error_requerido);
   lineal.setpunto_actual();

   cout <<"\n=================Nueva funcion======================\n"<<endl;
   parabola.setfunc_tipo("cuadratica");
   parabola.setparametros(0,1,9,3);
   parabola.setpunto_inicial(val_in);
   parabola.seterror_requerido(error_requerido);
   parabola.setpunto_actual();

   cout <<"\n=================Nueva funcion======================\n"<<endl;
   hiperbolica.setfunc_tipo("hiperbolica");
   hiperbolica.setparametros(1,2,3,4);
   hiperbolica.setvalor_funcion(val_in);
   hiperbolica.seterror_requerido(error_requerido);
   hiperbolica.setpunto_actual();

}//________________________________________
