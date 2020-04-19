#include <iostream>
#include "fpuid.h"
#include "graph.h"
using namespace std;
int main() {
	ContextualFPUID<void> a, b, c, d;
	cout << a.value() << endl
		<< b.value() << endl
		<< c.value() << endl
		<< d.value() << endl;
	Graph<> g;
	//Graph<ContextualFPUID<void>,ContextualFPUID<Empty>,int > g_vl;
	ContextualFPUID<void>  av= g.add_vertex();
	cout << av.value()<<endl;
//	g.add_vertex();
	// g.add_vertex();
	// g.add_edge(v1,v2);
	// cout<<v1.value()<<endl<<v2.value();
	return 0;
};
