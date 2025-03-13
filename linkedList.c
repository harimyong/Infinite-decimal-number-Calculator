#include "linkedList.h"
LinkedList* LLInit(){
    LinkedList* LL=(LinkedList*)malloc(sizeof(LinkedList));
    LL->head=makeNode(0);
    LL->tail=makeNode(0);
    LL->head->prev=NULL;
    LL->head->next=LL->tail;
    LL->tail->prev=LL->head;
    LL->tail->next=NULL;
    return LL;
}

void LLpushFront(LinkedList *L,char data){
    NODE* newNODE=makeNode(data);
    newNODE->next=L->head->next;
    newNODE->prev=L->head;
    L->head->next->prev=newNODE;
    L->head->next=newNODE;
}

void LLpushBack(LinkedList *L,char data){
    NODE* newNODE=makeNode(data);
    newNODE->next=L->tail;
    newNODE->prev=L->tail->prev;
    L->tail->prev->next=newNODE;
    L->tail->prev=newNODE;
}

bool LLPrint(LinkedList *L){
    if(LLisEmpty(L)) return false;
    NODE* now=L->head;
    while(now->next!=NULL){
        now=now->next;
        printf("%c",now->data);
    }printf("\n");
    return true;
}

bool LLElementRemove(LinkedList *L){
    if(LLisEmpty(L)) return false; 
    NODE* now=L->head->next;
    L->head->next=L->tail;
    L->tail->prev=L->head;
    while(now->data!=0){
        NODE* nxt=now->next;
        //printf("%c 지움\n",now->data);
        free(now);
        now=nxt;
    }
    return true;
}

void LLHeadTailRemove(LinkedList *L){ free(L->head); free(L->tail); }
    
bool LLAllRemove(LinkedList *L){ 
    if(LLElementRemove(L)==false) return false;
    LLHeadTailRemove(L); free(L);
    return true;
}

bool LLisEmpty(LinkedList *L){ return L->head->next->data==0; }