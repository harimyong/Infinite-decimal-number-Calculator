#include <stdio.h>
#include "linkedList.h"

LinkedList* LLinput();
void LLremove(LinkedList *LL);
int main(){
    LinkedList* input=LLinput();
    LLPrint(input);



    LLremove(input);
    return 0;
}

LinkedList* LLinput(){
    char c=getchar();
    LinkedList* LL=init();
    while(c!=EOF){
        pushBack(LL,c);
        c=getchar();
    }
    return LL;    
}

void LLremove(LinkedList *LL){
    NODE* now=LL->head;
    while(now->next!=NULL){
        NODE* nxt=now->next;
        free(now);
        now=nxt;
    }
}