#include <iostream>
#include <string>

using namespace std;

void testString()
{
	string a;
	string b;

	a.append("test");
	b += "test";

	cout << a << endl;
	cout << b << endl;
}