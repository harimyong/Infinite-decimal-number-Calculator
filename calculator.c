#include "calculator.h"

ExprNODE* ADD(ExprNODE* A,ExprNODE* B){
    if(A->oper!=B->oper) return SUB(A,B);
    ExprNODE* newNUMBER=makeExprNODE(NULL,0);
    
    return newNUMBER;
}
ExprNODE* SUB(ExprNODE* A,ExprNODE* B){
    if(A->oper==B->oper) return ADD(A,B);
    if(CompareAB(A,B)==false) return SUB(B,A);
    ExprNODE* newNUMBER=makeExprNODE(NULL,0);

    return newNUMBER;
}
bool CompareAB(ExprNODE* A,ExprNODE* B){
    NODE* Anow=A->NUMBER->head;
    NODE* Bnow=B->NUMBER->head;
    return true;
}