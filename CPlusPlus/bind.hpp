#include <iostream>
#include <functional>

using namespace std;

void outputFunciton(int num) {
	cout << "Function:" << num << endl;
}

class OutputClass {
public:
	void output(int num) {
		cout << "Class Function:" << num << endl;
	}
private:

};

void testBind() {
	OutputClass cl;

	auto func		= bind(outputFunciton, 4);
	auto classfunc	= bind(&OutputClass::output, cl, 3);

	func();
	classfunc();
}


