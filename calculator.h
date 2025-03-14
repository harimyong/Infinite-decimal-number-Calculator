#include "expression.h"

ExprNODE* ADD(ExprNODE* A,ExprNODE* B);
ExprNODE* SUB(ExprNODE* A,ExprNODE* B);
bool CompareAB(ExprNODE* A,ExprNODE* B);
bool isZero(ExprNODE* N);
void NumberBalancing(ExprNODE* A,ExprNODE* B);
bool isNUMBER(ExprNODE* EN);
bool isOper(ExprNODE* EN);