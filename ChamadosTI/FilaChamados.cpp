#include "FilaChamados.hpp"

NoFila::NoFila(NodeBST* chamado) {
    this->chamadoReferencia = chamado;
    this->proximo = nullptr;
}

FilaChamado::FilaChamado() {
    frente = nullptr;
    tras = nullptr;
}

bool FilaChamado::filaVazia() {
    return frente == nullptr;
}

void FilaChamado::enfileirar(NodeBST* chamado) {
    NoFila* novoNo = new NoFila(chamado);

    if(filaVazia()) {
        frente = novoNo;
        tras = novoNo;
    }
    else {
        tras->proximo = novoNo;
        tras = novoNo;
    }
}

NodeBST* FilaChamado::desenfileirar() { 
    if(filaVazia()) {
        return nullptr;
    }
    
    NoFila* noRemover = frente;
    NodeBST* chamadoAtendido = noRemover->chamadoReferencia;

    frente = frente->proximo;

    if(frente == nullptr) {
        tras = nullptr;
    }

    delete noRemover;

    return chamadoAtendido;
}

NodeBST* FilaChamado::obterFrente() { 
    if(filaVazia()) {
        return nullptr; 
    }
    
    return frente->chamadoReferencia; 
}