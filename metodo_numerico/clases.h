extern float suma(float,float );



class funcion{
    private:
        float punto_actual;
        float error_requerido;
        float punto_inicial;

        float valor_funcion;
        float valor_derivada;
        float punto_anterior;
        float error_obtenido;
    public:

        funcion();

        void setvalor_funcion();

        void setvalor_derivada();

        void setpunto_actual();

        void setpunto_anterior();

        void setpunto_inicial(float);

        float getpunto_actual();

        float calcular_error();

        float obtener_raiz();

};

funcion::funcion(){
}

void funcion::setvalor_funcion(){
    valor_funcion = pow(punto_actual,2) + punto_actual*7;
}


void funcion::setpunto_actual(){

    punto_actual = punto_actual - valor_funcion/valor_derivada;
}

void funcion::setpunto_inicial(float _punto_inicial){
    punto_actual = _punto_inicial;
}


float funcion::calcular_error(){
    error_obtenido = (punto_actual - punto_anterior)/punto_actual;
}

float funcion::getpunto_actual(){
    return punto_actual;
}

