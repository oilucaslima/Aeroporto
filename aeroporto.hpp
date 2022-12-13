#ifndef AEROPORTO_HPP
#define AEROPORTO_HPP
#include "pista.hpp"
#include "pista3.hpp"
#include <iostream>
#include <string>
 
using namespace std;

class Aeroporto{
    
    private:

        Aviao* aviao;
        Pista* p1;
        Pista* p2;
        Pista3* p3;

    public:

        Aeroporto(Pista* p1, Pista* p2, Pista3* p3);
        Aeroporto();

        void setPista1(Pista* p1);
        Pista* getPista1();

        void setPista2(Pista* p2);
        Pista* getPista2();

        void setPista3(Pista3* p3);
        Pista3* getPista3();

        void inserirPista(Aviao aviao);
        void removendoDasPistas();

        void imprimirPista1();
        void imprimirPista2();
        void imprimirPista3();

        void atualizandoTempos_Pistas();

        void alertaEmergencia();
};
#endif