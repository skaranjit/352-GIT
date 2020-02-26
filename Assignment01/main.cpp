#include "token.h"
#include "queueType.h"
#include "stackType.h"
#include "infixtopostfix.h"
#include "evalPostFix.h"
#include <iostream>

using namespace std;

int main(){
   Token t;
   Token t2('#');
   stackType<Token> s;
   s.push(t2);
   queueType<Token> o;
   cout << "enter a valid arithmetic expression on one line: ";
   cin >> t;
  infixTopostfix (&t,&s,&o);
  cout << evalPostfix(&t,&s,&o) << endl;;

}
