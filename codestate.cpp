#include "codestate.h"
#include<ctime>
#include<QTime>
#include<iostream>
using namespace std;
codestate::codestate()
{
    initializtion();
}
codestate::codestate(const codestate&st)
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            a[i][j]=st.a[i][j];
    location[0]=st.location[0];
    location[1]=st.location[1];
}
void codestate::exchange(int i,int j,int k,int l)   //空格、位置
{
    /*cout<<"to be done"<<endl;
    cout<<"space pos"<<i<<" "<<j<<endl;
    cout<<"to be changed pos"<<k<<" "<<l<<" "<<a[k][l]<<endl;*/
    char t=a[k][l];
    a[k][l]=' ';
    a[i][j]=t;
    location[0]=k;
    location[1]=l;    //更新空格位置}
    /*cout<<"location[0]"<<location[0]<<endl;
    cout<<"location[1]"<<location[1]<<endl;*/
}
void codestate::undo(int i, int j, int k, int l)    //空格、位置
{
    exchange(i,j,k,l);
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
    qsrand(time(NULL));
    int n1=qrand()%6;
    /*if(n1==0||n1==1)
    {
        a[0][0]='1';
        a[0][1]='2';
        a[0][2]='3';
        a[1][0]='8';
        a[1][1]=' ';
        a[1][2]='4';
        a[2][0]='7';
        a[2][1]='6';
        a[2][2]='5';
   // }
    /*else if(n1==2||n1==3)
    {*/
        a[0][0]='8';
        a[0][1]='5';
        a[0][2]='6';
        a[1][0]='2';
        a[1][1]='1';
        a[1][2]='3';
        a[2][0]='7';
        a[2][1]='4';
        a[2][2]=' ';
        location[0]=2;
        location[1]=2;
   /* }
    else
    {
        a[0][0]='4';
        a[0][1]='5';
        a[0][2]='6';
        a[1][0]='7';
        a[1][1]='1';
        a[1][2]='8';
        a[2][0]='2';
        a[2][1]='3';
        a[2][2]=' ';
    }*/
}
bool codestate::operator ==(codestate a1)
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            if(a[i][j]!=a1.a[i][j])
                return false;
        }
    return true;
}
bool codestate::operator !=(codestate a2)
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            if(a[i][j]!=a2.a[i][j])
                return true;
        }
    return false;
}
codestate codestate::operator =(codestate a3)
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            a[i][j]=a3.a[i][j];
    location[0]=a3.location[0];
    location[1]=a3.location[1];
}
