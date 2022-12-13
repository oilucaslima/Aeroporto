#include "aviao.hpp"
#include "aeroporto.hpp"
#include <fstream>
#include <iostream>
#include <string>
 
using namespace std;

void aleatorio(){
    int TAM=0, op=0, idate=1, iddeco=2, tipo; 
    Aeroporto* aux_Aeroporto = new Aeroporto();
    string comp;

    do{
        srand(time(NULL));
            
        int aterri=1+rand()%3; //2
        int deco=1+rand()%3;//3

        TAM = aterri + deco;//5

        int limiteAterrissagem=0,limiteDecolagem=0;

        cout<<"\n\n\t - - [GERANDO AVIÃO] - - \n";

        for(int i=0;i<TAM;i++){

            int numPassegeiro=0,id=0, minutos=0, tempoEspera=0;
            string companhia[4] = {"GOL", "LATAM", "AZUL", "American Airlines"};


            comp=companhia[rand()%4];

            numPassegeiro = 1+rand()%300;

            if(limiteAterrissagem!=aterri || limiteDecolagem!=deco)
            {
                if(limiteAterrissagem<aterri)
                {
                    id=idate;
                    idate=idate+2;
                    limiteAterrissagem++;

                    minutos = 1+rand()%15; //15
                
                    Aviao aux_Aviao(comp,numPassegeiro,id,minutos,tempoEspera);
                    aux_Aeroporto->inserirPista(aux_Aviao);
                    aux_Aviao.imprimirAte2();

                }
                else if(limiteDecolagem<deco)
                {
                    id=iddeco;
                    iddeco=iddeco+2;
                    limiteDecolagem++;

                    minutos = 100;
                
                    Aviao aux_Aviao(comp,numPassegeiro,id,minutos,tempoEspera);
                    aux_Aeroporto->inserirPista(aux_Aviao);
                    aux_Aviao.imprimirDeco2();
                }    
            }
        }
        cout<<"\n\n\t - - [GERANDO AVIÃO] - - \n";
        
        aux_Aeroporto->imprimirPista1();
        aux_Aeroporto->imprimirPista2();
        aux_Aeroporto->imprimirPista3();
        aux_Aeroporto->alertaEmergencia();

        cout<<"\n\n(@) - Continuar digite (1) = -1 MIN : ";
        cin>>op;

        if(op==1){
            aux_Aeroporto->removendoDasPistas();
            aux_Aeroporto->atualizandoTempos_Pistas();
        }
        else{
            cout<<"\n\n [S] - Saindo ... ";
        }
        
    }while(op==1);
}

