#include "ListaSimples.hpp"
#include <iostream>

using namespace std;

    ListaSimples::ListaSimples(){
        inicio = nullptr;
    }

    void ListaSimples::insertStart(int value){
        No * newValue = new No;
        newValue->valor = value;
        newValue->next = inicio;
        inicio = newValue;
    }
    
    void ListaSimples::insertEnd(int value){
        if (!listIsEmpity()){
            
            No* newValueEnd = new No;  // -> instancio um novo nó
            newValueEnd->valor = value; //-> insiro o valor que quero inserir no nó
            newValueEnd->next = nullptr; //-> faço next apontar para null pois estou inserindo no fim e não a nada depois dele;
            No * aux = inicio; // -> Crio um ponteiro que aponta para o inico
    
            // |> faço esse ptr percorre a lista até chegar ao fim
            while ( aux->next != NULL ){
                aux = aux->next;
            }
    
            aux->next = newValueEnd; //-> faço ultimo nó antigo apontar agora para o valor que quero inserir e o novo valor se torna o último.
            fim = newValueEnd; //-> agora o fim aponta para o novo valor 

            cout << "Valor Inserido com sucesso! "<< endl;
        }
        else{
            No * newValue2 = new No;
            newValue2->valor = value;
            newValue2->next = nullptr;
            inicio = newValue2;
            fim = newValue2;

            cout << "Valor Inserido com sucesso! "<< endl;
        }
    }

    void ListaSimples::searchElement(int value){
        No * valueSearch = inicio;

        while (valueSearch != nullptr){
            if (valueSearch->valor == value){
                cout << "Valor Encontrado! "<< valueSearch->valor << endl;
                return;
            }
            
            valueSearch = valueSearch->next;   
        } 
        
        if (valueSearch == nullptr){ 
            cout<< "Valor Não encontrado! \n";
        }
    }

    void ListaSimples::removeElement(int value){

        No * ptrNodeRemove;

        ptrNodeRemove = inicio;

        if (ptrNodeRemove == nullptr){
            cout<< "Erro a Lista Está Vazia"<< endl;
            return;
        }

        if (inicio->valor == value){
            No * auxDelete = inicio;
            inicio = inicio->next;
            delete auxDelete;

            cout << "No Removido!" << endl;
            return;
        }
        
     
        No * aux = inicio;
        while (aux->next != nullptr && aux->next->valor != value){
            aux = aux->next;

            if (aux->next == nullptr){
                cout<<"Valor Não Encontrado!"<< endl;
                return;
            }
        }

        if (aux->next != nullptr){
            No * noParaDeletar = aux->next;
            aux->next = noParaDeletar->next;
            delete noParaDeletar;
        } 

        cout << "No removido!"<< endl;
    }

    void ListaSimples::exibirLista(){
        No * aux = inicio;

        for (int i = 0; aux != nullptr; i++){
            cout<<"\t" << aux->valor;
            
            aux = aux->next;

        }
        cout<<"\n";
        
     }

    bool ListaSimples::listIsEmpity(){
        return inicio == nullptr;
    }