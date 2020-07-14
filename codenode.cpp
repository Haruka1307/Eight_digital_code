#include "codenode.h"

codeNode::codeNode()
{
    renew();
}
codeNode::~codeNode()
{
}
codeNode::codeNode(const codeNode &st):_state(st._state)
{
}
codestate codeNode::getstate()
{
    return _state;
}                              //根据空格位置判断不能移动方向
codeNode codeNode::createchild(int i, int j,int k,int l)
{
    codeNode child(*this);
    child._state.exchange(i,j,k,l);
                   //只是为了确保移动信息的更新

}
void codeNode::renew()
{
    if(_state.location[0]==0)
    {
        invalidmove[0]='U';
        if(_state.location[1]==0)
            invalidmove[1]='L';
        else if(space[1]==2)
            invalidmove[2]='R';
    }
    if(_state.location[0]==1)
    {
        if(_state.location[1]==0)
            invalidmove[0]='L';
        else if(space[2]==0)
            invalidmove[0]='R';
    }
    if(_state.location[0]==2)
    {
        invalidmove[0]='D';
        if(_state.location[0]==0)
            invalidmove[0]='L';
        else if(_state.location[1]==2)
            invalidmove[1]='R';
    }
}

