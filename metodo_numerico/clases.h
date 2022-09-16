
class funcion{
    private:
//parametros de las funciones algebraicas
        float a;
        float b;
        float c;
        float d;

        std::string func_tipo = "edfs";

        float punto_actual;
        float punto_actual_up;
        float punto_actual_down;

        float error_requerido;
        float punto_inicial;

        float valor_funcion;
        float valor_funcion_up;
        float valor_funcion_down;

        float valor_derivada;
        float punto_anterior;
        float error_obtenido = 1; //Iniciamos asumiendo un error obtenido grande
    public:

        funcion();
//setters
        void setfunc_tipo(std::string);

        void seterror_requerido(float);

        void setvalor_funcion(float);

        void setvalor_derivada();

        void setpunto_actual();

        void setpunto_anterior();

        void setpunto_inicial(float);

        void setparametros(float,float,float,float);
//getters
        std::string getfunc_tipo();

        float getpunto_actual();

        float getvalor_funcion();

        float getvalor_derivada();

        float calcular_error();

        float obtener_raiz();
};

funcion::funcion(){
}

void funcion::setpunto_inicial(float _punto_inicial){
    punto_actual = _punto_inicial;
}

void funcion::seterror_requerido(float _error_requerido){
    error_requerido = _error_requerido;
}

void funcion::setparametros(float _a, float _b, float _c, float _d){
    a = _a;
    b = _b;
    c = _c;
    d = _d;
}

void funcion::setvalor_funcion(float _punto){
    valor_funcion = a*pow(_punto,3) + b*pow(_punto,2) + c*_punto + d;
    valor_funcion_up = a*pow(_punto + 0.0001,3) + b*pow(_punto+0.0001,2) + c*(_punto+0.0001) + d;
    valor_funcion_down = a*pow(_punto - 0.0001,3) + b*pow(_punto-0.0001,2) + c*(_punto-0.0001) + d;
}

void funcion::setvalor_derivada(){
    valor_derivada = (valor_funcion_up - valor_funcion_down)/0.0002;
}
//

void funcion::setpunto_actual(){
    int i = 1;
    int while_count = 0;
    std::cout<<"Funcion "<<func_tipo<<std::endl;
    std::cout<<"F(x) = "<<a<<"x^3 + "<<b<<"x^2 + "<<c<<"x + "<<d<<std::endl;

    while (abs(error_obtenido) > error_requerido){
        std::cout<<"Probando x = "<<punto_actual<<std::endl;
        setvalor_funcion(punto_actual);
        setvalor_derivada();
        punto_anterior = punto_actual;
        std::cout<<"punto actual iteracion "<<i<<": "<<punto_actual<<std::endl;
        punto_actual = punto_actual - (valor_funcion/valor_derivada);
        i = i + 1;
        while_count = while_count + 1;
        error_obtenido = abs((punto_actual - punto_anterior)/punto_actual);



    }
    if (while_count == 1){

        i = 1;
    }
    std::cout<<"X = "<<punto_actual<<" es una solucion, se necesitaron "<<i<<" iteraciones"<<std::endl;
}

void funcion::setfunc_tipo(std::string _func_tipo){
    func_tipo = _func_tipo;
}

std::string funcion::getfunc_tipo(){
    return func_tipo;
}

float funcion::calcular_error(){
    error_obtenido = (punto_actual - punto_anterior)/punto_actual;
}

float funcion::getpunto_actual(){
    return punto_actual;
}

float funcion::getvalor_funcion(){
    return valor_funcion;
}

float funcion::getvalor_derivada(){
    return valor_derivada;
}

class grado3 : public funcion{



};

class grado2 : public funcion{


};

class grado1 : public funcion{


};
