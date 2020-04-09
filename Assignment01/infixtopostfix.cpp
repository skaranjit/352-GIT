 #include "infixtopostfix.h"
 #include <iostream>

 using namespace std;

 void infixTopostfix (void* tempt, void* temps, void* tempo){
     Token* ta = (Token*)tempt;
     Token& t = *ta;
     stackType<Token>* sa= (stackType<Token>*)temps;
     stackType<Token>& s = *sa;
     queueType<Token>* oa = (queueType<Token>*)tempo;
     queueType<Token>& o = *oa;

 while (t.Valid())
   {
      cout << "token: " << t << endl;
      if (t.IsOperand()){
         o.addQueue(t);
      }
      else if(t.IsLeftParen()){
         s.push(t);
      }
      else if(t.IsRightParen()){
         while (s.top().Precedence() != 9 && !(s.top().IsLeftParen()) ){
            Token t1 = s.top();
            s.pop();
            o.addQueue(t1);
         }
         if (s.top().IsLeftParen()){
            Token t1 = s.top();
            s.pop();
         }
      }
      else if(t.IsOperator()){
         while (s.top().Precedence() != 9 && s.top().Precedence() != 3 && !s.top().IsLeftParen() && !s.isEmptyStack() && s.top().Precedence() >= t.Precedence())		 
         {
            Token t1 = s.top();
	    cerr << "Debugging token: " << t1 << endl;
            s.pop();
            o.addQueue(t1);
         }
         s.push(t);
      }
      cin >> t;
   }

   while (!s.isEmptyStack() && s.top().Precedence() !=9){
      Token t3 = s.top();
      s.pop();
      o.addQueue(t3);
   }
   queueType<Token> i = o;
  while (!i.isEmptyQueue())
	    {
		         cout << i.front() << ' ';
               i.deleteQueue();
			        }
    cout << endl; 
  while (!s.isEmptyStack() && s.top().Precedence() != 9)
	     {
		           cout << s.top() << ' ';
			         s.pop();
				    }
     cout << endl;}