#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "pista.hpp"

Pista :: Pista (){
    this->tempoTotalEsperaF1=0;
    this->qtdAterrisagemF1=0; 
    this->tempoTotalEsperaF2=0; 
    this->qtdAterrisagemF2=0;
}

void Pista :: inserirF1(Aviao aviao){
    fila1_a.push(aviao);
}

void Pista :: inserirF2(Aviao aviao){
    fila2_a.push(aviao);
}

void Pista :: inserirF3(Aviao aviao){
    fila3_d.push(aviao);
}

int Pista :: tamanhoF1(){
    return fila1_a.size();
}

int Pista :: tamanhoF2(){
    return fila2_a.size();
}

int Pista :: tamanhoF3(){
    return fila3_d.size();
}

int Pista :: retornarEmergenciaF1(){

   priority_queue<Aviao, vector<Aviao>, Prioridade > auxfila = fila1_a;
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

int Pista :: retornarEmergenciaF2(){

   priority_queue<Aviao, vector<Aviao>, Prioridade > auxfila = fila2_a;
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

void Pista :: imprimirF1(){
    
    priority_queue<Aviao, vector<Aviao>, Prioridade > auxfila = fila1_a;

    while(!auxfila.empty()){
        
        Aviao aux = auxfila.top();
        aux.imprimirAte();
        auxfila.pop();
    }

    quedaF1();

    cout<<"\n";
}

void Pista :: imprimirF2(){
    
    priority_queue<Aviao, vector<Aviao>, Prioridade > auxfila2 = fila2_a;

    while(!auxfila2.empty()){
        
        Aviao aux2 = auxfila2.top();
        aux2.imprimirAte();
        auxfila2.pop();
    }

    quedaF2();

    cout<<"\n";
}

void Pista :: imprimirF3(){

    queue<Aviao> auxfila3 = fila3_d;

    while(!auxfila3.empty()){
        
        auxfila3.front().imprimirDeco();
        auxfila3.pop();
    }
}

void Pista :: atualizandoTempoF1(){

    priority_queue<Aviao, vector<Aviao>, Prioridade> auxfila = fila1_a; 
    priority_queue<Aviao, vector<Aviao>, Prioridade> auxfila1_a; 

    while(!auxfila.empty()){

        Aviao auxAviao = auxfila.top();

        auxAviao.setTempo(auxAviao.getTempo()-1);
        auxAviao.setTempoEspera(auxAviao.getTempoEspera()+1);
        auxfila1_a.push(auxAviao);
        auxfila.pop();
    }
    fila1_a = auxfila1_a;
}

void Pista :: atualizandoTempoF2(){

    priority_queue<Aviao, vector<Aviao>, Prioridade> auxfila = fila2_a; 
    priority_queue<Aviao, vector<Aviao>, Prioridade> auxfila2_a; 

    while(!auxfila.empty()){

        Aviao auxAviao = auxfila.top();

       
        auxAviao.setTempo((auxAviao.getTempo())-1);
        auxAviao.setTempoEspera(auxAviao.getTempoEspera()+1);
        auxfila2_a.push(auxAviao);
        auxfila.pop();
        
        
    }
    fila2_a = auxfila2_a;
}

void Pista :: atualizandoTempoF3(){

    queue<Aviao> auxfila = fila3_d;
    queue<Aviao> auxfila3_d ;

    while(!auxfila.empty()){
        
        Aviao auxAviao = auxfila.front();
        auxAviao.setTempoEspera(auxAviao.getTempoEspera()+1);
        auxfila3_d.push(auxAviao);
        auxfila.pop();
    }
    fila3_d = auxfila3_d;
}

void Pista :: removerNaFila(){

    //verficando combustivel...
    int tempoTopoF1=0 , tempoTopoF2=0, freeRandomicoF1=0, freeRandomicoF2=0;

    Aviao topoF1;
    Aviao topoF2;

    if(!fila1_a.empty()){
        topoF1  = fila1_a.top();
        tempoTopoF1 = topoF1.getTempo();
    }

    if(!fila2_a.empty()){
        topoF2 = fila2_a.top();
        tempoTopoF2 = topoF2.getTempo();
    }

    // as duas filas não estiverem vazia
    if(fila1_a.size()!=0 && fila2_a.size()!=0){
        
        //aviao com emergencia
        if(tempoTopoF1<=3 && tempoTopoF2<=3){

            if(tempoTopoF1<tempoTopoF2){

                Aviao aux = fila1_a.top();
                tempoTotalEsperaF1 += aux.getTempoEspera();
                qtdAterrisagemF1++;
                fila1_a.pop();
            }
            else if(tempoTopoF2<tempoTopoF1){

                Aviao aux = fila2_a.top();
                tempoTotalEsperaF2 += aux.getTempoEspera();
                qtdAterrisagemF2++;
                fila2_a.pop();
            }
            else if(tempoTopoF1==tempoTopoF2){

                int tamF1=0, tamF2=0;

                tamF1 = tamanhoF1();
                tamF2 = tamanhoF2();

                if(tamF1>=tamF2){

                    Aviao aux = fila1_a.top();
                    tempoTotalEsperaF1 += aux.getTempoEspera();
                    qtdAterrisagemF1++;
                    fila1_a.pop();
                }
                else if(tamF2>=tamF1){

                    Aviao aux = fila2_a.top();
                    tempoTotalEsperaF2 += aux.getTempoEspera();
                    qtdAterrisagemF2++;
                    fila2_a.pop();
                }
           }
        }
        // caso tenha apenas uma emergencia
        else if(tempoTopoF1<=3){

            Aviao aux = fila1_a.top();
            tempoTotalEsperaF1 += aux.getTempoEspera();
            qtdAterrisagemF1++;
            fila1_a.pop();
        }
        else if(tempoTopoF2<=3){
            Aviao aux = fila2_a.top();
            tempoTotalEsperaF2 += aux.getTempoEspera();
            qtdAterrisagemF2++;
            fila2_a.pop();
        }
        else if(tempoTopoF1>=3 && tempoTopoF2>=3){
            freeRandomicoF1=1;
            freeRandomicoF2=1;
        }

    }
    else if(fila1_a.size()!=0 && fila2_a.size()==0){
        // caso a outra fila vazia e uma emergencia
        if(tempoTopoF1<=3){
            Aviao aux = fila1_a.top();
            tempoTotalEsperaF1 += aux.getTempoEspera();
            qtdAterrisagemF1++;
            fila1_a.pop();
        }
        else{
            freeRandomicoF1=1;
        }
    }
    else if(fila1_a.size()==0 && fila2_a.size()!=0){

        if(tempoTopoF2<=3){
            Aviao aux = fila2_a.top();
            tempoTotalEsperaF2 += aux.getTempoEspera();
            qtdAterrisagemF2++;
            fila2_a.pop();
        }
        else{
            freeRandomicoF2=1;
        }
    }
    else{
       if(fila3_d.size()!=0){
            Aviao aux = fila3_d.front();
            tempoTotalEsperaF3 += aux.getTempoEspera();
            qtdDecolagemF3++;
            fila3_d.pop();
        }
    }

    if((freeRandomicoF1==1 && freeRandomicoF2==1) || (freeRandomicoF1==1 && freeRandomicoF2!=1) || (freeRandomicoF1!=1 && freeRandomicoF2==1)){

        int sorteio=0;

        srand(time(NULL));
        sorteio = 1+rand()%2;
        
        //removendo na aterissagem
        if(sorteio==1){
            int tamF1=0, tamF2=0, tamF3=0;

            tamF1 = tamanhoF1();
            tamF2 = tamanhoF2();
            tamF3 = tamanhoF3();

            if((tamF3>tamF1) && (tamF3>tamF2) && (tamF3!=0)){
                Aviao aux = fila3_d.front();
                tempoTotalEsperaF3 += aux.getTempoEspera();
                qtdDecolagemF3++;
                fila3_d.pop();
            }
            else if(fila1_a.size()!=0 || fila2_a.size()!=0){

                if(tamF1>=tamF2){

                    Aviao aux = fila1_a.top();
                    tempoTotalEsperaF1 += aux.getTempoEspera();
                    qtdAterrisagemF1++;
                    fila1_a.pop();
                }
                else if(tamF2>=tamF1){

                    Aviao aux = fila2_a.top();
                    tempoTotalEsperaF2 += aux.getTempoEspera();
                    qtdAterrisagemF2++;
                    fila2_a.pop();
                }
            }
            else{
                if (fila3_d.size()!=0){
                    Aviao aux = fila3_d.front();
                    tempoTotalEsperaF3 += aux.getTempoEspera();
                    qtdDecolagemF3++;   
                    fila3_d.pop();
                }
                else{
                    cout << "\nPista vazia.";
                }
            }
        }
        if(sorteio==2){

            int tamF1=0, tamF2=0;

            tamF1 = tamanhoF1();
            tamF2 = tamanhoF2();

            if(fila3_d.size()!=0){
                Aviao aux = fila3_d.front();
                tempoTotalEsperaF3 += aux.getTempoEspera();
                qtdDecolagemF3++;
                fila3_d.pop();
            }
            else{
                if(fila1_a.size()!=0 || fila2_a.size()!=0){

                    if(tamF1>=tamF2){
                        Aviao aux = fila1_a.top();
                        tempoTotalEsperaF1 += aux.getTempoEspera();
                        qtdAterrisagemF1++;
                        fila1_a.pop();
                    }
                    else if(tamF2>=tamF1){
                        Aviao aux = fila2_a.top();
                        tempoTotalEsperaF2 += aux.getTempoEspera();
                        qtdAterrisagemF2++;
                        fila2_a.pop();
                    }
                }
                else{
                    cout << "\nPista vazia.";
                }
            }
        }
    }
}

int Pista :: contadorTempoDecolagemF3(){

    queue<Aviao> auxfila = fila3_d;
    int contadorTempoDecolagemF3=0;

    while(!auxfila.empty()){

        Aviao aux = auxfila.front();
        contadorTempoDecolagemF3 += aux.getTempoEspera();
        auxfila.pop();
    }

    return contadorTempoDecolagemF3;
    
}

float Pista :: mediaEsperaAterrissagemF1(){
    if (qtdAterrisagemF1 == 0){
        return 0;
    }
    else{
        return (tempoTotalEsperaF1/qtdAterrisagemF1);
    }    
}

float Pista :: mediaEsperaAterrissagemF2(){
    if (qtdAterrisagemF2 == 0){
        return 0;
    }
    else{
        return (tempoTotalEsperaF2/qtdAterrisagemF2);
    } 
}

float Pista :: mediaEsperaDecolagemF3(){
    if (qtdDecolagemF3 == 0){
        return 0;
    }
    else{
        return (tempoTotalEsperaF3/qtdDecolagemF3);
    } 
}

void Pista :: quedaF1(){

    priority_queue<Aviao, vector<Aviao>, Prioridade> auxfila = fila1_a; 
    priority_queue<Aviao, vector<Aviao>, Prioridade> auxfila1_a; 

    while(!auxfila.empty()){

        Aviao auxAviao = auxfila.top();

        if(auxAviao.getTempo()<=0){
            cout<<"\n\t [!] - AVIÃO CAIU - [!] ";
            cout<<"\n\t\t - ID: "<<auxAviao.getID();
            auxfila.pop();
        }
        else{
            auxfila1_a.push(auxAviao);
            auxfila.pop();
        }   
    }
    fila1_a = auxfila1_a;
}

void Pista :: quedaF2(){

    priority_queue<Aviao, vector<Aviao>, Prioridade> auxfila = fila2_a; 
    priority_queue<Aviao, vector<Aviao>, Prioridade> auxfila2_a; 

    while(!auxfila.empty()){

        Aviao auxAviao = auxfila.top();

        if(auxAviao.getTempo()<=0){
            cout<<"\n\t [!] - AVIÃO CAIU - [!] ";
            cout<<"\n\t\t - ID: "<<auxAviao.getID();
            auxfila.pop();
        }
        else{
            auxfila2_a.push(auxAviao);
            auxfila.pop();
        }   
    }
    fila2_a = auxfila2_a;
}