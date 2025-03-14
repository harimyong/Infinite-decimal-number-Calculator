#include "calculator.h"

ExprNODE* ADD(ExprNODE* A,ExprNODE* B){
    if(isZero(A)) return B;
    if(isZero(B)) return A;
    if(A->oper!=B->oper) return SUB(A,B);
    //ExprNODE* newNUMBER=makeExprNODE(NULL,0);
    //logic
    NODE* Anow=A->NUMBER->tail;
    NODE* Bnow=B->NUMBER->tail;
    while(Anow->prev->data!=0 && Bnow->prev->data!=0){
        Anow=Anow->prev; Bnow=Bnow->prev;
        char tot=(Anow->data)+(Bnow->data)-96;
        if(tot>=10 && Anow->prev->data!=0){
            tot-=10; Anow->prev->data+=1;
        }
        //printf("%d\n",tot);
        Anow->data=tot+48;
    }
    //printf("fin\n");
    //logic
    return A;
}
ExprNODE* SUB(ExprNODE* A,ExprNODE* B){
    if(isZero(A)) return B;
    if(isZero(B)) return A;
    if(A->oper==B->oper) return ADD(A,B);
    if(CompareAB(A,B)==false) return SUB(B,A);
    ExprNODE* newNUMBER=makeExprNODE(NULL,0);
   //logic
   
    
    
    //logic
    return newNUMBER;
}
bool CompareAB(ExprNODE* A,ExprNODE* B){
    NODE* Anow=A->NUMBER->head;
    NODE* Bnow=B->NUMBER->head;
    //logic
    
    
    
    //logic
    return true;
}
bool isZero(ExprNODE* N){
    NODE* now=N->NUMBER->head;
    while(now->next->data!=0){
        now=now->next;
        if(now->data!='0') return false;
    }
    return true;
}

void NumberBalancing(ExprNODE* A,ExprNODE* B){
    NODE* Anow=A->NUMBER->tail;
    NODE* Bnow=B->NUMBER->tail;
    while(Anow->prev!=NULL || Bnow->prev!=NULL){
        if(Anow->prev!=NULL) Anow=Anow->prev;
        else LLpushFront(A->NUMBER,'0');
        if(Bnow->prev!=NULL) Bnow=Bnow->prev;
        else LLpushFront(B->NUMBER,'0');
    }
    LLpushFront(A->NUMBER,'0');
    LLpushFront(B->NUMBER,'0');
}

bool isNUMBER(ExprNODE* EN){ return EN->NUMBER!=NULL; }
bool isOper(ExprNODE* EN){ return EN->NUMBER==NULL && EN->oper!=0; }