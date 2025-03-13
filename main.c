#include "calculator.h"

LinkedList* ExprInput();

int main(){
    LinkedList* Bef_input=ExprInput(); //input expr
    Expr* Aft_input=NumPreprocessing(Bef_input);//number of Expr preprocessing
    if(EisEmpty(Aft_input)){
        printf("오류! 식을 입력하지 않았습니다.\n");
        return 0;
    }

    EPrint(Aft_input);
    // if(LLAllRemove(Bef_input)==false){
    //     printf("오류! 식을 삭제할 수 없거나 존재하지 않습니다.\n");
    // }
    // if(EAllRemove(Aft_input)==false){
    //     printf("오류! 식을 삭제할 수 없거나 존재하지 않습니다.\n");
    // }

    ExprNODE* now=Aft_input->head;
    while(now!=NULL && now->next!=NULL){
        now=now->next;
        printf("cs\n");
        if(now->NUMBER!=NULL)
        printf("%d\n",isZero(now));
        else
        printf("%c\n",now->oper);
        printf("\n");

    }
    
    return 0;
}

LinkedList* ExprInput(){
    char c=getchar();
    LinkedList* LL=LLInit();
    while(c!=EOF){
        LLpushBack(LL,c);
        c=getchar();
    }
    return LL;    
}
