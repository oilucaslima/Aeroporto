#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "pista3.hpp"

Pista3 :: Pista3 (){
    this->tempoTotalEsperaAterrissagemF1=0;
    this->tempoTotalEsperaF1=0;
    this->qtdAterrisagemF1=0;
    this->qtdDiminuidoTotalF1=0;
}

void Pista3 :: inserirF1(Aviao aviao){
    fila1_a.push(aviao);
}

int Pista3 :: tamanhoF1(){
    return fila1_a.size();
}

void Pista3 :: imprimirF1(){
    
    priority_queue<Aviao, vector<Aviao>, Prioridade3 > auxfila = fila1_a;

    while(!auxfila.empty()){
        
        Aviao aux = auxfila.top();
        aux.imprimirAte();
        auxfila.pop();
    }

    cout<<"\n";
}

void Pista3 :: removerNaFila(){
    if(fila1_a.size() != 0){
        Aviao aux = fila1_a.top();
        if (aux.getID()%2!=0){
            tempoTotalEsperaAterrissagemF1 += aux.getTempoEspera();
            qtdAterrisagemF1++;
        }
        tempoTotalEsperaF1 += aux.getTempoEspera();
        fila1_a.pop();
        qtdDiminuidoTotalF1++;
    }
    else{
        cout<<" \n\t [!] - Pista 3: vazia - [!] ";
    }
}

void Pista3 :: atualizandoTempoF1(){

    priority_queue<Aviao, vector<Aviao>, Prioridade3> auxfila = fila1_a; 
    priority_queue<Aviao, vector<Aviao>, Prioridade3> auxfila1_a; 

    while(!auxfila.empty()){

        Aviao auxAviao = auxfila.top();

        auxAviao.setTempo(auxAviao.getTempo()-1);
        auxAviao.setTempoEspera(auxAviao.getTempoEspera()+1);
        auxfila1_a.push(auxAviao);
        auxfila.pop();
    }
    fila1_a = auxfila1_a;
}

int Pista3 :: contadorTempoDecolagemF1(){

    priority_queue<Aviao, vector<Aviao>, Prioridade3> auxfila = fila1_a;

    int contadorTempoDecolagemF1=0;

    while(!auxfila.empty()){

        Aviao aux = auxfila.top();

        if(aux.getID()%2==0){
            contadorTempoDecolagemF1 += aux.getTempoEspera();
        }
        auxfila.pop();
    }
    return contadorTempoDecolagemF1;   
}

int Pista3 :: tamanhoApenasDecolagem(){

    priority_queue<Aviao, vector<Aviao>, Prioridade3> auxfila = fila1_a;

    int contadorDecolagemF1=0;

    while(!auxfila.empty()){

        Aviao aux = auxfila.top();

        if(aux.getID()%2==0){
            contadorDecolagemF1 ++;
        }
        auxfila.pop();
    }

    return contadorDecolagemF1;
}

int Pista3 :: tamanhoApenasAterrissagem(){

    priority_queue<Aviao, vector<Aviao>, Prioridade3> auxfila = fila1_a;

    int contadorAterrisagemF1=0;

    while(!auxfila.empty()){

        Aviao aux = auxfila.top();

        if(aux.getID()%2 !=0){
            contadorAterrisagemF1++;
        }
        auxfila.pop();
    }
    return contadorAterrisagemF1;
}

float Pista3 :: mediaEsperaAterrissagemF1(){
    if (qtdAterrisagemF1 == 0){
        return 0;
    }
    else{
        return (tempoTotalEsperaAterrissagemF1/qtdAterrisagemF1);
    }    
}

float Pista3 :: diminuidoTotalF1(){

    if (qtdDiminuidoTotalF1==0){
        return 0;
    }
    else{
        return qtdDiminuidoTotalF1;
    }
}

float Pista3 :: mediaGlobalF1(){
    if (qtdDiminuidoTotalF1==0){
        return 0;
    }
    else{
        return (tempoTotalEsperaF1/qtdDiminuidoTotalF1);
    }
}

int Pista3 :: retornarEmergenciaF1(){

    priority_queue<Aviao, vector<Aviao>, Prioridade3> auxfila = fila1_a;
   int alerta=0;

    while(!auxfila.empty()){
        
        Aviao aux = auxfila.top();

        if(aux.getTempo()<=3){
            alerta++;
        }

        auxfila.pop();
    }

    return alerta;

}
