#include "evalPostFix.h"
#include <iostream>
using namespace std;

double evalPostfix(void* tempt, void* temps, void* tempo){
         Token* ta = (Token*)tempt;
     Token& t = *ta;
     stackType<Token>* sa= (stackType<Token>*)temps;
     stackType<Token>& s = *sa;
     queueType<Token>* oa = (queueType<Token>*)tempo;
     queueType<Token>& o = *oa;
      while (!o.isEmptyQueue())
	    {
		         if(o.front().IsOperand()){
               s.push(o.front());
               o.deleteQueue();
			        }
              else if(o.front().IsOperator()){
                Token t1 = s.top();
                s.pop();
                Token t2 = s.top();
                Token t3;
                s.pop();
                switch(o.front().Operator()){
                  case '+':
                    t3 = t1 + t2;
                    break;
                    
                  case '-':
                    t3 = t2- t1;
                    break;
                  case '*':
                    t3 = t1*t2;
                    break;
                  case '/':
                    t3 = t2/t1;
                    break;
                  case '%':
                    t3 = t2 % t1;
                    break;
                  case '^':
                    t3 = t2^t1;
                    break;
                }
                s.push(t3);
                o.deleteQueue();
              }

      }
      t = s.top();
      s.pop();
      return t.Operand();
}