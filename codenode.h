#ifndef CODENODE_H
#define CODENODE_H
#include<iostream>
using namespace std;
#include"codestate.h"
struct Node
{
    codestate _state;
    Node*Prior;
    int pos=0;   //位置信息
};
class codeNode
{
public:
    codeNode();
    ~codeNode();
    codeNode(const codeNode&st);
    codestate getstate();
    codeNode createchild(int i,int j,int k,int l);   //创建子节点
   // void renew();   //更新空格位置
    bool checkrepeat(codeNode node1);  //检查是否重复
    struct Node node;
private:
    struct Node* head;
    struct Node* tail;
    struct Node* fathernode=NULL;
};

#endif // CODENODE_H
