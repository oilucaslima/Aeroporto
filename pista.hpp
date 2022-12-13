#ifndef PISTA_HPP
#define PISTA_HPP
#include <iostream>
#include <string>
#include <queue>
#include "aviao.hpp"
 
using namespace std;

struct Prioridade{
    bool operator() (Aviao& a1, Aviao& a2){
        return a1.getTempo() > a2.getTempo();
    }
};
 
class Pista {

    private:
        priority_queue<Aviao, vector<Aviao>, Prioridade>fila1_a; 
        priority_queue<Aviao, vector<Aviao>, Prioridade>fila2_a; 
        queue<Aviao>fila3_d;
        float  tempoTotalEsperaF1=0, qtdAterrisagemF1=0, tempoTotalEsperaF2=0, qtdAterrisagemF2=0;
        float tempoTotalEsperaF3=0, qtdDecolagemF3=0;

    public:
        
        Pista();

        void inserirF1(Aviao a);
        void inserirF2(Aviao a);
        void inserirF3(Aviao a);

        int tamanhoF1();
        int tamanhoF2();
        int tamanhoF3();

        void imprimirF1();
        void imprimirF2();
        void imprimirF3();

        void atualizandoTempoF1();
        void atualizandoTempoF2();
        void atualizandoTempoF3();
       
        void removerNaFila();

        int contadorTempoDecolagemF3();

        float mediaEsperaAterrissagemF1();
        float mediaEsperaAterrissagemF2();
        float mediaEsperaDecolagemF3();

        int retornarEmergenciaF1();
        int retornarEmergenciaF2();
        
        void quedaF1();
        void quedaF2();

};
#endif
 
   


