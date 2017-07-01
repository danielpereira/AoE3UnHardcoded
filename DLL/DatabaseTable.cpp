#include "DatabaseTable.h"

DatabaseTable::DatabaseTable() {}

DatabaseTable::~DatabaseTable() {}

bool DatabaseTable::set(int index, const char* name) {
	vec.reserve(index + 1);
	vec[index] = name;
}

const char* DatabaseTable::getName(int index) {
	return vec[index];
}