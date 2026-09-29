#ifndef _FILA_CHAMADOS_HPP_
#define _FILA_CHAMADOS_HPP_

#include "BSTChamados.hpp" 
struct NoFila {
    NoArvore* chamadoReferencia;
    NoFila* proximo;

    NoFila(NoArvore* chamado); 
};

class FilaChamado {
private:
    NoFila* frente;
    NoFila* tras;
    
public:
    FilaChamado();
    bool filaVazia();
    void enfileirar(NoArvore* chamado);
    NoArvore* desenfileirar();
    NoArvore* obterFrente();
};

#endif