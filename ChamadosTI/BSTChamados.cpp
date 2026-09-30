
#include "BSTChamados.hpp"

    BSTChamados::BSTChamados(){
        root = nullptr;

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

    long BSTChamados::searchChamadoById(long id){
 
        NodeBST * aux = root; 

        if (isEmpity()){
            cout<<"AVISO: A arvore está vazia a busca não sera possivel!"<< endl;
            return -1;
        }        

        if (aux->chamado.id == id){
          return id;  
        }

        
        while (aux != nullptr && (aux->chamado.id != id)){
            if (aux->chamado.id < id){
                aux = aux->filhoDir;
                
            }
            else if (aux->chamado.id > id){
                aux = aux->filhoEsqu;
              
            }
           
        } 

        if (aux == nullptr){
            cout << "AVISO: Id do chamado não encontrado" << endl;
            return -1;
        }
        
        cout << "Id encontrado: " << aux->chamado.id << endl;
        return aux->chamado.id;
        
    }

    NodeBST* BSTChamados::searchNoBSTById(long id){

        NodeBST * noAtual = root;

        if (isEmpity()){
            cout<<"AVISO: A arvore está vazia a busca não sera possivel!"<< endl;
            return nullptr;
        }        

        if (noAtual->chamado.id == id){
          return noAtual;  
        }

        
        while (noAtual != nullptr && (noAtual->chamado.id != id)){
            if (noAtual->chamado.id < id){
                noAtual = noAtual->filhoDir;
                
            }
            else if (noAtual->chamado.id > id){
                noAtual = noAtual->filhoEsqu;
              
            }
           
        } 

        if (noAtual == nullptr){
            cout << "AVISO: Id do chamado não encontrado" << endl;
            return nullptr;
        }
        

        return noAtual;
    }


    void BSTChamados::removeChamadoById(long id){

        NodeBST * noAtual = searchNoBSTById(id);

        if (noAtual == nullptr){
            cout << "No vazio" << endl;
            return;
        }
        
        if (noAtual->filhoEsqu == nullptr){
            transplantNode(noAtual, noAtual->filhoDir);
        }
        else if (noAtual->filhoDir == nullptr){
            transplantNode(noAtual, noAtual->filhoEsqu);
        }
        else{
            NodeBST * sucessor = searchMenorNoBST(noAtual->filhoDir);

            if (sucessor->pai != noAtual){
                transplantNode(sucessor, sucessor->filhoDir);
                sucessor->filhoDir = noAtual->filhoDir;
                sucessor->filhoDir->pai = sucessor;
            }
            transplantNode(noAtual, sucessor);
            sucessor->filhoEsqu = noAtual->filhoEsqu;
            noAtual->filhoEsqu->pai = sucessor;

            delete noAtual;
        }
        
    }

    void BSTChamados::transplantNode(NodeBST * noAtual,NodeBST *noTransplant){
        
        if (noAtual->pai == nullptr){
            root = noTransplant;
        }
        else if (noAtual == noAtual->pai->filhoEsqu){
            noAtual->pai->filhoEsqu = noTransplant;
        }
        else{
            noAtual->pai->filhoDir = noTransplant;
        }

        if (noTransplant != nullptr){
            noTransplant->pai = noAtual->pai;
        }
        
    }

    long BSTChamados::searchMenorId(){
        NodeBST * aux = root; 
       
        if (isEmpity()){
            cout<<"AVISO: A arvore está vazia a busca não sera possivel!"<< endl;
            return -1;
        }        
        
        while (aux->filhoEsqu != nullptr){
            aux = aux->filhoEsqu;
        } 

        cout << "Menor Id encontrado: " << aux->chamado.id << endl;
        return aux->chamado.id;
    }

    NodeBST* BSTChamados::searchMenorNoBST(NodeBST * noAtual){
      
        if (noAtual == nullptr){
             cout<<"AVISO: A sub arvore está vazia a busca não sera possivel!"<< endl;
            return nullptr;
        }
        
        while (noAtual->filhoEsqu != nullptr){
            noAtual = noAtual->filhoEsqu;
        } 

        return noAtual;
    } 
    
    long BSTChamados::searchMaiorId(){
         NodeBST * aux = root; 
       
        if (root == nullptr){
            cout<<"AVISO: A arvore está vazia a busca não sera possivel!"<< endl;
            return -1;
        }        
        
        while (aux->filhoDir != nullptr){
            aux = aux->filhoDir;
        } 

        
        cout << "Maior Id encontrado: " << aux->chamado.id << endl;
        return aux->chamado.id;
    }
    
    int BSTChamados::calcularAlturaBST(){
        
    }
    
    int BSTChamados::countChamados(){
        
    }
    
    void BSTChamados::listarIdPorIntervalo(long id1, long id2){

    }
    
    void BSTChamados::exibirPorNivel(NodeBST * noAtual){
        
    }
    
    void BSTChamados::exibirPreOrdem(NodeBST * noAtual){
        
        if (noAtual == nullptr){
            cout<< "Arvore vazia!"<< endl;
        }
        
        cout<< " " << noAtual->chamado.id;
        exibirPreOrdem(noAtual->filhoEsqu);
        exibirPreOrdem(noAtual->filhoDir);
    }

    void BSTChamados::listarEmOrdem(NodeBST * noAtual){

        if (noAtual == nullptr){
            cout<< "Arvore vazia!"<< endl;
        }

        listarEmOrdem(noAtual->filhoEsqu);
        cout<< " " << noAtual->chamado.id;
        listarEmOrdem(noAtual->filhoDir);

        cout<< endl;
    }
    
    void BSTChamados::exibirPosOrdem(NodeBST * noAtual){

        if (noAtual == nullptr){
            cout<< "Arvore vazia!"<< endl;
        }

        exibirPosOrdem(noAtual->filhoEsqu);
        exibirPosOrdem(noAtual->filhoDir);
        cout<< " " << noAtual->chamado.id;
    }


    bool BSTChamados::isEmpity(){
        return root == nullptr;
    }
