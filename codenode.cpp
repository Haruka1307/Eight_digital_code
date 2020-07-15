#include "codenode.h"
#include<iostream>
#include<QDebug>
using namespace std;
codeNode::codeNode()
{
    struct Node*p1,*p2;
    head=p1=p2=new Node;
    head->Prior=NULL;
    fathernode=head;
    //renew();
}
codeNode::~codeNode()
{
}
codeNode::codeNode(const codeNode &st)
{
    node._state=st.node._state;
}
codestate codeNode::getstate()
{
    return node._state;
}                              //根据空格位置判断不能移动方向
codeNode codeNode::createchild(int i, int j,int k,int l)
{
    codeNode child(*this);
    child.node._state.exchange(i,j,k,l);  //做交换
    /*cout<<"after create child"<<endl;
    child.node._state.printstate();   //打印矩阵信息*/
    struct Node* newnode;
    newnode=new Node;
    newnode->Prior=fathernode;
    newnode->_state=node._state;
    newnode->pos=newnode->pos+1;
    fathernode=newnode;
    tail=newnode;
    return child;
}
/*void codeNode::renew()
{
    invalidmove[0]=0;
    invalidmove[1]=0;
    if(node._state.location[0]==0)   //location[]空格位置
    {
        invalidmove[0]='U';
        if(node._state.location[1]==0)
            invalidmove[1]='L';
        else if(node._state.location[1]==2)
            invalidmove[1]='R';
    }
    if(node._state.location[0]==1)
    {
        if(node._state.location[1]==0)
            invalidmove[0]='L';
        else if(node._state.location[1]==2)
            invalidmove[0]='R';
    }
    if(node._state.location[0]==2)
    {
        invalidmove[0]='D';
        if(node._state.location[0]==0)
            invalidmove[1]='L';
        else if(node._state.location[1]==2)
            invalidmove[1]='R';
    }
}*/
bool codeNode::checkrepeat(codeNode node1)
{
    int t=0;
    struct Node* ptr=tail;
    while(ptr->Prior->_state!=node1.node._state)
    {
        ptr=ptr->Prior;
    }
    if(ptr->_state==node1.node._state)
        t=1;
    if(t==1)
        return true;
    else
        return false;
}

