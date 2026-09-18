#include "HistoricoChamados.hpp" 
#include<iostream>

using namespace std;

    HistoricoChamados::HistoricoChamados(){
        noLista = nullptr;
    }

    void HistoricoChamados::insertListHistory(string dateTime, string descricao){
        
        if (isEmpity()){
            insertIfListEmpity(dateTime, descricao);
            return;
        }      

        NoHistory * aux = noLista;

        while (aux->next != nullptr){
           aux = aux->next;
        }

        NoHistory * newNode = new NoHistory();
        newNode->dateTime = dateTime;
        newNode->descricao = descricao;
        aux->next = newNode;
        newNode->next = nullptr;
    }

    void HistoricoChamados::insertIfListEmpity(string dateTime, string descricao){
            NoHistory * newNode = new NoHistory();
            newNode->dateTime = dateTime;
            newNode->descricao = descricao;
            newNode->next = nullptr;
            noLista = newNode;
    }

    void HistoricoChamados::printList(){

        NoHistory * aux = noLista;
        while (aux->next != nullptr){
            aux = aux->next;

            cout<< " " << aux->dateTime << " " << aux->descricao <<endl;
            
        }

    }

    bool HistoricoChamados::isEmpity(){
        return noLista == nullptr;
    }