#ifndef _HISTORICO_CHAMADOS_
#define _HISTORICO_CHAMADOS_

#include <iostream>

using namespace std;

struct NoHistory{
    string dateTime;
    string descricao;

    NoHistory * next;
};


class HistoricoChamados{
private:
    NoHistory * noLista;
   
public:
    HistoricoChamados();
    void insertListHistory(string dateTime, string descricao);
    void insertIfListEmpity(string dateTime, string descricao);
    void printList();
    bool isEmpity();
};


#endif