#include "expression.h"

LinkedList* ExprInput();

int main(){
    LinkedList* Bef_input=ExprInput(); //input expr
    Expr* Aft_input=NumPreprocessing(Bef_input);//number of Expr preprocessing


    LLPrint(Bef_input);
    LLAllRemove(Bef_input);
    
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
