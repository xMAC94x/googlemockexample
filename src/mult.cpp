#include "mult.h"

int multNumbers(const int foo, const int bar) {
	if (foo == 3 && bar == 3) {
		return 7; // this is an programming error
	}
	return foo * bar;
}