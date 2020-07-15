#ifndef CODESTATE_H
#define CODESTATE_H


class codestate
{
public:
    codestate();
    codestate(const codestate&st);
    void exchange(int i,int j,int k,int l);
    void undo(int i,int j,int k,int l);
    void initializtion();
    void printstate();
    bool isTarget();
    bool operator==(codestate a1);
    bool operator!=(codestate a2);
    codestate operator=(codestate a3);
    char a[3][3];
    int location[2];
};

#endif // CODESTATE_H
