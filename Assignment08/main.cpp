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
    cout << "Current:"<<current<<endl;

    while (t.Valid()){
        cout << "token: "<<t<<endl;
        if(t.IsOperand()){
            // cout<< current<<endl;
            tmp = current->parent;
            current = new LeafNode(t.Operand());
            //cout << ph <<endl;
            //current = ph;
            current->parent = tmp;
            cout<<current->eval();
            cout << "Current Parent:"<<current->parent << endl;
            
            cout << "Current:"<<current<<endl;
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
            AbstractNode * left=new LeafNode(2);
            AbstractNode * right = new PlaceholderNode();
            BinaryNode * op ;
            bool x = true;
            while (x == true){
                if(current->parent == 0 || t.Operator() == '^' || current == param  ){
                    cout << "True and exit";
                    x = false;
                }
                else{
                   current = current->parent;
                }
            }
           
            left = current;

           op = new BinaryNode(left,right,t.Operator());
            //op->parent = current->parent;
            // cout<<op->parent<<endl;
            // cout<<right->parent<<endl;

            // cout << left->parent<<endl;
            // cout<<left->eval()<<endl;
            // cout<<right<<endl;
            current = right;
            current->parent = op;
            op->printLeft();
            op->printOperator();
            //cout << op->eval();
            cout << "Current Parent:"<<current->parent << endl;
            
            cout << "Current:"<<current<<endl;
           
        }

        cin >> t;

    }
    while(current->parent != 0){
        cout << current<<endl;
        current = current->parent;
        
    }
	cout << current<<endl;
	AbstractNode * result;
    result = current;
    cout << result->eval();


	return 0;
};
