#include "node.h"
typedef struct
{
    NODE* head;
    NODE* tail;
}LinkedList;

void pushFront(LinkedList *L,char data);
void pushBack(LinkedList *L,char data);
LinkedList* init();
void LLPrint(LinkedList *L);