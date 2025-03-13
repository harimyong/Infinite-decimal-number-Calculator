#include "expression.h"

bool isNUM_ASCII(char data){ return '0'<=data && data<='9'; }

Expr* NumPreprocessing(LinkedList *expr){
    Expr* EXPR=EInit();
    if(LLisEmpty(expr)) return EXPR;
    NODE* now=expr->head->next;
    while(now->next!=NULL){
        if(isNUM_ASCII(now->data)){
            LinkedList* NUMBER=LLInit();
            while(isNUM_ASCII(now->data)){
                LLpushBack(NUMBER,now->data);
                now=now->next;
            }
            //LLPrint(NUMBER);
            ExprNODE* newElement=makeExprNODE(NUMBER,0);
            EpushBack(EXPR,newElement);
        }else{
            //printf("기호 %c\n",now->data);
            ExprNODE* newElement=makeExprNODE(NULL,now->data);
            now=now->next;
            EpushBack(EXPR,newElement);
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

bool EPrint(Expr *E){
    if(EisEmpty(E)) return false;
    ExprNODE* now=E->head->next;
    while(now!=NULL && now->next!=NULL){
        if(now->NUMBER!=NULL) LLPrint(now->NUMBER);
        else printf("기호 %c\n",now->oper);
        now=now->next;
    }
    return true;
}

bool EisEmpty(Expr *E){ return E->head->next->oper==0 && E->head->next->NUMBER==NULL; }

bool EElementRemove(Expr *E){
    if(EisEmpty(E)) return false;
    ExprNODE* now=E->head->next;
    E->head->next=E->tail;
    E->tail->prev=E->head;
    while(now->NUMBER!=NULL || now->oper!=0){
        ExprNODE* nxt=now->next;
        free(now->NUMBER);
        free(now);
        now=nxt;
    }
    return true;
}
void EHeadTailRemove(Expr *E){
    ExprNODE* H=E->head;
    ExprNODE* T=E->tail;
    free(H->NUMBER);
    free(T->NUMBER);
    free(H); free(T);
}
bool EAllRemove(Expr *E){
    if(EElementRemove(E)==false) return false;
    EHeadTailRemove(E); free(E);
    return true;
}