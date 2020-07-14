#ifndef CODENODE_H
#define CODENODE_H

#include"codestate.h"
class codeNode
{
public:
    codeNode();
    ~codeNode();
    codeNode(const codeNode&st);
    char invalidmove[2]={NULL};
    codestate &getstate();
    codeNode createchild(int i,int j,int k,int l);
    void renew();
private:
    codestate _state;
};

#endif // CODENODE_H
