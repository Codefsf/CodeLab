#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class MyAdd {
public:
	int operator()(int x, int y) const {
		return x + y * 2;
	}
};

static int MyAddFunc(int x, int y) {
	return x + y * 2;
};

auto MyAddLambda = [](int x, int y) {
	return x + y * 2;
};

void testAlgorithm()
{
	vector<int> vec;
	for (int i = 0; i < 100; i++)
		vec.push_back(i);

	int sum = accumulate(vec.begin(), vec.end(), 0, MyAddLambda);

	cout << "Sum is: " << sum << endl;
}