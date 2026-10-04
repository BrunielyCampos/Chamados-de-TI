#include <iostream>
#include <string>
#include "BSTChamados.hpp"
#include "FilaChamados.hpp"

using namespace std;

int main() {
    BSTChamados arvore;
    FilaChamado fila;
    int opcao;

    do {
        cout << "\n--- SISTEMA DE CHAMADOS DE TI ---" << endl;
        cout << "1. Abrir Chamado | 2. Buscar Chamado | 3. Listar Chamados | 4. Enfileirar | 5. Atender | 6. Ver historico | 7. Alterar Status | 0. Sair" << endl;
        cout << "Escolha: ";
        cin >> opcao;

        switch(opcao) {
            case 1: {
                long id; 
                string nome;
                int opCat, opPri;

                cout << "Digite o ID numerico: ";
                cin >> id;
                
                cin.ignore(); 

                cout << "Digite o Nome/Descricao do Problema: ";
                getline(cin, nome); 
                
                cout << "Categoria (0-Hardware, 1-Software, 2-Rede, 3-Sistema, 4-Conta): ";
                cin >> opCat;

                cout << "Prioridade (0-Baixa, 1-Media, 2-Alta, 3-Critica): ";
                cin >> opPri;
                
                Chamado novoChamado(id, nome, (CategoriaChamado)opCat, (PrioridadeChamado)opPri);
                
                arvore.insertChamadoBST(novoChamado);
                cout << "Chamado " << id << " aberto com sucesso!\n";
                break;
            }
            case 2: {
                long id; 
                cout << "Id a ser buscado: "; 
                cin >> id;
                
                NodeBST* achado = arvore.searchNoBSTById(id);
                if(achado != nullptr) {
                    cout << "Encontrado: " << achado->chamado.descricao << "\n";
                } 
                else {
                    cout << "Nao existe.\n";
                }
                break;
            }
            case 3:
                cout << "Chamados armazenados (Em Ordem): ";
                arvore.listarEmOrdem(arvore.getRoot());
                cout << endl;
                break;
            case 4: {
                long id; 
                cout << "Id para fila: "; 
                cin >> id;
                
                NodeBST* chamado = arvore.searchNoBSTById(id);
                if(chamado != nullptr) {
                    fila.enfileirar(chamado);
                    cout << "O Chamado: " << id << " entrou na fila!\n";
                }
                else {
                    cout << "Erro: Chamado " << id << " nao encontrado.\n";
                }
                break;
            }
            case 5: {
                NodeBST* proximo = fila.desenfileirar();
                
                if(proximo != nullptr) {
                    cout << "Atendendo agora o chamado " << proximo->chamado.id << "\n";
                } 
                else {
                    cout << "Fila vazia!\n";
                }
                break;
            }
            case 6: {
                long idBusca;
                cout << "Qual ID para ver o historico? ";
                cin >> idBusca;

                NodeBST* achado = arvore.searchNoBSTById(idBusca);

                if (achado != nullptr) {
                    cout << "\n--- HISTORICO DO CHAMADO " << achado->chamado.id << " ---\n";
                    achado->chamado.historico->printList();
                } 
                else {
                    cout << "Erro: Chamado nao encontrado.\n";
                }
                break;
            }
            case 7: {
                long idBusca;
                int novoStatus;
                cout << "Qual ID para alterar o status? ";
                cin >> idBusca;

                NodeBST* achado = arvore.searchNoBSTById(idBusca);

                if (achado != nullptr) {
                    cout << "Novo Status (0-Aberto, 1-Em Atendimento, 2-Resolvido, 3-Cancelado): ";
                    cin >> novoStatus;

                    achado->chamado.status = (StatusChamado)novoStatus;
                    achado->chamado.historico->insertListHistory("Data Atual", "Status alterado manualmente");
                    
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