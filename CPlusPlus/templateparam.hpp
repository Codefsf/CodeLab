#include <iostream>
#include <memory>
#include <functional>

using namespace std;

template <class T1, class T2>
class A {
public:
	void test() {
		cout << "Temp0" << endl;
	}


	T1 data1;
	T2 data2;
};

template <>
class A<int, int> {
public:
	void test() {
		cout << "Temp1" << endl;
	}

	int data1;
	int data2;
};

template <class T2>
class A<int, T2> {
public:
	void test() {
		cout << "Temp2" << endl;
	}

	int data1;
	T2 data2;
};

template <class T>
T max(const T lhs, const T rhs) {
	return lhs > rhs ? lhs : rhs;
}


function<int(int)> test() {
	int a = 1;
	auto la = [=](int b)->int {
		cout << a << b << endl;
		return a + b;
	};

	return la;
}

void testTemplateParam()
{
	auto la = test();

	cout << la(2) << endl;
}