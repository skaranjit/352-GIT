#ifndef _FPUID_H_
#define _FPUID_H_
class FastPseudoUniqueID {
	private:
		unsigned long long id;
		static unsigned long long last_id;
	public:
		FastPseudoUniqueID();
		FastPseudoUniqueID(const FastPseudoUniqueID &);
		~FastPseudoUniqueID();
		const FastPseudoUniqueID & operator=(const FastPseudoUniqueID &);
		bool operator==(const FastPseudoUniqueID &);
		bool operator!=(const FastPseudoUniqueID &);
		bool operator<(const FastPseudoUniqueID &);
		bool operator>(const FastPseudoUniqueID &);
		bool operator<=(const FastPseudoUniqueID &);
		bool operator>=(const FastPseudoUniqueID &);
		unsigned long long value();
};

template <typename CONTEXT>
struct ContextualFPUID : FastPseudoUniqueID {
};

#endif
