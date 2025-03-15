#include "calculator.h"

ExprNODE* ADD(ExprNODE* A,ExprNODE* B){
    if(isZero(A)) return B;
    if(isZero(B)) return A;
    if(A->oper=='+' && B->oper=='-'){
        B->oper='+'; return SUB(A,B);
    }else if(A->oper=='-' && B->oper=='+'){
        A->oper='+'; return SUB(B,A);
    }

    // printf("%c",A->oper); LLPrint(A->NUMBER);
    // printf("+\n");
    // printf("%c",B->oper); LLPrint(B->NUMBER);
    PopZero(A); PopZero(B);
    FillZero(A,B);
    NODE* Anow=A->NUMBER->tail;
    NODE* Bnow=B->NUMBER->tail;
    while(Anow->prev->data!=0 && Bnow->prev->data!=0){
        Anow=Anow->prev; Bnow=Bnow->prev;
        char tot=(Anow->data)+(Bnow->data)-96;
        if(tot>=10 && Anow->prev->data!=0){
            tot-=10; Anow->prev->data+=1;
        }
        //printf("%d\n",tot);
        Anow->data=tot+48;
    }
    //printf("fin\n");

    //+ + + -> ADD
    //+A + -B -> +A - +B -> SUB
    //-A + +B -> +B + -A -> +B - +A -> SUB 
    //-A + -B -> -(A+B) -> ADD
    PopZero(A);
    return A;
}

ExprNODE* SUB(ExprNODE* A,ExprNODE* B){
    if(isZero(A)){
        if(B->oper=='+') B->oper='-';
        else B->oper='+';
        return B;
    }
    if(isZero(B)) return A;

    if(A->oper=='+' && B->oper=='-'){
        B->oper='+'; return ADD(A,B);
    }else if(A->oper=='-' && B->oper=='+'){
        B->oper='-'; return ADD(A,B);
    }else if(A->oper=='-' && B->oper=='-'){
        A->oper='+'; B->oper='+';
        return SUB(B,A);
    }
    if(CompareAB(A,B)==false){ ExprNODE* res=SUB(B,A); res->oper='-'; return res; }
    
    // printf("%c",A->oper); LLPrint(A->NUMBER);
    // printf("-\n");
    // printf("%c",B->oper); LLPrint(B->NUMBER);
    PopZero(A); PopZero(B);
    NODE* Anow=A->NUMBER->tail;
    NODE* Bnow=B->NUMBER->tail;
    while(Anow->prev->data!=0 && Bnow->prev->data!=0){
        Anow=Anow->prev; Bnow=Bnow->prev;
        char tot=(Anow->data)-(Bnow->data);
        if(tot<0){
            tot+=10; Anow->prev->data-=1;
        }
        //printf("%d\n",tot);
        Anow->data=tot+48;
    }

    //+A - +B -> SUB (A<B 일 경우 sub(B,A)하고 부호 마이너스)
    //+A - -B -> +A + +B -> ADD
    //-A - +B -> -A + -B -> ADD 
    //-A - -B -> -A + +B -> +B + -A -> +B - +A -> SUB
    if(isZero(A)) A->oper='+';
    PopZero(A);
    return A;
}

ExprNODE* MUL(ExprNODE* A,ExprNODE* B){
    if(isZero(A)) return A;
    if(isZero(B)) return B;
    char res_oper='+';
    if(A->oper!=B->oper) res_oper='-';
    
    //나올 수 있는 최대 자리수만큼 0 추가
    LinkedList* res_N=LLInit();
    ExprNODE* res_EN=makeExprNODE(res_N,'+');
    NODE* now=A->NUMBER->tail;
    while(now->prev->data!=0){ now=now->prev; LLpushFront(res_N,'0'); }
    now=B->NUMBER->tail;
    while(now->prev->data!=0){ now=now->prev; LLpushFront(res_N,'0'); }

    //Multiply 진행
    NODE* Bnow=B->NUMBER->tail;
    char UP;
    while(Bnow->prev->data!=0){
        LinkedList* temp_L=LLInit();
        NODE* Anow=A->NUMBER->tail;
        Bnow=Bnow->prev;
        UP=0;
        while(Anow->prev->data!=0){
            Anow=Anow->prev;
            char tot=((Anow->data)-48)*((Bnow->data)-48)+UP;
            UP=tot/10;
            if(tot>=10) tot%=10;
            LLpushFront(temp_L,tot+48);
        }
        if(UP!=0) LLpushFront(temp_L,UP+48);

        NODE* tempNODE=B->NUMBER->tail->prev;
        while(tempNODE!=Bnow){
            tempNODE=tempNODE->prev;
            LLpushBack(temp_L,'0');
        }

        ExprNODE* temp_EN=makeExprNODE(temp_L,'+');
        res_EN=ADD(res_EN,temp_EN);
    }
    PopZero(res_EN);
    res_EN->oper=res_oper;
    //LLPrint(res_EN->NUMBER);
    return res_EN;
}

