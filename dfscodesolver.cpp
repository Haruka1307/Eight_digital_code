#include "dfscodesolver.h"
#include"codenode.h"
#include<stack>
using namespace std;
dfscodesolver::dfscodesolver()
{
}
dfscodesolver::~dfscodesolver()
{
}
void dfscodesolver::solve()
{
    stack<codeNode>nodes;
    codeNode n0;
    nodes.push(n0);
    while(!nodes.empty())
    {
        codeNode crntnode=nodes.top();
        nodes.pop();
        codestate st=crntnode.getstate();   //拷贝构造函数，不同于=赋值
        if(st.isTarget())
        {
            /*char state[32][3][3]={0};   //存储步骤
            int i=crntnode.node.pos;
            int t=0;
            codeNode ptr=crntnode;
            while(ptr.node.Prior!=NULL)   //正序存入数据
            {
                for(int k=i;k>=0;k--)
                {
                    for(int x=0;x<3;x++)
                        for(int y=0;y<3;y++)
                        {
                           state[t][x][y]=ptr.node._state.a[x][y];
                        }
                    t++;
                }
                for(int k=0;k<=i;k++)
                    for(int x=0;x<3;x++)
                        for(int y=0;y<3;y++)
                        {
                            cout<<state[k][x][y]<<' ';
                            if(y==2)
                                cout<<endl;
                        }
            }*/
            cout<<"success"<<endl;
            return;
        }
        else if(!st.isTarget()&&crntnode.node.pos>=2)
        {
            cout<<"no anwser";
            return;
        }
        if(crntnode.getstate().location[1]==0)   //纵坐标为0
        {
            codeNode child1=crntnode.createchild(st.location[0],st.location[1],st.location[0],st.location[1]+1);  //下
            nodes.push(child1);
            if(crntnode.getstate().location[0]==1||crntnode.getstate().location[0]==0)
            {
                codeNode child2=crntnode.createchild(st.location[0]+1,st.location[1],st.location[0],st.location[1]);  //右
                nodes.push(child2);
            }
            if(crntnode.getstate().location[0]==1||crntnode.getstate().location[0]==2)
            {
                codeNode child3=crntnode.createchild(st.location[0]-1,st.location[1],st.location[0],st.location[1]);  //左
                nodes.push(child3);
            }
        }
        else if(crntnode.getstate().location[1]==1)    //纵坐标为1
        {
            codeNode child1=crntnode.createchild(st.location[0],st.location[1],st.location[0],st.location[1]-1);  //上
            nodes.push(child1);
            codeNode child2=crntnode.createchild(st.location[0],st.location[1],st.location[0],st.location[1]+1);  //下
            nodes.push(child2);
            if(crntnode.getstate().location[0]==0||crntnode.getstate().location[0]==1)
            {
                codeNode child3=crntnode.createchild(st.location[0],st.location[1],st.location[0]+1,st.location[1]);  //右
                nodes.push(child3);
            }
            if(crntnode.getstate().location[0]==1||crntnode.getstate().location[0]==2)//中间位置或者右边
            {
                codeNode child4=crntnode.createchild(st.location[0],st.location[1],st.location[0]-1,st.location[1]);  //左
                nodes.push(child4);
            }
        }
        else    //纵坐标为2
        {
            if(crntnode.getstate().location[0]==1||crntnode.getstate().location[0]==0)   //中间位置或者左边位置
            {
                codeNode child2=crntnode.createchild(st.location[0],st.location[1],st.location[0]+1,st.location[1]);  //右
                nodes.push(child2);
            }
            if(crntnode.getstate().location[0]==1||crntnode.getstate().location[0]==2)     //中间位置或者右边位置
            {
                codeNode child3=crntnode.createchild(st.location[0],st.location[1],st.location[0]-1,st.location[1]);  //左
                nodes.push(child3);
            }
            codeNode child1=crntnode.createchild(st.location[0],st.location[1],st.location[0],st.location[1]-1);  //上
            nodes.push(child1);
        }
}
}
