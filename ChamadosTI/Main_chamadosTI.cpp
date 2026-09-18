#include "HistoricoChamados.hpp" 
#include<iostream>

using namespace std;

int main(){
    
    HistoricoChamados lista;

    lista.insertListHistory("10:30, 08/09", "criação do chamado");
    lista.insertListHistory("10:35, 09/09", "Chamado aberto");
    lista.insertListHistory("10:09, 10/09", "Chamado resolvido");

    lista.printList();

    return 0;
}
