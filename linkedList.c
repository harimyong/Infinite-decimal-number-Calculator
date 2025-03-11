#include "linkedList.h"
LinkedList* init(){
    LinkedList* LL=(LinkedList*)malloc(sizeof(LinkedList));
    LL->head=makeNode(0);
    LL->tail=makeNode(0);
    LL->head->prev=NULL;
    LL->head->next=LL->tail;
    LL->tail->prev=LL->head;
    LL->tail->next=NULL;
    return LL;
}
void pushFront(LinkedList *L,char data){
    NODE* newNODE=makeNode(data);
    newNODE->next=L->head->next;
    newNODE->prev=L->head;
    L->head->next->prev=newNODE;
    L->head->next=newNODE;
}

void pushBack(LinkedList *L,char data){
    NODE* newNODE=makeNode(data);
    newNODE->next=L->tail;
    newNODE->prev=L->tail->prev;
    L->tail->prev->next=newNODE;
    L->tail->prev=newNODE;
}

void LLPrint(LinkedList *L){
    NODE* now=L->head;
    while(now->next!=NULL){
        now=now->next;
        printf("%c",now->data);
    }printf("\n");
}

