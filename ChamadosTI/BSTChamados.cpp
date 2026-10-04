#include "BSTChamados.hpp"
#include <iostream>

ArvoreBST::ArvoreBST() {
    raiz = nullptr;
}

NoArvore* ArvoreBST::inserirRecursivo(NoArvore* noAtual, NoArvore* novoChamado) {
    if (noAtual == nullptr) {
        return novoChamado;
    }

    if (novoChamado->idChamado < noAtual->idChamado) {
        noAtual->esquerda = inserirRecursivo(noAtual->esquerda, novoChamado);
    } 
    else if (novoChamado->idChamado > noAtual->idChamado) {
        noAtual->direita = inserirRecursivo(noAtual->direita, novoChamado);
    }

    return noAtual;
}

NoArvore* ArvoreBST::buscarRecursivo(NoArvore* noAtual, int idProcurado) {
    if (noAtual == nullptr || noAtual->idChamado == idProcurado) {
        return noAtual; 
    }

    if (idProcurado < noAtual->idChamado) {
        return buscarRecursivo(noAtual->esquerda, idProcurado);
    }
    
    return buscarRecursivo(noAtual->direita, idProcurado);
}

void ArvoreBST::listarEmOrdemRecursivo(NoArvore* noAtual) {
    if (noAtual != nullptr) {
        listarEmOrdemRecursivo(noAtual->esquerda);
        
        std::cout << "Chamado #" << noAtual->idChamado 
                  << " | Solicitante: " << noAtual->solicitante 
                  << " | Descricao: " << noAtual->descricao << std::endl;
        
        listarEmOrdemRecursivo(noAtual->direita);
    }
}

void ArvoreBST::cadastrarChamado(int id, std::string sol, std::string desc, CategoriaChamado cat, PrioridadeChamado pri) {
    NoArvore* novoChamado = new NoArvore(id, sol, desc, cat, pri);
    novoChamado->historico.insertListHistory("Data Atual", "Chamado Aberto");
    raiz = inserirRecursivo(raiz, novoChamado);
}

NoArvore* ArvoreBST::buscarChamado(int id) {
    return buscarRecursivo(raiz, id); 
}

void ArvoreBST::listarChamados() {
    if (raiz == nullptr) {
        std::cout << "Nenhum chamado registado no sistema." << std::endl;
        return;
    }
    
    std::cout << "--- LISTA DE CHAMADOS (ORDEM CRESCENTE) ---" << std::endl;
    listarEmOrdemRecursivo(raiz);
}

NoArvore* ArvoreBST::getRaiz() {
    return raiz;
}