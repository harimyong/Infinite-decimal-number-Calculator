#include "calculator.h"

LinkedList* ExprInput();

//ERROR Catch Functions
bool NO_InputERROR(LinkedList *L);
bool NOTVALID_InputERROR(Expr *E);

int main(){
    LinkedList* Bef_input=ExprInput(); //input expr
    if(NO_InputERROR(Bef_input)) return 0;
    Expr* Aft_input=NumPreprocessing(Bef_input);//number of Expr preprocessing
    if(NOTVALID_InputERROR(Aft_input)) return 0;

    EPrint(Aft_input);
    //printf("\n");

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

    //LLPrint(A->NUMBER); printf("AF : %d\n",A->isFloat);
    //LLPrint(B->NUMBER); printf("BF : %d\n",B->isFloat);
    // ExprNODE* res=DIV(A,B);
    // ENumberPrint(res);
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

bool NO_InputERROR(LinkedList *L){
    if(LLisEmpty(L)) {printf("오류! 식을 입력하지 않았습니다.\n");return true;}
    return false;
}
bool NOTVALID_InputERROR(Expr *E){
    if(E==NULL) {printf("오류! 식이 잘못된 형태입니다.\n"); return true;}
    return false;
}