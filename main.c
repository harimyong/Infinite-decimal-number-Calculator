#include "expression.h"

LinkedList* ExprInput();

int main(){
    LinkedList* Bef_input=ExprInput(); //input expr
    Expr* Aft_input=NumPreprocessing(Bef_input);//number of Expr preprocessing
    if(EisEmpty(Aft_input)){
        printf("오류! 식을 입력하지 않았습니다.\n");
        return 0;
    }

    EPrint(Aft_input);
    if(LLAllRemove(Bef_input)==false){
        printf("오류! 식을 삭제할 수 없거나 존재하지 않습니다.\n");
    }
    if(EAllRemove(Aft_input)==false){
        printf("오류! 식을 삭제할 수 없거나 존재하지 않습니다.\n");
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
