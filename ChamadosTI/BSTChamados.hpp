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

    //#### Declaração de metodos auxiliares para auxiliar na implementação dos publicos no cpp.
   
    NodeBST* inserIfBSTEmpity(NodeBST * noAtual, Chamado newChamado, NodeBST *pai);
    NodeBST* searchMenorNoBST(NodeBST * noAtual);
    void transplantNode(NodeBST * noAtual,NodeBST *noTransplant);

    NodeBST* searchNoBSTById(long id);

    void listarPorIntervalo( NodeBST* noAtual, long id1, long id2);
    
    
    public:
    BSTChamados();
    
    NodeBST* insertBST(NodeBST * noAtual, Chamado newChamado, NodeBST* pai);
    void insertChamadoBST(Chamado newChamado);
    long searchChamadoById(long id);
    void removeChamadoById(long id);

    
    
    long searchMenorId();
    long searchMaiorId();
    
    void listarChamadosPorIntervalo(long id1, long id2);
    int calcularAltura(NodeBST* noAtual);
    int countChamados(NodeBST* noAtual);
    void exibirPorNivel(NodeBST * noAtual);
    
    void listarEmOrdem(NodeBST * noAtual);
    void exibirPreOrdem(NodeBST * noAtual);
    void exibirPosOrdem(NodeBST * noAtual);
    
    NodeBST* getRoot();
    bool isEmpity();
    
};
#endif