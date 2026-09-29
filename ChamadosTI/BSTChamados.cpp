#ifndef _ARVORE_BST_HPP_
#define _ARVORE_BST_HPP_
#include "BSTChamados.hpp"
#include <iostream>


class ArvoreBST{
    private:
        NoArvore* raiz;

        NoArvore* inserirRecursivo(NoArvore* noAtual, NoArvore* novoChamado){
            if(noAtual == nullptr){
                return novoChamado;
            }

            if(novoChamado->idChamado < noAtual->idChamado){
                noAtual->esquerda = inserirRecursivo(noAtual->esquerda,novoChamado);
            }
            else if(novoChamado->idChamado > noAtual->idChamado){
                noAtual->direita = inserirRecursivo(noAtual->direita, novoChamado);
            }

            return noAtual;
        }

        public:
            ArvoreBST(){
                raiz = nullptr;
            }

            void cadastrarChamado(int id, std::string sol, std::string desc, CategoriaChamado cat, PrioridadeChamado pri ){
                NoArvore* novoChamado = new NoArvore(id, sol, desc, cat, pri);
                novoChamado->historico.insertListHistory("Data Atual", "Chamado Aberto");

                raiz = inserirRecursivo(raiz, novoChamado);
            }

            NoArvore* getRaiz(){
                return raiz;
            }
        
};

#endif