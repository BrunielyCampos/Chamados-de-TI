#ifndef _NO_ARVORE_HPP_
#define _NO_ARVORE_HPP_

#include <string>
#include "HistoricoChamados.hpp"
#include "StatusChamado.hpp"
#include "CategoriaChamado.hpp"
#include "PrioridadeChamado.hpp"

struct NoArvore{ 
    int idChamado;
    std::string solicitante;
    std::string descricao;
    StatusChamado status;
    CategoriaChamado categoria;
    PrioridadeChamado prioridade;

    HistoricoChamados historico;

    NoArvore* esquerda;
    NoArvore* direita;

    NoArvore(int id, std::string soli, std::string desc, CategoriaChamado cat, PrioridadeChamado pri){
        this->idChamado = id;
        this->solicitante = soli;
        this->descricao = desc;
        this->categoria = cat;
        this->prioridade = pri;

        this->status = StatusChamado::ABERTO;

        this->esquerda = nullptr;
        this->direita = nullptr;
    }
}; 

#endif