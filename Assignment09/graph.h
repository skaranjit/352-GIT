#include <set>
#include <map>
#include <bitset>
#include <memory>
#include "fpuid.h"
#include "empty.h"

template <typename V = ContextualFPUID<void>,typename E = ContextualFPUID<Empty>,typename VL = Empty,typename EL = Empty>
class Graph {
	/*
		A class for undirected simple graphs

		For graph terminology, you can see Chapter 20 of the textbook.

		You will probably be unable to do this assignment without
		first reading the chapter.
		If you have questions as you read the chapter,
		please post to the discussion forums.

		You may also feel free to use:
		https://en.wikipedia.org/wiki/Graph_theory
		as a reference
	 */
	private:
		std::set<V> _vertices;
		std::set<E> _edges;
		std::map<std::pair<V,V>, E > _relations;
	public:
		
		// no reason to keep these private or protected,
		// since we won't actually be accessing them here at all
		std::map<V,VL> vertex_labels;
		std::map<E,EL> edge_labels;
		/*
		Note: the default constructor, destructor, operator=
		are all good, because by default it just does it all
		for each member, and that will be fine for us
		*/
		typedef V vertex_t;
		typedef E edge_t;
		const V & add_vertex(){
			V a;
			_vertices.insert(a);
			return a;			
		};
		const E & add_edge(const V & v_source,const V & v_dest){
			std::pair<V,V> pairV;
			pairV.first = v_source;
			pairV.second =v_dest;
			E newEdge = new E(pairV);
			_edges.insert(newEdge);
			_relations.insert(pairV,newEdge);
			return newEdge;
			

		};
		void remove_vertex(const V&);
		void remove_edge(const E&);
		std::shared_ptr<std::set<V> > adjacent(const V&);
		std::shared_ptr<std::set<E> > incident(const V&);
		bool empty();
		int size(); // number of edges
		int order(); // number of vertices
		bool trivial();
		bool has_vertext(const V&);
		bool has_edge(const E&);
		// your implementation of these methods should:
		// throw appropriate exceptions (use standard ones)

		// extra credit methods to add,
		//  look up what they mean on your own
		//   induced_subgraph, contract, subdivide
		//   to_matrix (a map of map of bool, so V can be preserved,
		//    and also it accomodates sparseness, so not all entries)
		/*   path (given two vertices as arguments,
			return a shared_ptr to a
				vector or list or other sequence type
				of edges that would take us from the first vertex to the second)
		*/
};

		
