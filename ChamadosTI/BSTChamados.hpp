#ifndef _BST_CHAMADOS_HPP_
#define _BST_CHAMADOS_HPP_

#include "NoArvore.hpp"
#include <string>

class ArvoreBST {
private:
    NoArvore* raiz;
    NoArvore* inserirRecursivo(NoArvore* noAtual, NoArvore* novoChamado);
    NoArvore* buscarRecursivo(NoArvore* noAtual, int idProcurado);
    void listarEmOrdemRecursivo(NoArvore* noAtual);

public:
    ArvoreBST();
    void cadastrarChamado(int id, std::string sol, std::string desc, CategoriaChamado cat, PrioridadeChamado pri);
    NoArvore* getRaiz();

    NoArvore* buscarChamado(int id);
    void listarChamados(); 
};

#endif