#include "expression.h"

//Calculation Functions
ExprNODE* ADD(ExprNODE* A,ExprNODE* B);
ExprNODE* SUB(ExprNODE* A,ExprNODE* B);
ExprNODE* MUL(ExprNODE* A,ExprNODE* B);
ExprNODE* DIV(ExprNODE* A,ExprNODE* B); //wait



//Utilitys
bool CompareAB(ExprNODE* A,ExprNODE* B);
bool isSameAB(ExprNODE* A,ExprNODE* B);
bool isZero(ExprNODE* N);
bool isNUMBER(ExprNODE* EN);
bool isOper(ExprNODE* EN);

void ENumberPrint(ExprNODE *EN);
void FillZero(ExprNODE* A,ExprNODE* B);
void PopZero(ExprNODE *E);