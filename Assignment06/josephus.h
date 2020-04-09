#ifndef _JOSEPHUS_
#define _JOSEPHUS_

namespace JosephusProblem {

class Josephus {
	private:
		bool * people;
		/* pointer to an array of people
		 * true if alive, false if dead
                 */

		int count; // number of people

		int position; // which person we're on right now

		int iteration; // which iteration we're on

		int skip_amount;

	public:
		Josephus(int number_of_people, int skip=2);
		/* constructor
		 * input:
		 *   number_of_people: how many people
		 *   skip: how many people are skipped before an execution
		 * description:
		 *   allocates the array,
		 *   initializes it,
		 *   initializes the other private data members accordingly
		 */

		Josephus(const Josephus & original);
		/* copy constructor
		 * description:
		 *   copies everything from the original into this one,
		 *   but allocates a new array and copies the elements
		 *   from the original array into this array
		 */

		virtual ~Josephus();
		/* destructor
		 * description:
		 *   deallocates the array, if non-empty
		 */

		Josephus & operator=(const Josephus & original);
		/* assignment operator
		 * description:
		 *   copies values from the original over,
		 *   but the array in this is deallocated and reallocated if
		 *   necessary given differences in the size(s) between the
		 *   original and thus;
		 *   the values in the arrays must be copied over
		 */

		bool is_alive(int who) const;
		/* input: which person
		 * result: whether that person is alive or not
		 * description: indexes the array
		 */

		int size() const;
		/* result: how many people (alive or dead)
		 */

		void iterate();
		/* description:
		 *   updates the private member variables accordingly
		 *   to match one more execution being done
		 * exceptions:
		 *   throws an exception if there are less than two alive
		 *   the exception has the position of the one that is alive
		 */
	
};

class JosephusException {
	public:
		JosephusException(int which_person);
		int who();
	private:
		int person_index;
};

};

#endif 