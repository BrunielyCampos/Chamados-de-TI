#include "ListaSimples.hpp"

#include<iostream>

int main(){

    ListaSimples lista;

    lista.insertStart(30);
    lista.insertStart(40);
    lista.insertStart(50);
    lista.insertEnd(65);

    lista.exibirLista();

    lista.removeElement(60);
    lista.removeElement(65);

    lista.exibirLista();


    return 0;
}
