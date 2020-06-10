#include "templateparam.hpp"
#include "string.hpp"
#include <iostream>
#include <Windows.h>
#include "move.hpp"
#include "vector.hpp"

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
	testVectorItem();
}