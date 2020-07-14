#include "codestate.h"
#include<ctime>
#include<QTime>
codestate::codestate()
{
    initializtion();
}
codestate::codestate(const codestate&st)
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            a[i][j]=st.a[i][j];
}
void codestate::exchange(int i,int j,int k,int l)
{
    char k=a[k][l];
    a[k][l]=' ';
    a[i][j]=k;
    location[0]=k;
    location[1]=l;
}
void codestate::undo(int i, int j, int k, int l)
{
    exchange(i,j,k,l);
    location[0]=i;
    location[1]=j;
}
bool codestate::isTarget()
{
    if(a[0][0]=='1'&&a[0][1]=='2'&&a[0][2]=='3')
        if(a[1][0]=='8'&&a[1][1]==' '&&a[1][2]=='4')
            if(a[2][0]=='7'&&a[2][1]=='6'&&a[2][2]=='5')
                return true;
    return false;
}
void codestate::printstate()
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            cout<<a[i][j]<<" ";
            if(j==2)
                cout<<endl;
        }
}
void codestate::initializtion()
{
    qrsand(time(NULL));
    int n1=qrand()%3;
    int n2=qrand()%3;
    location[0]=n1;
    location[1]=n2;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            if(i==1&&j==1)
                continue;
            QTime time=QTime::currentTime();
            qrsand(time.msec()+time.second()*1000);
            int t=qrand()%7;
            a[i][j]='t';
        }
}
