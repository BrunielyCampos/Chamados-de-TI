#include "HistoricoChamados.hpp" 
#include "BSTChamados.hpp"
#include "CategoriaChamado.hpp"
#include "PrioridadeChamado.hpp"
#include "StatusChamado.hpp"
#include<iostream>

using namespace std;

int main(){

    
    HistoricoChamados lista;
    
    BSTChamados bst;

    Chamado newChamado;

    newChamado.id = 2220;
    newChamado.descricao = "Concerto de teclado de notebook quebrado";
    newChamado.Categoria = CategoriaChamado::HARDWARE;
    newChamado.prioridade = PrioridadeChamado::ALTA;
    newChamado.status = StatusChamado::ABERTO;

    bst.insertChamadoBST(newChamado);

    // if (bst.getRoot() == nullptr) {
    // cout << "A raiz continua vazia!" << endl;   
    // } else {
    // cout << "Raiz criada! ID: "
    //      << bst.getRoot()->chamado.id << endl;
    // }

    bst.listarEmOrdem(bst.getRoot());

    lista.insertListHistory("10:30, 08/09", "criação do chamado");
    lista.insertListHistory("10:35, 09/09", "Chamado aberto");
    lista.insertListHistory("10:09, 10/09", "Chamado resolvido");

    lista.printList();
    
    return 0;
}
