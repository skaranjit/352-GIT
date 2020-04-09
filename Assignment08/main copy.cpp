#include <iostream>
#include "CreateTree.h"
#include "token.h"
using namespace std;

int main() {
    Token t;
    AbstractNode * tree = new PlaceholderNode();
    AbstractNode * current = new PlaceholderNode(); 
    cout << current->parent <<endl;
    AbstractNode *ph = new PlaceholderNode(); 
    AbstractNode *tmp;
    UnaryAbstractNode * param , *tmp2;
    int ct =0;
    // *left, *right, *tmp;
    cout << "enter a valid arithmetic expression on one line: ";
    cin >> t;
    while (t.Valid()){
        cout << "token: "<<t<<endl;
        if(t.IsOperand()){
            // cout<< current<<endl;
            ph = new LeafNode(t.Operand());
            ph->parent = current->parent;
            current = ph;
            // cout<< current<<endl;
        }
        else if (t.IsLeftParen()){
            // cout<<"Skipped : NOt an operand"<<endl;
           
            // cout << "Current Parent:"<<current->parent << endl;
            
            // cout << "Current:"<<current<<endl;
            tmp = new PlaceholderNode();
            param = new ParentheisNode(tmp);
            // cout <<"Param PArent:" <<param->parent << endl;
            // cout << "Param Child:" <<param->child << endl;
            // cout << "Param :" <<param << endl;
            param->parent = current->parent;
            param->child = current;
           // current->parent= param;
            current = param->child;
            ct += 1;
            cout << "Current:"<<current<<endl;
           
            // cout << "Current Parent:"<<current->parent << endl;
            // cout << "Current Parent Parent:"<<current->parent->parent << endl;           
        }
        else if (t.IsRightParen()){
             tmp = new PlaceholderNode();
             
          cout << "Current:"<<current<<endl;
          cout << "Current Parent:"<<current->parent << endl;
          tmp = current;
          cout << "Current Parent:"<<tmp->parent << endl;
           
            while (current != param){
                if(current == param){
                    cout<<"yes it is"<<endl;
                }
                    current = current->parent;
                     cout << "Current:"<<current<<endl;
          cout << "Current Parent:"<<current->parent << endl;
                    ph = current;
            }
            current = ph;
            cout << "Current:"<<current<<endl;
          cout << "Current Parent:"<<current->parent << endl;
        }
        else if(t.IsOperator()){
            AbstractNode * left = new PlaceholderNode();
            AbstractNode * right = new PlaceholderNode();
            BinaryNode * op = new BinaryNode(left,right,t.Operator());
            bool x = true;
            cout << x;
            while (x == true){
                if(current->parent == 0 || t.Operator() == '^' || current == param || op->precedence < t.Precedence() ){
                    x = false;
                }
                else{
                    left = current;
                   current = current->parent;
                }
            }
           
            
           op = new BinaryNode(left,right,t.Operator());
            op->parent = current->parent;
            // cout<<op->parent<<endl;
            // cout<<right->parent<<endl;

            // cout << left->parent<<endl;
            // cout<<left->eval()<<endl;
            // cout<<right<<endl;
            current = right;
            current->parent = op;
           
        }

        cin >> t;

    }
    while(current->parent != 0){
        cout << current<<endl;
        current = current->parent;
        
    }
	cout << current->eval()<<endl;
	
	return 0;
};
