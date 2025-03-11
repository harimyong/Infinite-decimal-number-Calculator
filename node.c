#include "node.h"
NODE* makeNode(char data){
    NODE* newNode=(NODE*)malloc(sizeof(NODE));
    newNode->data=data;
    newNode->prev=newNode;
    newNode->next=newNode;
    return newNode;
}

