#ifndef _BST_CHAMADOS_
#define _BST_CHAMADOS_

#include <iostream>

#include "HistoricoChamados.hpp"
#include "CategoriaChamado.hpp"
#include "PrioridadeChamado.hpp"
#include "StatusChamado.hpp"

using namespace std;

struct Chamado{
    long id;
    string descricao;
    CategoriaChamado Categoria;
    PrioridadeChamado prioridade;
    StatusChamado status;

    HistoricoChamados * historico;
};


struct NodeBST{
  
    Chamado chamado;

    NodeBST * filhoEsqu;
    NodeBST * filhoDir;
    NodeBST * pai;

};


class BSTChamados{
private:

    NodeBST * root;
   
    NodeBST* inserIfBSTEmpity(NodeBST * noAtual, Chamado newChamado, NodeBST *pai);

public:
    BSTChamados();
    ~BSTChamados();

    NodeBST* insertBST(NodeBST * noAtual, Chamado newChamado, NodeBST* pai);
    void searchChamadoById(long id);
    void removeChamadoById(long id);
    void listarEmOrdemById();

    long searchMenorId();
    long searchMaiorId();

    int calcularAlturaBST();
    int countChamados();

    void listarIdPorIntervalo(long id1, long id2);
    void exibirPreOrdem();
    void exibirPosOrdem();
    void exibirPorNivel();

    bool isEmpity();

    void alterarStatusChamado();
    void registrarChamadosNoHistorico();
    
    
};

#endif