ExprNODE* DIV(ExprNODE* A,ExprNODE* B){
    if(isZero(B))return NULL; //Division By Zero Error
    if(isZero(A))return A; // 0 / B = 0
    PopZero(A); PopZero(B);
    char Q_oper='+';
    if(A->oper!=B->oper) Q_oper='-';
    LinkedList* Q_N=LLInit();

    //BNumber Copy -> RemainderNumber
    LinkedList* R_N=LLInit();
    ExprNODE* R_EN=makeExprNODE(R_N,'+');


    //Divide
    //Quotient 몫 구현 완료
    NODE* Anow=A->NUMBER->head;
    while(Anow->next->data!=0){
        Anow=Anow->next;
        LLpushBack(R_N,Anow->data);
        if(isSameAB(B,R_EN)==false and CompareAB(B,R_EN)==true){
            LLpushBack(Q_N,'0');
        }else{
            ExprNODE* temp_EN=makeExprNODE(LLInit(),'+');
            bool flag=false;
            for(int i=0;i<10;i++){
                LLElementRemove(temp_EN->NUMBER);
                LLpushBack(temp_EN->NUMBER,i+48);
                temp_EN=MUL(temp_EN,B);
                if(isSameAB(temp_EN,R_EN)){
                    R_EN=SUB(R_EN,temp_EN);
                    LLpushBack(Q_N,i+48);
                    flag=true;
                    break;
                }else if(CompareAB(temp_EN,R_EN)){
                    LLElementRemove(temp_EN->NUMBER);
                    LLpushBack(temp_EN->NUMBER,i+47);
                    temp_EN=MUL(temp_EN,B);
                    R_EN=SUB(R_EN,temp_EN);
                    LLpushBack(Q_N,i+47);
                    flag=true;
                    break;
                }
            }
            if(flag==false){
                LLElementRemove(temp_EN->NUMBER);
                LLpushBack(temp_EN->NUMBER,'9');
                temp_EN=MUL(temp_EN,B);
                R_EN=SUB(R_EN,temp_EN);
                LLpushBack(Q_N,57);
            }
            LLAllRemove(temp_EN->NUMBER);
            free(temp_EN);
        }
    }

    
    ExprNODE* Q_EN=makeExprNODE(Q_N,Q_oper);
    PopZero(Q_EN);
    if(isZero(R_EN)) return Q_EN; //나머지가 0일 경우 더 이어서 연산 X

    //Decimal 나머지 구현 미완
    Q_EN->isFloat=true;
    




    return Q_EN;
}







//Utilitys
bool CompareAB(ExprNODE* A,ExprNODE* B){ 
    if(isSameAB(A,B)==true) return true;
    FillZero(A,B);
    NODE* Anow=A->NUMBER->head;
    NODE* Bnow=B->NUMBER->head;
    // printf("함수 안\n");
    // LLPrint(A->NUMBER); LLPrint(B->NUMBER);
    // printf("\n");
    while(Anow->next->data!=0 && Bnow->next->data!=0){
        Anow=Anow->next; Bnow=Bnow->next;
        //printf("%c %c\n",Anow->data,Bnow->data);
        if(Anow->data==Bnow->data) continue;
        else if(Anow->data>Bnow->data) { PopZero(A); PopZero(B); return true; }
        else { PopZero(A); PopZero(B); return false; }
    }
}

bool isSameAB(ExprNODE* A,ExprNODE* B){ 
    //if(LLisEmpty(A->NUMBER) || LLisEmpty(B->NUMBER)) return false;
    FillZero(A,B);
    NODE* Anow=A->NUMBER->head;
    NODE* Bnow=B->NUMBER->head;
    while(Anow->next->data!=0 && Bnow->next->data!=0){
        Anow=Anow->next; Bnow=Bnow->next;
        //printf("%c %c\n",Anow->data,Bnow->data);
        if(Anow->data!=Bnow->data) { PopZero(A); PopZero(B); return false; }
    }
    PopZero(A); PopZero(B);
    return true;
}

void FillZero(ExprNODE* A,ExprNODE* B){
    NODE* Anow=A->NUMBER->tail;
    NODE* Bnow=B->NUMBER->tail;
    while(Anow->prev!=NULL || Bnow->prev!=NULL){
        if(Anow->prev!=NULL) Anow=Anow->prev;
        else LLpushFront(A->NUMBER,'0');
        if(Bnow->prev!=NULL) Bnow=Bnow->prev;
        else LLpushFront(B->NUMBER,'0');
    }
    LLpushFront(A->NUMBER,'0');
    LLpushFront(B->NUMBER,'0');
}

void PopZero(ExprNODE *N){
    NODE* now=N->NUMBER->head;
    while(now->next->data=='0') LLpopFront(N->NUMBER);
    if(LLisEmpty(N->NUMBER)) LLpushFront(N->NUMBER,'0');
}
