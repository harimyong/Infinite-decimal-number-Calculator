#include "linkedList.h"

LinkedList* ExprInput();
//LinkedList* NumPreprocessing(LinkedList *expr);
int main(){
    LinkedList* input=ExprInput(); //input expr
    //number of Expr preprocessing




    LLAllRemove(input);

    return 0;
}

LinkedList* ExprInput(){
    char c=getchar();
    LinkedList* LL=LLInit();
    while(c!=EOF){
        pushBack(LL,c);
        c=getchar();
    }
    return LL;    
}

// LinkedList* NumPreprocessing(LinkedList *expr){
//     if(LLisEmpty(expr)){ printf("오류! 식을 입력하지 않았습니다.\n"); return expr;}
//     NODE* head=expr->head->next;
    
//     return expr;
// }