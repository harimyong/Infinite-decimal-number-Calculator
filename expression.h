#include "linkedList.h"
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


Expr* NumPreprocessing(LinkedList *expr);
void EpushFront(Expr *E,ExprNODE *data);
void EpushBack(Expr *E,ExprNODE *data);