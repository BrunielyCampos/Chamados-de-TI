#ifndef _BST_
#define _BST_

struct Chamado{
    
};

struct Node{
    Chamado chamado;

    Node * pai;
    Node * filho;
};

class BST{
private:
    
public:
    BST();

    void insertElement();

    void searchElement();
    void removeElement();

    void insetToList();

    
};

#endif