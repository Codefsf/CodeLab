#include "templateparam.hpp"
#include "string.hpp"
#include <iostream>
#include <Windows.h>
#include "move.hpp"
#include "vector.hpp"
#include "set.hpp"
#include "map.hpp"
#include "algorithm.hpp"

using namespace std;

class Global {
public:
	Global() {
		cout << "Global construct" << endl;
	}

	~Global() {
		cout << "Global deconstruct" << endl;
	}
};


int main() {
	testAlgorithm();
}