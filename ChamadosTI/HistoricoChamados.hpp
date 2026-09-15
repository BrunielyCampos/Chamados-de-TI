#ifndef _HISTORICO_CHAMADOS_
#define _HISTORICO_CHAMADOS_

#include <iostream>

using namespace std;

struct NoHistory{
    string dateTime;
    string state;

    NoHistory * next;
};


class HistoricoChamados{
private:
    NoHistory * start;
   
public:
    void insertListHistory();
    void printList();
};


#endif