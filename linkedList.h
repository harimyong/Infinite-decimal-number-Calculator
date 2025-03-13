#include "node.h"
typedef struct
{
    NODE* head;
    NODE* tail;
}LinkedList;

void LLpushFront(LinkedList *L,char data);
void LLpushBack(LinkedList *L,char data);
LinkedList* LLInit();
bool LLElementRemove(LinkedList *L);
void LLHeadTailRemove(LinkedList *L);
bool LLAllRemove(LinkedList *L);
bool LLPrint(LinkedList *L);
bool LLisEmpty(LinkedList *L);