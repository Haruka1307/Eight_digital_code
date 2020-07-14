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
private:
    char a[3][3];
    int location[2];
};

#endif // CODESTATE_H
