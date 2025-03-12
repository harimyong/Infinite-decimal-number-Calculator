#include "node.h"
typedef struct
{
    NODE* head;
    NODE* tail;
}LinkedList;

void LLpushFront(LinkedList *L,char data);
void LLpushBack(LinkedList *L,char data);
LinkedList* LLInit();
void LLElementRemove(LinkedList *L);
void LLHeadTailRemove(LinkedList *L);
void LLAllRemove(LinkedList *L);
void LLPrint(LinkedList *L);
bool LLisEmpty(LinkedList *L);