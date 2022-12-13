#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "aeroporto.hpp"

int totalAviaoDecolagem1_F3=0,totalAviaoDecolagem2_F3=0,totalAviaoDecolagem3_F1=0;
int avioesEmergencia=0;

Aeroporto :: Aeroporto (){
    p1 = new Pista();
    p2 = new Pista();
    p3 = new Pista3();
    
}

void Aeroporto :: setPista1(Pista* p1){
    this -> p1 = p1;
}

Pista* Aeroporto :: getPista1(){
    return this-> p1;
}

void Aeroporto :: setPista2(Pista* p2){
    this -> p2 = p2;
}

Pista* Aeroporto :: getPista2(){
    return this-> p2;
}

void Aeroporto :: setPista3(Pista3* p3){
    this -> p3 = p3;
}

Pista3* Aeroporto :: getPista3(){
    return this-> p3;
}

void Aeroporto :: inserirPista(Aviao aviao){

    int par=0, impar=0, auxID = 0;

    auxID = aviao.getID();

   
    if(auxID%2 == 0){

        //Decolagem
        int tam1=0, tam2=0, tam3=0;
        int auxTempoDecolagem = 0;

        //decolagem
        tam1 = p1->tamanhoF3();
        tam2 = p2->tamanhoF3();        
        tam3 = p3->tamanhoF1();
    
        if((tam1==tam2) && (tam2==tam3)){
            p1->inserirF3(aviao);  
        }
        else if ((tam1<=tam2) && (tam1<=tam3)){
            p1->inserirF3(aviao);
        }
        else if((tam2<=tam1) && (tam2<=tam3)){
            p2->inserirF3(aviao);
        }
        else if((tam3<=tam1) && (tam3<=tam2)){
            p3->inserirF1(aviao);
        }
    }
    else{

        // Aterrissagem
        int tam1, tam2, tam3, tam4, tam5, tam6, tam7, tam8;
        int tamanhoaux=0, id=0, emergencia=0;

        emergencia = p3->tamanhoApenasAterrissagem();

        //Pista 1
        tam1 = p1->tamanhoF1();
        tam2 = p1->tamanhoF2();
        //Pista 2
        tam3 = p2->tamanhoF1();
        tam4 = p2->tamanhoF2();
        //Pista 3
        //emergencia...
        tam5 = p3->tamanhoF1(); 

        //decolagem
        tam6 = p1->tamanhoF3();
        tam7 = p2->tamanhoF3();

        //inserir com emergencia...
        if(aviao.getTempo()<=3){

            avioesEmergencia++;

            if(emergencia==0){
                p3->inserirF1(aviao);
            }
            else if(tam1==0){
                p1->inserirF1(aviao);
            }
            else if(tam2==0){
                p1->inserirF2(aviao);
            }
            else if(tam3==0){
                p2->inserirF1(aviao);
            }
            else if(tam4==0){
                p2->inserirF2(aviao);
            }
            else{

                if((emergencia<=tam1) && (emergencia<=tam2) && (emergencia<=tam3) && (emergencia<=tam4)){
                    p3->inserirF1(aviao);
                }
                else if((tam1<=tam2) && (tam1<=tam3) && (tam1<=tam4) && (tam1<=emergencia)){ 
                    p1->inserirF1(aviao); 
                }
                else if((tam2<=tam1) && (tam2<=tam3) && (tam2<=tam4) && (tam2<=emergencia)){
                    p1->inserirF2(aviao);
                }
                else if((tam3<=tam1) && (tam3<=tam2) && (tam3<=tam4) && (tam3<=emergencia)){
                    p2->inserirF1(aviao);
                }
                else if((tam4<=tam1) && (tam4<=tam2) && (tam4<=tam3) && (tam4<=emergencia)){
                    p2->inserirF2(aviao);
                }
                
                
            }

        }
        else{

            int auxTempoEspera=0;

            // Sem emergencia...
            if((tam1<=tam2) && (tam1<=tam3) && (tam1<=tam4)){
                p1->inserirF1(aviao);
            }
            else if((tam2<=tam1) && (tam2<=tam3) && (tam2<=tam4)){
                p1->inserirF2(aviao);
            }
            else if((tam3<=tam1) && (tam3<=tam2) && (tam3<=tam4)){
                p2->inserirF1(aviao);
            }
            else if((tam4<=tam1) && (tam4<=tam2) && (tam4<=tam3)){
                p2->inserirF2(aviao);
            }
            
        }
    }
}

void Aeroporto :: removendoDasPistas(){
    
    p1->removerNaFila();
    p2->removerNaFila();
    p3->removerNaFila();
}

void Aeroporto :: imprimirPista1(){

    float totalTempoDecolagem,tamanhoDecolagem, mediaDecolagem;
    float mediaAterrisagemF1, mediaAterrisagemF2, mediaDecolaramF3;
    float mediaGlobal;

    cout<<"\n\n\t____________________ PISTA [1] ____________________";

    cout<<"\n\n >>>> FILA - [1] - Aterrisagem <<<<\n";
    p1->imprimirF1();
    mediaAterrisagemF1 = p1->mediaEsperaAterrissagemF1();
    cout<<"\n---Tempo médio de espera para Aterrissar: "<<mediaAterrisagemF1<<" minutos.\n";


    cout<<"\n >>>> FILA - [2] - Aterrisagem <<<<\n";
    p1->imprimirF2();
    mediaAterrisagemF2 = p1->mediaEsperaAterrissagemF2();
    cout<<"\n---Tempo médio de espera para Aterrissar: "<<mediaAterrisagemF2<<" minutos.\n";

    cout<<"\n >>>> FILA - [3] - Decolagem <<<<\n";
    p1->imprimirF3();

    totalTempoDecolagem= p1->contadorTempoDecolagemF3();
    tamanhoDecolagem = p1->tamanhoF3()+0;
    mediaDecolagem = totalTempoDecolagem / tamanhoDecolagem;

    if(tamanhoDecolagem==0){
        cout<<"\n---Tempo médio de espera: 0 minutos."; 
    }
    else{
        cout<<"\n---Tempo médio de espera para Decolar: "<<mediaDecolagem<<" minutos.\n"; 
    } 

    mediaDecolaramF3 = p1->mediaEsperaDecolagemF3();
    mediaGlobal = ((mediaAterrisagemF1+mediaAterrisagemF2+mediaDecolaramF3)/3);

    if ((mediaAterrisagemF1 != 0) || (mediaAterrisagemF2!=0) || (mediaDecolaramF3!=0)){
        cout<<"\n\n\t---[Tempo médio global de espera: " << mediaGlobal << " minutos]---";
    }
    else{
        cout<<"\n\n\t---[Tempo médio global de espera: 0 minutos]---";
    }

}

