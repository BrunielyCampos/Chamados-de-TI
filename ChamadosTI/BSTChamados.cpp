
#include "BSTChamados.hpp"

    BSTChamados::BSTChamados(){

    }

    BSTChamados::~BSTChamados(){

    }

    NodeBST* BSTChamados::insertBST(NodeBST* noAtual, Chamado newChamado, NodeBST* pai){

        if(noAtual == nullptr){
            inserIfBSTEmpity(noAtual, newChamado, pai);
            return;
        }

        if(newChamado.id < noAtual->chamado.id){

            noAtual->filhoEsqu =
                insertBST(noAtual->filhoEsqu, newChamado, noAtual);

        }
        else if(newChamado.id > noAtual->chamado.id){

            noAtual->filhoDir =
                insertBST(noAtual->filhoDir, newChamado, noAtual);

        }
        else{

            cout << "Esse valor já existe!!" << endl;
        }

        return noAtual;
    }

    NodeBST* inserIfBSTEmpity(NodeBST * noAtual, Chamado newChamado, NodeBST *pai){
          NodeBST* newNode = new NodeBST();

            newNode->chamado = newChamado;
            newNode->filhoEsqu = nullptr;
            newNode->filhoDir = nullptr;
            newNode->pai = pai;

            return newNode;
    }

    void BSTChamados::searchChamadoById(long id){

    }

    void BSTChamados::removeChamadoById(long id){

    }

    void BSTChamados::listarEmOrdemById(){

    }

    long BSTChamados::searchMenorId(){

    }

    long BSTChamados::searchMaiorId(){

    }

    int BSTChamados::calcularAlturaBST(){

    }

    int BSTChamados::countChamados(){

    }

    void BSTChamados::listarIdPorIntervalo(long id1, long id2){

    }

    void BSTChamados::exibirPreOrdem(){

    }

    void BSTChamados::exibirPosOrdem(){

    }

    void BSTChamados::exibirPorNivel(){

    }

    bool BSTChamados::isEmpity(){
        return root == nullptr;
    }
