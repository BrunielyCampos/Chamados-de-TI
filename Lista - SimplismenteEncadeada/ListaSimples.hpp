#ifndef _LISTA_
#define _LISTA_

//#include "arquivoBst.hpp"

struct No{
    int valor; //Chamado chamadoLista;
    No * next;
};


class ListaSimples{
private:
    No * inicio;
    No * fim;


public:
    ListaSimples();

    void insertStart(int value);
    void insertEnd(int value);

    void searchElement(int value);
    void removeElement(int value);

    void exibirLista();

    bool listIsEmpity();
};

#endif