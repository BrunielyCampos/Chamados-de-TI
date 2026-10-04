#include <iostream>
#include <string>
#include "BSTChamados.hpp"
#include "FilaChamados.hpp"

using namespace std;

int main() {
    ArvoreBST arvore;
    FilaChamado fila;
    int opcao;

    do {
        cout << "\n--- SISTEMA DE CHAMADOS DE TI ---" << endl;
        cout << "1. Abrir Chamado | 2. Buscar Chamado | 3. Listar Chamados | 4. Enfileirar |5. Atender | 6. Ver historico | 7. Alterar ID | 0. Sair" << endl; //Não vou fazer que nem no trabalho porque é um trabalho infeliz
        cout << "Escolha: ";
        cin >> opcao;

        switch(opcao) {
            case 1: {
                int id; 
                string nome;
                cout << "Digite o ID e o Nome: ";
                cin >> id >> nome;
                
                arvore.cadastrarChamado(id, nome, "Problema padrao", CategoriaChamado::REDE, PrioridadeChamado::MEDIA);
                cout << "Chamado " << id << " salvo na Arvore!\n";
                break;
            }
            case 2: {
                int id; 
                cout << "Id a ser buscado: "; 
                cin >> id;
                
                NoArvore* achado = arvore.buscarChamado(id);
                if(achado){
                    cout << "Encontrado: " << achado->solicitante << "\n";
                } 
                else{
                    cout << "Nao existe.\n";
                }
                break;
            }
            case 3:
                arvore.listarChamados();
                break;
            case 4: {
                int id; 
                cout << "Id para fila: "; 
                cin >> id;
                
                NoArvore* chamado = arvore.buscarChamado(id);
                if(chamado != nullptr) {
                    fila.enfileirar(chamado);
                    cout << "O Chamado: " << id << " entrou na fila!\n";
                }
                else{
                    cout<<"Erro: Chamado "<< id << "nao encontrado\n";
                }
                break;
            }
            case 5: {
                NoArvore* proximo = fila.desenfileirar();
                
                if(proximo){
                    cout << "Atendendo agora o chamado " << proximo->idChamado << "\n";
                } 
                else{
                    cout << "Fila vazia!\n";
                }
                break;
            }
            case 6: {
                int idBusca;
                cout << "Qual ID para ver o historico? ";
                cin >> idBusca;

                
                NoArvore* achado = arvore.buscarChamado(idBusca);

                if (achado != nullptr) {
                    cout << "\n--- HISTORICO DO CHAMADO " << achado->idChamado << " ---\n";
                    
                    achado->historico.printList();
                } 
                else {
                    cout << "Erro: Chamado nao encontrado.\n";
                }
                break;
            }

            case 7: {
                int idBusca, novoStatus;
                cout << "Qual ID para alterar o status? ";
                cin >> idBusca;

               
                NoArvore* achado = arvore.buscarChamado(idBusca);

                if (achado != nullptr) {
                    cout << "Novo Status (0-Aberto, 1-Em Atendimento, 2-Resolvido, 3-Cancelado): ";
                    cin >> novoStatus;

                    
                    achado->status = (StatusChamado)novoStatus;

                    
                    achado->historico.insertListHistory("Data Atual", "Status alterado manualmente");
                    
                    cout << "Status atualizado e registado no historico com sucesso!\n";
                } 
                else {
                    cout << "Erro: Chamado nao encontrado.\n";
                }
                break;
            }
        }
    } while(opcao != 0);

    return 0;
}