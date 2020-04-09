#include <iostream>
#include "CreateTree.h"
#include "token.h"
using namespace std;

int main() {
    Token t;
    AbstractNode * tree;
    AbstractNode * current,*tmp;
    //cout<<current->eval();
    //cout << current <<endl;
    AbstractNode *ph = new PlaceholderNode(); 
   AbstractNode * right = new LeafNode(2);
    UnaryAbstractNode * param , *tmp2;
    int ct =0;
    // *left, *right, *tmp;
    cout << "enter a valid arithmetic expression on one line: ";
    cin >> t;
    cout << "Current:"<<current<<endl;

    while (t.Valid()){
        cout << "token: "<<t<<endl;
        if(t.IsOperand()){
            // cout<< current<<endl
            tmp = new LeafNode(t.Operand());
            if (current == 0){
                cout << "Yes";
                current = tmp;
            }
            else{
                //tmp->parent = current->parent;
                //cout << current->eval();
                // LeafNode tmp(t.Operand());
                tmp->parent = current->parent;
                
                current = tmp;
                current->parent = tmp->parent;
                right = tmp;
               //current->parent = tree;
               //cout << current->eval();
               
            }
            // LeafNode curernt(t.Operand());
           // current = tmp;
            //cout << ph <<endl;
            //current = ph;
            //cout<<current->eval();
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
            AbstractNode * left;
            
            AbstractNode * op ;
            bool x = true;
            while (x == true){
                if(current->parent == 0 || t.Operator() == '^' || current == param ){
                    cout << "True and exit";
                    x = false;
                }
                else{
                   current = current->parent;
                }
            }
           
            left = current;
            tmp = current->parent;

           current = new BinaryNode(left,right,t.Operator());
            //op->parent = current->parent;
            // cout<<op->parent<<endl;
            // cout<<right->parent<<endl;
           // cout << "Current:"<<current->eval()<<endl;
            // cout << left->parent<<endl;
            // cout<<left->eval()<<endl;
            // cout<<right<<endl;
            //current->parent = tmp;
          // /./ op.parent = tmp;
          current->parent = tmp;
           current = right;
            // current->parent = op;
            // op->printLeft();
            // op->printOperator();
            //cout << op->eval();
            cout << "Current Parent:"<<current->parent << endl;
            
            cout << "Current:"<<current<<endl;
           
        }

        cin >> t;

    }
    while(current->parent != 0){
        //cout << current->eval()<<endl;
        current = current->parent;
        
    }
	cout << current->eval()<<endl;
	


	return 0;
};