void arquivo(){

    ifstream arquivo;
    
    int contador=0,tamanhoAuxiliar=0, auxPassageiro, auxId, auxMinutos, auxTempoEspera,freeArquivo=0;
    Aeroporto* aux_Aeroporto = new Aeroporto();
    vector<Aviao>avioesPares;
    vector<Aviao>avioesImpares;
    string companhia = "", numPassegeiro = "" , id = "" , minutos = "", tempoEspera = "",caracteres;
    arquivo.open("avioes.txt" , ios::in);

    if(arquivo.is_open()){

        while(getline(arquivo,caracteres,'\n')){
            
            cout<<endl;
            companhia.clear();
            numPassegeiro.clear();
            id.clear();
            minutos.clear();
            tempoEspera.clear();

            for(int i=tamanhoAuxiliar; i<=caracteres.size(); i++){

                contador = 0;

                if(caracteres[i]!=','){
                    companhia = companhia + caracteres[i];
                }
                else{
                    tamanhoAuxiliar = i+1;
                    contador=1;
                    break;
                }
            } 

            if(contador==1){
                for(int i=tamanhoAuxiliar; i<caracteres.size(); i++){
                    if(caracteres[i] != ','){
                        numPassegeiro = numPassegeiro + caracteres[i];
                        auxPassageiro = stoi(numPassegeiro);

                    }
                    else{
                        tamanhoAuxiliar = i+1;
                        contador=2;
                        break;
                    }
                }
            }
        
            if(contador==2){
                for(int i=tamanhoAuxiliar; i<caracteres.size(); i++){
                    if(caracteres[i] != ','){
                        id = id + caracteres[i];
                        auxId = stoi(id);
                    }
                    else{
                        tamanhoAuxiliar = i+1;
                        contador=3;
                        break;
                    }
                }
            }
            
            if(contador==3){
                for(int i=tamanhoAuxiliar; i<caracteres.size(); i++){
                    if(caracteres[i] != ','){
                        minutos = minutos + caracteres[i];
                        auxMinutos = stoi(minutos);
                    }
                    else{
                        tamanhoAuxiliar = i+1;
                        contador=4;
                        break;
                    }
                }
            }
            
            if(contador==4){
                for(int i=tamanhoAuxiliar; i<caracteres.size(); i++){
                    if(caracteres[i] != '\n'){
                        tempoEspera = tempoEspera + caracteres[i];
                        auxTempoEspera = stoi(tempoEspera);
                    }

                    tamanhoAuxiliar = 0;
                    contador=0;
                }
            }

            if(auxId%2 == 0){
                auxMinutos=100;
                avioesPares.push_back(Aviao(companhia,auxPassageiro,auxId,auxMinutos,auxTempoEspera));
            }
            else{
                avioesImpares.push_back(Aviao(companhia,auxPassageiro,auxId,auxMinutos,auxTempoEspera));
            }

        }
        arquivo.close();
        freeArquivo = 1;
    }
    else{
        cout<< "\n\t [!] ERRO NO ARQUIVO";
    }

    /*
    if(freeArquivo==1){
        for(int i=0; i<avioesImpares.size(); i++){
            cout<<"\n\n[impares]";
            cout<<"\n\n Companhia: " << avioesImpares[i].getCompanhia();
            cout<<"\n Passageiro: " << avioesImpares[i].getPassageiro();
            cout<<"\n Id: " << avioesImpares[i].getID();
            cout<<"\n Tempo Comb.: " << avioesImpares[i].getTempo();
            cout<<"\n Tempo Espera.: "<<avioesImpares[i].getTempoEspera();
            cout<<"\n- - -";
        }

        for(int i=0; i<avioesPares.size(); i++){
            cout<<"\n\n[pares]";
            cout<<"\n\n Companhia: " << avioesPares[i].getCompanhia();
            cout<<"\n Passageiro: " << avioesPares[i].getPassageiro();
            cout<<"\n Id: " << avioesPares[i].getID();
            //cout<<"\n Tempo Comb.: " << avioesPares[i].getTempo();
            cout<<"\n Tempo Espera.: "<<avioesPares[i].getTempoEspera();
            cout<<"\n- - -";
            
        }

    }
    */

    if(freeArquivo==1){

        srand(time(NULL));
        int limiteAterrissagem=0, limiteDecolagem=0, TAM=0, deco=0, aterri=0, opcao=0, soma=0;
        
        do{

            if(avioesImpares.size() >= 3){
                aterri=1+rand()%3;
            }
            else{
                aterri = avioesImpares.size();
            }

            if(avioesPares.size() >= 3){
                deco=1+rand()%3; 
            }
            else{
                deco = avioesPares.size();
            }

            TAM = aterri + deco;

            cout<<"\n\n\t - - [INSERINDO AVIÃO] - - \n";

            if(avioesImpares.size()>0){
                for(int i=0; i<aterri; i++){
                    cout<<"\n\n Companhia: " << avioesImpares[i].getCompanhia();
                    cout<<"\n Passageiro: " << avioesImpares[i].getPassageiro();
                    cout<<"\n Id: " << avioesImpares[i].getID();
                    cout<<"\n Tempo Comb.: " << avioesImpares[i].getTempo();
                    cout<<"\n Tempo Espera.: "<<avioesImpares[i].getTempoEspera();
                    cout<<"\n- - -";
                    aux_Aeroporto->inserirPista(avioesImpares[i]);
                    limiteAterrissagem++;
                }
                avioesImpares.erase(avioesImpares.begin(), avioesImpares.begin()+aterri);
            }
            else{
                cout<<"\n\t [!] - FIM DE AVIÕES - [!] ";
            }
            
            if(avioesPares.size()>0){
                for(int i=0; i<deco; i++){
                    cout<<"\n\n Companhia: " << avioesPares[i].getCompanhia();
                    cout<<"\n Passageiro: " << avioesPares[i].getPassageiro();
                    cout<<"\n Id: " << avioesPares[i].getID();
                    //cout<<"\n Tempo Comb.: " << avioesPares[i].getTempo();
                    cout<<"\n Tempo Espera.: "<<avioesPares[i].getTempoEspera();
                    cout<<"\n- - -";
                    aux_Aeroporto->inserirPista(avioesPares[i]);
                    limiteDecolagem++;
                }
                avioesPares.erase(avioesPares.begin(), avioesPares.begin()+deco);
            }
            else{
                cout<<"\n\t [!] - FIM DE AVIÕES - [!] ";
            }

            cout<<"\n\n\t - - [INSERINDO AVIÃO] - - \n";

            aux_Aeroporto->imprimirPista1();
            aux_Aeroporto->imprimirPista2();
            aux_Aeroporto->imprimirPista3();
            aux_Aeroporto->alertaEmergencia();

            cout<<"\n\n(@) - Continuar digite (1) = -1 MIN : ";
            cin>>opcao;

            if(opcao==1){
                
                aux_Aeroporto->removendoDasPistas();
                aux_Aeroporto->atualizandoTempos_Pistas();
                soma = avioesPares.size()+avioesImpares.size();

                if(soma == 0){
                    cout<<"\n\t -[!] - [TODOS AVIOES DO ARQUIVO FORAM INSERIDOS] - [!] -";
                }
            }
            else{
                cout<<"\n\n [S] - Saindo ... ";
            }

        }while(opcao==1);


    }

}

int main(){

    int menu=0, continuar=1;

    do{
        cout<<"\n\n\t - - [AEROPORTO] - - ";
        cout<<"\n\n[1] - Inserir aviões aleatoriamente.";
        cout<<"\n[2] - Inserir aviões do arquivo.";
        cout<<"\n[0] - Sair.\n[>] - ";
        cin>>menu;

        switch(menu){

            case 1:
                aleatorio();
            break;

            case 2:
                arquivo();
            break;
        }

    }while(menu!=0);

    return 0;
}
