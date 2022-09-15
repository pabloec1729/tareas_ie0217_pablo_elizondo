
class funcion{
    private:
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
        float error_obtenido = 1;
    public:

        funcion();
//setters
        void seterror_requerido(float);

        void setvalor_funcion(float);

        void setvalor_derivada();

        void setpunto_actual();

        void setpunto_anterior();

        void setpunto_inicial(float);
//getters
        float getpunto_actual();

        float getvalor_funcion();

        float getvalor_derivada();

        float calcular_error();

        float obtener_raiz();



};

//funcion::funcion(float _a, _b, _c, x){
//    funcion = _a*pow(_x,2)+_b*_x + _c;
//}

funcion::funcion(){
}

void funcion::setpunto_inicial(float _punto_inicial){
    punto_actual = _punto_inicial;
}

void funcion::seterror_requerido(float _error_requerido){
    error_requerido = _error_requerido;
}

void funcion::setvalor_funcion(float _punto){
    valor_funcion = 4*pow(_punto,2) -9*_punto + 3;
    valor_funcion_up = pow(_punto+0.0001,3) - 1;
    valor_funcion_down = pow(_punto-0.0001,3) - 1;
}

void funcion::setvalor_derivada(){
    valor_derivada = (valor_funcion_up - valor_funcion_down)/0.0002;
}

void funcion::setpunto_actual(){
    while (abs(error_obtenido) > error_requerido){
        setvalor_funcion(punto_actual);
        setvalor_derivada();
        punto_anterior = punto_actual;
        punto_actual = punto_actual - (valor_funcion/valor_derivada);
        error_obtenido = abs((punto_actual - punto_anterior)/punto_actual);
    }
}
//
//void funcion::setpunto_anterior(){
//    punto_anterior = _punto_actual;
//}









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
