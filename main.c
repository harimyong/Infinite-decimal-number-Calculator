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


    //test
    ExprNODE* A=NULL;
    ExprNODE* B=NULL;
    ExprNODE* now=Aft_input->head;
    while(now->next->NUMBER!=NULL || now->next->oper!=0){
        now=now->next;
        if(isNUMBER(now)){
            if(A==NULL) A=now;
            else if(B==NULL) B=now;
            else break;
        }
    }
    NumberBalancing(A,B);
    LLPrint(A->NUMBER);
    LLPrint(B->NUMBER);
    ExprNODE* res=ADD(A,B);
    LLPrint(res->NUMBER);
    //test fin
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
