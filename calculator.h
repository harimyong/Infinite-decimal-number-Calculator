#include "expression.h"

//Calculation Functions
//소수점 연산 다 구현 X
ExprNODE* ADD(ExprNODE* A,ExprNODE* B);
ExprNODE* SUB(ExprNODE* A,ExprNODE* B);
ExprNODE* MUL(ExprNODE* A,ExprNODE* B);
ExprNODE* DIV(ExprNODE* A,ExprNODE* B); //소수점 이하 연산 X



//Utilitys
bool CompareAB(ExprNODE* A,ExprNODE* B);
bool isSameAB(ExprNODE* A,ExprNODE* B);

void FillZero(ExprNODE* A,ExprNODE* B);
void PopZero(ExprNODE *E);