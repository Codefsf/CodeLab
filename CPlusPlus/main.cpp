#include "templateparam.hpp"
#include "string.hpp"
#include <iostream>
#include <Windows.h>

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
	cout << "Main start" << endl;

	{
		char* ch = new char[1024 * 1024 * 10];
	}

	{
		char* ch2 = new char[1024 * 1024 * 10];
	}
	
	cout << "Main end" << endl;

	return -1;
}