template <class T>
class CircularQueue {
	public:
		// you write lots of stuff here
		// you may write more, but at a minimum,
		// you need to flesh out the following:
		CircularQueue();
<<<<<<< HEAD
		void destroyqueue();
		~CircularQueue();
		CircularQueue(CircularQueue<T> & cq);
		CircularQueue<T> & operator=(CircularQueue<T> & cq);
		void next();
		void prev();
		void copylist(CircularQueue<T> & cq);
=======
		~CircularQueue();
		// CircularQueue(CircularQueue<T> & cq);
		// CircularQueue<T> & operator=(CircularQueue<T> & cq);
		void next();
		void prev();
>>>>>>> 1c5b46782265b9a3a71cd679feedf0a2ce857522
		T& curr();
		bool is_empty();
		// the following two are similar,
		// in that they both create a new node
		void add_before(T&); // puts it before the current
		void add_after(T&); // puts it after the current
<<<<<<< HEAD
		int Size();
		void first(); //go to first in queue
		void last();  //put current node to last element.
		T& lastitem() ;
		void print(); //will print the names from queue but the current node will stays same.
	private:
		int count;
=======
	private:
>>>>>>> 1c5b46782265b9a3a71cd679feedf0a2ce857522
		// you also write lots of stuff here
		// you must keep the following,
		// and use it for your implementation
	struct node;
	struct node {
		node * next;
		node * prev;
		T item;
	};
	struct node * current;

		/* a few notes:
			if (current) {
				assert(current->next->prev == current);
				assert(current->prev->next == current);
			} else {
				assert(is_empty());
			};
		*/
};
<<<<<<< HEAD

=======
>>>>>>> 1c5b46782265b9a3a71cd679feedf0a2ce857522
