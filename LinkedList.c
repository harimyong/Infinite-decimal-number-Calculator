#include <stdlib.h>
#include <malloc.h>
#include <node.c>

typedef struct LinkedList
{
    NODE* head;
    NODE* tail;
}LinkedList;

LinkedList* pushFront(LinkedList *L,char data);
LinkedList* init();

LinkedList* init(){
    LinkedList* LL=(LinkedList*)malloc(sizeof(LinkedList));
    LL->head=makeNode(NULL);
    LL->tail=makeNode(NULL);
    LL->head->prev=NULL;
    LL->head->next=LL->tail;
    LL->tail->prev=LL->head;
    LL->tail->next=NULL;
    return LL;
}

LinkedList* pushFront(LinkedList *L,char data){
    return L;
}
