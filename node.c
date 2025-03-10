#include <stdlib.h>
#include <malloc.h>
typedef struct NODE
{
    char data;
    struct NODE *next;
    struct NODE *prev;
}NODE;

NODE* makeNode(char data){
    NODE* newNode=(NODE*)malloc(sizeof(newNode));
    newNode=data;
    newNode->prev=newNode;
    newNode->next=newNode;
    return newNode;
}

