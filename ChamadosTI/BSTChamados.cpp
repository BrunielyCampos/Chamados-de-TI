
#include "BSTChamados.hpp"
#include <queue>

    BSTChamados::BSTChamados(){
        root = nullptr;

    }

    NodeBST* BSTChamados::insertBST(NodeBST* noAtual, Chamado newChamado, NodeBST* pai){

        if(noAtual == nullptr){
            return inserIfBSTEmpity(noAtual, newChamado, pai);
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

    void BSTChamados::insertChamadoBST(Chamado newChamado) {
        root = insertBST(root, newChamado, nullptr);
    }

    NodeBST* BSTChamados::inserIfBSTEmpity(NodeBST * noAtual, Chamado newChamado, NodeBST *pai){
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
    
    int BSTChamados::calcularAltura(NodeBST* noAtual){

        if (noAtual == nullptr){
            return 0;
        }

        int contEsq = calcularAltura(noAtual->filhoEsqu);
        int contDir = calcularAltura(noAtual->filhoDir);

        if (contEsq > contDir){
            return contEsq + 1;
        }
        else{
            return contDir + 1;
        }
    }
    
    int BSTChamados::countChamados(NodeBST* noAtual) {
        if (noAtual == nullptr) {
            return 0;
        }

        int contEsq = countChamados(noAtual->filhoEsqu);
        int contDir = countChamados(noAtual->filhoDir);

        return 1 + contEsq + contDir;
    }
    
    void BSTChamados::listarPorIntervalo(
        NodeBST* noAtual, long id1, long id2) {

        if (noAtual == nullptr) {
            return;
        }

        if (id1 < noAtual->chamado.id) {
            listarPorIntervalo(noAtual->filhoEsqu, id1, id2);
        }

        if (noAtual->chamado.id >= id1 &&
            noAtual->chamado.id <= id2) {
            cout << noAtual->chamado.id << " ";
        }

        if (id2 > noAtual->chamado.id) {
            listarPorIntervalo(noAtual->filhoDir, id1, id2);
        }
    }
    
    void BSTChamados::exibirPorNivel(NodeBST* noAtual) {
        if (noAtual == nullptr) {
            return;
        }

        queue<NodeBST*> fila;
        fila.push(noAtual);

        while (!fila.empty()) {
            NodeBST* noAtual = fila.front();
            fila.pop();

            cout << noAtual->chamado.id << " ";

            if (noAtual->filhoEsqu != nullptr) {
                fila.push(noAtual->filhoEsqu);
            }

            if (noAtual->filhoDir != nullptr) {
                fila.push(noAtual->filhoDir);
            }
        }

        cout << endl;
    }

// #### FIM METODOS AUXILIARES DA BST


    void BSTChamados::listarChamadosPorIntervalo(long id1, long id2) {
        if (id1 > id2) {
            return;
        }

        listarPorIntervalo(root, id1, id2);
        cout << endl;
    }

    
    void BSTChamados::exibirPreOrdem(NodeBST * noAtual){
        
        if (noAtual == nullptr){
            return;
        }
        
        cout<< " " << noAtual->chamado.id;
        exibirPreOrdem(noAtual->filhoEsqu);
        exibirPreOrdem(noAtual->filhoDir);
    }

    void BSTChamados::listarEmOrdem(NodeBST * noAtual){

        if (noAtual == nullptr){
            return;
        }

        listarEmOrdem(noAtual->filhoEsqu);
        cout<< " " << noAtual->chamado.id;
        listarEmOrdem(noAtual->filhoDir);

    }
    
    void BSTChamados::exibirPosOrdem(NodeBST * noAtual){

        if (noAtual == nullptr){
            return;
        }

        exibirPosOrdem(noAtual->filhoEsqu);
        exibirPosOrdem(noAtual->filhoDir);
        cout<< " " << noAtual->chamado.id;
    }

    NodeBST* BSTChamados::getRoot(){
        return root;
    }


    bool BSTChamados::isEmpity(){
        return root == nullptr;
    }
