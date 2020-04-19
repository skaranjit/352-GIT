#include "fpuid.h"
unsigned long long FastPseudoUniqueID::last_id;
FastPseudoUniqueID::FastPseudoUniqueID() {
	last_id++;
	id = last_id;
};
FastPseudoUniqueID::FastPseudoUniqueID(const FastPseudoUniqueID & other) {
	id = other.id;
};
FastPseudoUniqueID::~FastPseudoUniqueID() {
	// nothing to do
};
const FastPseudoUniqueID & FastPseudoUniqueID::operator=(const FastPseudoUniqueID & other) {
	id = other.id;
	return (*this);
};
bool FastPseudoUniqueID::operator==(const FastPseudoUniqueID & other) {
	return (id == other.id);
};
bool FastPseudoUniqueID::operator!=(const FastPseudoUniqueID & other) {
	return (id != other.id);
};
bool FastPseudoUniqueID::operator<(const FastPseudoUniqueID & other) {
	return (id < other.id);
};
bool FastPseudoUniqueID::operator>(const FastPseudoUniqueID & other) {
	return (id > other.id);
};
bool FastPseudoUniqueID::operator<=(const FastPseudoUniqueID & other) {
	return (id <= other.id);
};
bool FastPseudoUniqueID::operator>=(const FastPseudoUniqueID & other) {
	return (id >= other.id);
};
unsigned long long FastPseudoUniqueID::value() {
	return id;
};

