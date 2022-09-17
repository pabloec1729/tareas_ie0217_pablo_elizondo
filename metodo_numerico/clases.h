

class funcion{
    private:
//parametros de las funciones algebraicas
        double a;
        double b;
        double c;
        double d;

        std::string func_tipo = "";

        double punto_actual;
        double punto_actual_up;
        double punto_actual_down;

        double error_requerido;
        double punto_inicial;

        double valor_funcion;
        double valor_funcion_up;
        double valor_funcion_down;

        double valor_derivada;
        double punto_anterior;
        double error_obtenido = 1; //Iniciamos asumiendo un error obtenido grande
    public:

        funcion();
//setters
        void setfunc_tipo(std::string); //el usuario puede ponerle una etiqueta a la funcion desde el main

        void seterror_requerido(double); //Al usuario se le solicita este dato como un porcentaje, asi que debe dividirse entre 100

        void setvalor_funcion(double);  //Calcula el valor de la funcion en el valor de prueba "p" y en otros 2 valores cercanos ((p + dp) y (p-dp), siendo "dp" un valor muy pequeño)

        void setvalor_derivada();  //Usando los valores dados por el metodo anterior calcula la pendiente de la linea recta entre los puntos r = (p + dp,f(p + dp)) y g = (p - dp,f(p - dp))

        void setpunto_actual();  //Implementacion del metodo de Newton-Raphson

        void setpunto_anterior(); //Guarda el valor de prueba anterior

        void setpunto_inicial(double); //establece el valor de prueba inicial

        void setparametros(double,double,double,double); //Define los parametros de las funciones algebraicas de la forma f(x) = a*x^3 + b*x^2 + c*x + d , se pueden modificar desde el main
//getters
        std::string getfunc_tipo();

        double getpunto_actual();

        double getvalor_funcion();

        double getvalor_derivada();

        double calcular_error();

        double obtener_raiz();
};

funcion::funcion(){
}

void funcion::setpunto_inicial(double _punto_inicial){
    punto_actual = _punto_inicial;
}

void funcion::seterror_requerido(double _error_requerido){
    error_requerido = _error_requerido/100;
}

void funcion::setparametros(double _a, double _b, double _c, double _d){
    a = _a;
    b = _b;
    c = _c;
    d = _d;
}

void funcion::setvalor_funcion(double _punto){
    //Se escogio 0.0001 como un valor muy cercano a cero con el cual se pueden obtener dos puntos uno a la derecha y otro a la izquierda del valor de prueba

    valor_funcion = a*pow(_punto,3) + b*pow(_punto,2) + c*_punto + d;
    valor_funcion_up = a*pow(_punto + 0.0001,3) + b*pow(_punto+0.0001,2) + c*(_punto+0.0001) + d;
    valor_funcion_down = a*pow(_punto - 0.0001,3) + b*pow(_punto-0.0001,2) + c*(_punto-0.0001) + d;
}

void funcion::setvalor_derivada(){
    //La derivada se obtiene linealizando alrededor del punto de prueba y aplicando la definicion pendiente, esto permite que desde el main
    //se puedan modificar y crear cuantas funciones se quieran sin tener que preocuparse por definir su derivada, siempre y cuando la funcion sea algebraica
    valor_derivada = (valor_funcion_up - valor_funcion_down)/0.0002;
}


void funcion::setpunto_actual(){
    int i = 1;
    int while_count = 0;
    int max_iteraciones = 30;   //Se puede modificar este parametro en caso de que se requiera mucha precision
    std::cout<<"Funcion "<<func_tipo<<std::endl;
    std::cout<<"F(x) = "<<a<<"x^3 + "<<b<<"x^2 + "<<c<<"x + "<<d<<"\n"<<std::endl;

    std::cout<<"Iteracion No."<<i<<": Probando x = "<<punto_actual<<std::endl;
    while ((abs(error_obtenido) > error_requerido) && (while_count < max_iteraciones)){

        setvalor_funcion(punto_actual);
        setvalor_derivada();
        punto_anterior = punto_actual;
        punto_actual = punto_actual - (valor_funcion/valor_derivada);
        i = i + 1;
        while_count = while_count + 1;
        error_obtenido = abs((punto_actual - punto_anterior)/punto_actual);
        std::cout<<"Iteracion No."<<i<<"\nProbando x = "<<punto_actual<<std::endl;
        std::cout<<"Error obtenido: "<<error_obtenido*100<<"%\n"<<std::endl;

    }

    if (while_count == 1){
        i = 1;
    }

    if (while_count < max_iteraciones){ //Se establece un numero maximo de iteraciones ya que en caso de que no haya solucion el programa no terminaria
        std::cout<<"\nSolucion x = "<<punto_actual<<"\nIteraciones: "<<i<<"\nError: "<<error_obtenido*100<<"%"<<std::endl;
    }
    else {
        std::cout<<"No hay soluciones reales tras "<<max_iteraciones<<" iteraciones"<<std::endl;
    }

}

void funcion::setfunc_tipo(std::string _func_tipo){
    func_tipo = _func_tipo;
}

std::string funcion::getfunc_tipo(){
    return func_tipo;
}

double funcion::calcular_error(){ //calculo del error
    error_obtenido = (punto_actual - punto_anterior)/punto_actual;
}

double funcion::getpunto_actual(){
    return punto_actual;
}

double funcion::getvalor_funcion(){
    return valor_funcion;
}

double funcion::getvalor_derivada(){
    return valor_derivada;
}


//clases hijas de la clase funcion que son usadas en el main para resolver 3 ecuaciones de distinto grado
class grado3 : public funcion{

};

class grado2 : public funcion{
};

class grado1 : public funcion{
};
