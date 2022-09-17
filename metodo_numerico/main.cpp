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
    double val_in; //Guarda el primer valor de prueba
    double error_maximo; //Guarda el erro maximo solicitado por el usuario

    grado3 hiperbolica;
    grado2 parabola;
    grado2 parabola_sin_solucion;
    grado1 lineal;



    cout <<"Ingrese un valor de prueba inicial: "; cin>>val_in;
    cout <<"Ingrese el porcentaje de error maximo deseado: "; cin>>error_maximo;

   cout <<"\n=================Nueva funcion======================\n"<<endl;
   lineal.setfunc_tipo("lineal");
   lineal.setparametros(0,0,3,7); //parametros a,b,c y d respectivamente
   lineal.setpunto_inicial(val_in);
   lineal.seterror_requerido(error_maximo);
   lineal.setpunto_actual();    //Metodo de Newton-Raphson, calculando la solucion comparando entre los puntos de prueba obtenidos

   cout <<"\n=================Nueva funcion======================\n"<<endl;
   parabola.setfunc_tipo("cuadratica");
   parabola.setparametros(0,1,2,1); //parametros a,b,c y d respectivamente
   parabola.setpunto_inicial(val_in);
   parabola.seterror_requerido(error_maximo);
   parabola.setpunto_actual(); //Metodo de Newton-Raphson, calculando la solucion comparando entre los puntos de prueba obtenidos

   cout <<"\n=================Nueva funcion======================\n"<<endl;
   hiperbolica.setfunc_tipo("hiperbolica");
   hiperbolica.setparametros(1,2,3,4); //parametros a,b,c y d respectivamente
   hiperbolica.setpunto_inicial(val_in);
   hiperbolica.seterror_requerido(error_maximo);
   hiperbolica.setpunto_actual(); //Metodo de Newton-Raphson, calculando la solucion comparando entre los puntos de prueba obtenidos


    cout <<"\n=================Nueva funcion======================\n"<<endl; //Probando una funcion sin solucion real
   parabola_sin_solucion.setfunc_tipo("cuadratica");
   parabola_sin_solucion.setparametros(0,1,1,1); //parametros a,b,c y d respectivamente
   parabola_sin_solucion.setpunto_inicial(val_in);
   parabola_sin_solucion.seterror_requerido(error_maximo);
   parabola_sin_solucion.setpunto_actual(); //Metodo de Newton-Raphson, calculando la solucion comparando entre los puntos de prueba obtenidos


}//________________________________________
