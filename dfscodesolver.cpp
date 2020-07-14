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
    Queen n0;
    nodes.push(n0);
    while(!nodes.empty())
    {
        codeNode crntnode=nodes.top();
        nodes.pop();
        codestate st=crntnode.getstate();
        st.printstate();
        if(st.isTarget())
            return;
        if(crntnode.invalidmove[0]==NULL)
        {
           codeNode child=crntnode.createchild(st.location[0],st.location[1],st.location[0]-1,st.location[1]);
           nodes.push(child);
        }
    }
}
