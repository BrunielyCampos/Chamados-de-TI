#include "FilaChamados.hpp"

NoFila::NoFila(NoArvore* chamado) {
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

void FilaChamado::enfileirar(NoArvore* chamado) {
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

NoArvore* FilaChamado::desenfileirar() { 
    if(filaVazia()) {
        return nullptr;
    }
    
    NoFila* noRemover = frente;
    NoArvore* chamadoAtendido = noRemover->chamadoReferencia;

    frente = frente->proximo;

    if(frente == nullptr) {
        tras = nullptr;
    }

    delete noRemover;

    return chamadoAtendido;
}

NoArvore* FilaChamado::obterFrente() { 
    if(filaVazia()) {
        return nullptr; 
    }
    
   
    return frente->chamadoReferencia; 
}