void Aeroporto :: imprimirPista2(){

    float totalTempoDecolagem,tamanhoDecolagem, mediaDecolagem;
    float mediaAterrisagemF1, mediaAterrisagemF2, mediaDecolaramF3=0;
    float mediaGlobal=0;

    cout<<"\n\n\t____________________ PISTA [2] ____________________";

    cout<<"\n\n >>>> FILA - [1] - Aterrisagem <<<<\n";
    p2->imprimirF1();
    mediaAterrisagemF1 = p2->mediaEsperaAterrissagemF1();
    cout<<"\n---Tempo médio de espera para Aterrissar: "<<mediaAterrisagemF1<<" minutos.\n";

    cout<<"\n >>>> FILA - [2] - Aterrisagem <<<<\n";
    p2->imprimirF2();
    mediaAterrisagemF2 = p2->mediaEsperaAterrissagemF2();
    cout<<"\n---Tempo médio de espera para Aterrissar: "<<mediaAterrisagemF2<<" minutos.\n";

    cout<<"\n >>>> FILA - [3] - Decolagem <<<<\n";
    p2->imprimirF3();

    totalTempoDecolagem= p2->contadorTempoDecolagemF3();
    tamanhoDecolagem = p2->tamanhoF3()+0;
    mediaDecolagem = totalTempoDecolagem / tamanhoDecolagem;

    if(tamanhoDecolagem==0){
        cout<<"\n---Tempo médio de espera: 0 minutos."; 
    }
    else{
        cout<<"\n---Tempo médio de espera para Decolar: "<<mediaDecolagem<<" minutos.\n"; 
    }         

    mediaDecolaramF3 = p2->mediaEsperaDecolagemF3();
    mediaGlobal = ((mediaAterrisagemF1+mediaAterrisagemF2+mediaDecolaramF3)/3);

    if ((mediaAterrisagemF1 != 0) || (mediaAterrisagemF2!=0) || (mediaDecolaramF3!=0)){
        cout<<"\n\n\t---[Tempo médio global de espera: " << mediaGlobal << " minutos]---";
    }
    else{
        cout<<"\n\n\t---[Tempo médio global de espera: 0 minutos]---";
    }
}

void Aeroporto :: imprimirPista3(){

    float totalTempoDecolagem,totalAviaoDecolagem,mediaDecolagem, mediaAterrisagem;
    float mediaGlobal;

    cout<<"\n\n\t____________________ PISTA [3] ____________________";

    cout<<"\n\n >>>> FILA - [1] - DEC // ATE [URGENTE] <<<<\n";
    p3->imprimirF1();

    totalTempoDecolagem = p3->contadorTempoDecolagemF1();
    totalAviaoDecolagem = p3->tamanhoApenasDecolagem();
    mediaDecolagem = totalTempoDecolagem / totalAviaoDecolagem;

    if(totalAviaoDecolagem==0){
        cout<<"\n---Tempo médio de espera: 0 minutos."; 
    }
    else{
        cout<<"\n---Tempo médio de espera para Decolar: "<<mediaDecolagem<<" minutos.\n"; 
    } 
    mediaAterrisagem = p3->mediaEsperaAterrissagemF1();
    cout<<"\n---Tempo médio de espera para Aterrisar: "<<mediaAterrisagem<<" minutos.\n";

    mediaGlobal = p3->mediaGlobalF1();
    cout<<"\n\n\t---[Tempo médio global de espera: " << mediaGlobal << " minutos]---";

    cout<<"\n\n\n\t [!] - AVIÕES EMERGENCIAIS ATENDIDOS = "<<avioesEmergencia<<" - [!]\n";
}

void Aeroporto :: atualizandoTempos_Pistas(){


    p1->atualizandoTempoF1();
    p1->atualizandoTempoF2();
    p1->atualizandoTempoF3();

    p2->atualizandoTempoF1();
    p2->atualizandoTempoF2();
    p2->atualizandoTempoF3();

    p3->atualizandoTempoF1();
     
}

void Aeroporto :: alertaEmergencia(){

    int alerta1_1, alerta1_2;
    int alerta2_1, alerta2_2;
    int alerta3_1, soma;

    alerta1_1 = p1->retornarEmergenciaF1();
    alerta1_2 = p1->retornarEmergenciaF2();
    alerta2_1 = p2->retornarEmergenciaF1();
    alerta2_2 = p2->retornarEmergenciaF2();
    alerta3_1 = p3->retornarEmergenciaF1();

    soma = alerta1_1 + alerta1_2 + alerta2_1 + alerta2_2 + alerta3_1;

    if(soma>=3){
        cout<<"\n\n\t\t [!] ALERTA ESTADO CRITICO [!]";
    }

}

