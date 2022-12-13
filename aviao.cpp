#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "aviao.hpp"
 
Aviao :: Aviao () {
    this -> setCompanhia(" ");
    this -> setPassageiro(0);
    this -> setID(0);
    this -> setTempo(0);
    this -> setTempoEspera(0);
}
 
Aviao :: Aviao (string companhia, int passageiro, int ID, int tempo_comb, int tempo_espera){
    this -> setCompanhia(companhia);
    this -> setPassageiro(passageiro);
    this -> setID(ID);
    this -> setTempo(tempo_comb);
    this -> setTempoEspera(tempo_espera);
}
 
void Aviao :: setCompanhia(string companhia){
    this -> companhia = companhia;
}
string Aviao :: getCompanhia() {
    return this -> companhia;
}
 
void Aviao :: setPassageiro(int passageiro){
    this -> passageiro = passageiro;
}
int Aviao :: getPassageiro() {
    return this -> passageiro;
}
 
void Aviao :: setID (int ID){
    this -> ID = ID;
}
int Aviao :: getID() {
    return this -> ID;
}
 
void Aviao :: setTempo (int tempo_comb){
    this -> tempo_comb = tempo_comb;
}
int Aviao :: getTempo() {
    return this -> tempo_comb;
}

void Aviao :: setTempoEspera (int tempo_espera){
    this -> tempo_espera = tempo_espera;
}
int Aviao :: getTempoEspera() {
    return this -> tempo_espera;
}

void Aviao :: imprimirAte(){
    cout << "\nCompanhia: " << this->getCompanhia() << endl;
    cout << "Passageiro(s): " << this->getPassageiro() << endl;
    cout << "ID: " << this->getID() << endl;
    if(getID()%2!=0){
        cout << "Reserva de combustivel: " << this->getTempo() << " minuto(s)."<< endl;
    }
    cout << "Esperando a: " << this->getTempoEspera() << " minuto(s)." << endl;
}
//imprime na main
void Aviao :: imprimirAte2(){
    cout << "\nCompanhia: " << this->getCompanhia() << endl;
    cout << "Passageiro(s): " << this->getPassageiro() << endl;
    cout << "ID: " << this->getID() << endl;
    cout << "Reserva de combustivel: " << this->getTempo() << " minuto(s)."<< endl;
    //cout << "Tempo de Espera: " << this->getTempoEspera() << " minuto(s)." << endl;
}

void Aviao :: imprimirDeco(){
    cout << "\nCompanhia: " << this->getCompanhia() << endl;
    cout << "Passageiro(s): " << this->getPassageiro() << endl;
    cout << "ID: " << this->getID() << endl;
    cout << "Esperando a: " << this->getTempoEspera() << " minuto(s)." << endl;
}
//imprime na main
void Aviao :: imprimirDeco2(){
    cout << "\nCompanhia: " << this->getCompanhia() << endl;
    cout << "Passageiro(s): " << this->getPassageiro() << endl;
    cout << "ID: " << this->getID() << endl;
    cout << "Esperando a: " << this->getTempoEspera() << " minuto(s)." << endl;
}

void Aviao :: inserir(){

    srand(time(NULL));
    int numPassegeiro=0,id=0,minutos=0;
    string companhia[4] = {"GOL", "LATAM", "AZUL", "American Airlines"};


    cout<<"\n\n\t - - [INSERINDO AVIÃO] - - \n";

    setCompanhia(companhia[rand()%4]);

    numPassegeiro = 1+rand()%300;
    cout<< "numero pass = "<<numPassegeiro;
    setPassageiro(numPassegeiro);

    id = 1+rand()%500;
    setID(id);
  
    minutos = 1+rand()%15;
    setTempo(minutos);

}

