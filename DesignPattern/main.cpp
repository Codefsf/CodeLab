#include <iostream>

#include "observer.hpp"

class A {
public:
	A(int x) { y = x + 1; }
	void Print() const { printf("%d", y); }
private:
	int y;
};

void main()
{
	int x = strlen((char*)L"ABC");
	printf("%d", x);
}

