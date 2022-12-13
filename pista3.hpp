#ifndef PISTA3_HPP
#define PISTA3_HPP
#include <iostream>
#include <string>
#include <queue>
#include "aviao.hpp"
 
using namespace std;

struct Prioridade3{
    bool operator() (Aviao& a1, Aviao& a2){
        return a1.getTempo() > a2.getTempo();
    }
};
 
class Pista3 {

    private:
        priority_queue<Aviao, vector<Aviao>, Prioridade3>fila1_a; 
        float  tempoTotalEsperaAterrissagemF1=0, tempoTotalEsperaF1=0, qtdAterrisagemF1=0, qtdDiminuidoTotalF1=0;

    public:
        
        Pista3();

        void inserirF1(Aviao a);

        int tamanhoF1();

        void imprimirF1();

        void atualizandoTempoF1();

        void removerNaFila();

        int contadorTempoDecolagemF1();

        int tamanhoApenasAterrissagem();
        int tamanhoApenasDecolagem();

        float mediaEsperaAterrissagemF1();

        float diminuidoTotalF1();
        float mediaGlobalF1();

        int retornarEmergenciaF1();
};
#endif
 
   


