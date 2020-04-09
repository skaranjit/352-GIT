#include "token.h"
#include "stackType.h"
#include "queueType.h"

double evalPostfix(void* tempt, void* temps, void* o);
//This function will evaluate postfix expression. It will scan postfix queue from left to right and do the following. 
//1.if the token is an operand, push it on the stack
//2.if the token is an operator
//   a.pop the top two operands
//   b.perform the arithmetic (taking care that the operands are in the proper order)
//   c.push the result
//3.if there are no more tokens in the postfix expression
//   a.pop the final result off the stack
//PreCondition : Token, emptystack queue and postfix queue should be provided.
//PostCondition : stackqueue and postfix queue will be updated. Returns final token after performing airthematic operations.
