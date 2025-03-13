#include "expression.h"

bool isNUM_ASCII(char data){ return '0'<=data && data<='9'; }

Expr* NumPreprocessing(LinkedList *expr){
    Expr* EXPR=(Expr*)malloc(sizeof(Expr));
    NODE* now=expr->head->next;
    while(now->next!=NULL){
        if(isNUM_ASCII(now->data)){
            LinkedList* NUMBER=LLInit();
            while(isNUM_ASCII(now->data)){
                LLpushBack(NUMBER,now->data);
                now=now->next;
            }
            LLPrint(NUMBER);
            ExprNODE* newElement=makeExprNODE(NUMBER,0);
        }else{
            printf("기호 %c\n",now->data);
            ExprNODE* newElement=makeExprNODE(NULL,now->data);
            now=now->next;
        }
    }
    return EXPR;
}

Expr* EInit(){ 
    Expr* EXPR=(Expr*)malloc(sizeof(Expr)); 
    EXPR->head=makeExprNODE(NULL,0);
    EXPR->tail=makeExprNODE(NULL,0);
    EXPR->head->prev=NULL;
    EXPR->head->next=EXPR->tail;
    EXPR->tail->prev=EXPR->head;
    EXPR->tail->next=NULL;
    return EXPR;
}
ExprNODE* makeExprNODE(LinkedList* NUMBER,char oper){
    ExprNODE* newNode=(ExprNODE*)malloc(sizeof(ExprNODE));
    newNode->oper=oper;
    newNode->NUMBER=NUMBER;
    newNode->prev=newNode;
    newNode->next=newNode;
    return newNode;
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
