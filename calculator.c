#include "calculator.h"

ExprNODE* ADD(ExprNODE* A,ExprNODE* B){
    if(isZero(A)) return B;
    if(isZero(B)) return A;
    if(A->oper=='+' && B->oper=='-'){
        B->oper='+'; return SUB(A,B);
    }else if(A->oper=='-' && B->oper=='+'){
        A->oper='+'; return SUB(A,B);
    }
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

    //+ + + -> ADD
    //+ + - -> + - + -> SUB
    //- + + -> + - + -> SUB 
    //- + - -> ADD
    //logic
    return A;
}
ExprNODE* SUB(ExprNODE* A,ExprNODE* B){
    if(isZero(A)) return B;
    if(isZero(B)) return A;
    if(A->oper=='+' && B->oper=='-'){
        B->oper='+'; return ADD(A,B);
    }else if(A->oper=='-' && B->oper=='+'){
        B->oper='-'; return ADD(A,B);
    }else if(A->oper=='-' && B->oper=='-'){
        return SUB(B,A);
    }
    if(CompareAB(A,B)==false) return SUB(B,A);

    NODE* Anow=A->NUMBER->tail;
    NODE* Bnow=B->NUMBER->tail;
    LLPrint(A->NUMBER);
    LLPrint(B->NUMBER);
    while(Anow->prev->data!=0 && Bnow->prev->data!=0){
        Anow=Anow->prev; Bnow=Bnow->prev;
        char tot=(Anow->data)-(Bnow->data);
        if(tot<0){
            tot+=10; Anow->prev->data-=1;
        }
        //printf("%d\n",tot);
        Anow->data=tot+48;
    }

    //logic
    //+ - + -> sub (A<B 일 경우 sub(B,A)하고 부호 마이너스)
    //+ - - -> + + + -> ADD
    //- - + -> - + - -> ADD 
    //- - - -> - + + -> + - + -> sub -3 - (-5) = 2 = -3 + +5 = +5 + -3 = +5 - +3 
    // -A - -B = -A + +B = +B - +A
    //logic
    if(isZero(A)) A->oper='+';
    return A;
}
bool CompareAB(ExprNODE* A,ExprNODE* B){
    NODE* Anow=A->NUMBER->head;
    NODE* Bnow=B->NUMBER->head;
    //logic
    while(Anow->next->data!=0 && Bnow->next->data!=0){
        Anow=Anow->next; Bnow=Bnow->next;
        printf("%c %c\n",Anow->data,Bnow->data);
        if(Anow->data>Bnow->data) return true;
    }
    //logic
    return false;
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