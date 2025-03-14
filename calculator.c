#include "calculator.h"

ExprNODE* ADD(ExprNODE* A,ExprNODE* B){
    if(isZero(A)) return B;
    if(isZero(B)) return A;
    if(A->oper=='+' && B->oper=='-'){
        B->oper='+'; return SUB(A,B);
    }else if(A->oper=='-' && B->oper=='+'){
        A->oper='+'; return SUB(B,A);
    }
    FillZero(A,B);
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
    //+A + -B -> +A - +B -> SUB
    //-A + +B -> +B + -A -> +B - +A -> SUB 
    //-A + -B -> -(A+B) -> ADD
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
        A->oper='+'; B->oper='+';
        return SUB(B,A);
    }
    if(CompareAB(A,B)==false){ ExprNODE* res=SUB(B,A); res->oper='-'; return res; }
    
    FillZero(A,B);
    NODE* Anow=A->NUMBER->tail;
    NODE* Bnow=B->NUMBER->tail;
    while(Anow->prev->data!=0 && Bnow->prev->data!=0){
        Anow=Anow->prev; Bnow=Bnow->prev;
        char tot=(Anow->data)-(Bnow->data);
        if(tot<0){
            tot+=10; Anow->prev->data-=1;
        }
        //printf("%d\n",tot);
        Anow->data=tot+48;
    }

    //+A - +B -> SUB (A<B 일 경우 sub(B,A)하고 부호 마이너스)
    //+A - -B -> +A + +B -> ADD
    //-A - +B -> -A + -B -> ADD 
    //-A - -B -> -A + +B -> +B + -A -> +B - +A -> SUB
    if(isZero(A)) A->oper='+';
    return A;
}

ExprNODE* MUL(ExprNODE* A,ExprNODE* B){
    if(isZero(A)) return A;
    if(isZero(B)) return B;

    /* logic
        
    */
    



    return A;
}
ExprNODE* DIV(ExprNODE* A,ExprNODE* B){
    if(isZero(B))return NULL;
    if(isZero(A))return A;


     /* logic
        
    */

    return A;
}







//Utilitys
bool CompareAB(ExprNODE* A,ExprNODE* B){ 
    if(isSameAB(A,B)==true) return true;
    NODE* Anow=A->NUMBER->head;
    NODE* Bnow=B->NUMBER->head;
    while(Anow->next->data!=0 && Bnow->next->data!=0){
        Anow=Anow->next; Bnow=Bnow->next;
        //printf("%c %c\n",Anow->data,Bnow->data);
        if(Anow->data==Bnow->data) continue;
        else if(Anow->data>Bnow->data) return true;
        else return false;
    }
}

bool isSameAB(ExprNODE* A,ExprNODE* B){ 
    NODE* Anow=A->NUMBER->head;
    NODE* Bnow=B->NUMBER->head;
    while(Anow->next->data!=0 && Bnow->next->data!=0){
        Anow=Anow->next; Bnow=Bnow->next;
        //printf("%c %c\n",Anow->data,Bnow->data);
        if(Anow->data!=Bnow->data) return false;
    }
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

void FillZero(ExprNODE* A,ExprNODE* B){
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

void PopZero(ExprNODE *E){
    /*
        logic
    */

}

bool isNUMBER(ExprNODE* EN){ return EN->NUMBER!=NULL; }
bool isOper(ExprNODE* EN){ return EN->NUMBER==NULL && EN->oper!=0; }