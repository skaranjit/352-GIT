#include <iostream>
#include <cassert>
using namespace std;

#ifndef Create_TREE
#define Create_TREE

class AbstractNode {      
	public:
        AbstractNode * parent = 0;
		virtual double eval() = 0;
		AbstractNode() {};
		virtual ~AbstractNode() {};
};

class AbstractLeafNode : public AbstractNode{

};
class PlaceholderNode : public AbstractLeafNode {
    public:
        virtual double eval() {assert(0); return 0.0;};
};
class LeafNode : public AbstractLeafNode {
	private:
		double value;
	public:
		LeafNode(double d) : value(d) {};
		~LeafNode() {};
		double eval() {return value;};
};
class UnaryAbstractNode : public AbstractNode {
    public:
       AbstractNode * child;
};
class ParentheisNode : public UnaryAbstractNode {
    public:
        ParentheisNode(AbstractNode * c) {
            child = c;
            child->parent = this;
        };
        ~ParentheisNode() { delete child;};
        virtual double eval() {return (child->eval());};

};
class UnaryMinusNode : public UnaryAbstractNode {
	public:
		UnaryMinusNode(AbstractNode * c) {
            child = c;
            child->parent = this;
        };
		~UnaryMinusNode() {delete child;};
		virtual double eval() {return ((-1.0)*child->eval());};
};
class BinaryNode : public AbstractNode {
	private:
		AbstractNode * left;
		AbstractNode * right;
		char op;
	public:
        int precedence;
		BinaryNode(AbstractNode * l,AbstractNode * r,char o) : left(l), right(r), op(o) {
            left->parent = this;
            right->parent = this;
            precedence = getPrecendence();
        };
		~BinaryNode() {delete left; delete right;};
		virtual double eval() {
			switch(op) {
				case '+':
					return left->eval()+right->eval();
				case '-':
					return left->eval()-right->eval();
				case '*':
					return left->eval()*right->eval();
				case '/':
					return left->eval()/right->eval();
				default:
					return 0;
			};
        };
        void printLeft(){
            cout<<left->eval();
        };
        void printRight(){
            cout<<right->eval();
        };
		void printOperator(){
			cout<<op<<endl;
		}
        int getPrecendence(){
            switch(op){
                case '(': return 0;
		        case ')': return 0;
		        case '^': return 3;
		        case '*': return 2;
		        case '/': return 2;
                case '%': return 2;
                case '+': return 1;
                case '-': return 1;
                case '#': return 9;
                default: return 0;
            }
        }

};

#endif

