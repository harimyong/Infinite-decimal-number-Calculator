#include "expression.h"

Expr* NumPreprocessing(LinkedList* expr){
    Expr* EXPR=(Expr*)malloc(sizeof(Expr));
    NODE* now=expr->head;
    while(now->next!=NULL){
        now=now->next;
        if('0'<=now->data && now->data>='9'){
            LinkedList* NUMBER=LLInit();
            
        }



    }


    return EXPR;
}

Expr* EInit(){ 
    Expr* EXPR=(Expr*)malloc(sizeof(Expr)); 
    LL->head=makeNode(0);
    LL->tail=makeNode(0);
    LL->head->prev=NULL;
    LL->head->next=LL->tail;
    LL->tail->prev=LL->head;
    LL->tail->next=NULL;
    
    return EXPR;
}
void EpushFront(Expr *E,ExprNODE *data){
    data->next=E->head->next;
    data->prev=E->head;
    E->head->next->prev=data;
    E->head->next=data;
}
void EpushBack(Expr *E,ExprNODE *data){
    data->next=E->tail;
    data->prev=E->tail->prev;
    E->tail->prev->next=data;
    E->tail->prev=data;
}
// void EElementRemove(LinkedList *E){ LLElementRemove(E); }
// void EHeadTailRemove(LinkedList *E){ LLHeadTailRemove(E); }
// void EAllRemove(LinkedList *E){ LLAllRemove(E); }
// void EPrint(LinkedList *E){ LLPrint(E); }
// bool EisEmpty(LinkedList *E){ LLisEmpty(E); }
