#include "expression.h"

//Calculation Functions
ExprNODE* ADD(ExprNODE* A,ExprNODE* B); //완
ExprNODE* SUB(ExprNODE* A,ExprNODE* B); //완
ExprNODE* MUL(ExprNODE* A,ExprNODE* B); //완
ExprNODE* DIV(ExprNODE* A,ExprNODE* B); //소수점 이하 연산 X

//Utilitys
bool CompareAB(ExprNODE* A,ExprNODE* B);
bool isSameAB(ExprNODE* A,ExprNODE* B);

void FillZero(ExprNODE* A,ExprNODE* B); //숫자 front,back에 0 push -> 숫자 자릿수 balancing
void PopZero(ExprNODE *E); // 숫자 front,back에 있는 0 pop
void MULbyTen(ExprNODE *N); //곱하기 10
void DIVbyTen(ExprNODE *N); //나누기 10