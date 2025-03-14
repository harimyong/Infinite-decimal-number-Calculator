#include "number.h"
typedef struct ExprNODE{
    LinkedList* NUMBER;
    char oper;
    struct ExprNODE* next;
    struct ExprNODE* prev;
}ExprNODE;

typedef struct 
{
    ExprNODE* head;
    ExprNODE* tail;
}Expr;

ExprNODE* makeExprNODE(LinkedList* NUMBER,char oper);
Expr* EInit();
Expr* NumPreprocessing(LinkedList *expr);
bool isNUM_ASCII(char data);
void EpushFront(Expr *E,ExprNODE *data);
void EpushBack(Expr *E,ExprNODE *data);