#ifndef AVIAO_HPP
#define AVIAO_HPP
#include <iostream>
#include <string>
 
using namespace std;
 
class Aviao {

    private:
       
        string companhia;
        int passageiro;
        int ID;
        int tempo_comb;
        int tempo_espera;
 
       
    public:
       
        Aviao ();
        Aviao (string companhia, int passageiro, int ID, int tempo_comb, int tempo_espera);
 
        void setCompanhia(string companhia);
        string getCompanhia();
 
        void setPassageiro(int passageiro);
        int getPassageiro();
 
        void setID(int ID);
        int getID();
 
        void setTempo(int tempo_comb);
        int getTempo();

        void setTempoEspera(int tempo_espera);
        int getTempoEspera();
 
        void imprimirAte();
        void imprimirAte2();

        void imprimirDeco();
        void imprimirDeco2();

        void inserir();
 
};
 
#endif
 
   


