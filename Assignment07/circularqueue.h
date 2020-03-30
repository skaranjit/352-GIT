template <class T>
class CircularQueue {
	public:
		// you write lots of stuff here
		// you may write more, but at a minimum,
		// you need to flesh out the following:
		CircularQueue();
		~CircularQueue();
		// CircularQueue(CircularQueue<T> & cq);
		// CircularQueue<T> & operator=(CircularQueue<T> & cq);
		void next();
		void prev();
		T& curr();
		bool is_empty();
		// the following two are similar,
		// in that they both create a new node
		void add_before(T&); // puts it before the current
		void add_after(T&); // puts it after the current
	private:
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
