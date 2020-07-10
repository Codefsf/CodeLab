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
	/*
	vector<int> vec;
	for (int i = 0; i < 100; i++)
		vec.push_back(i);

	int sum = accumulate(vec.begin(), vec.end(), 0, MyAddLambda);

	cout << "Sum is: " << sum << endl;

	cout << "Count is " << count(vec.begin(), vec.end(), 0) << endl;
	*/

	vector<int> vec;
	
	for (int i = 22; i < 33; i++)
		vec.push_back(i);
	for (int i = 0; i < 10; i++)
		vec.push_back(i);

	sort(vec.begin(), vec.end());

	for_each(vec.begin(), vec.end(), [](int item) {
		cout << item << endl;
	});

	cout << binary_search(vec.begin(), vec.end(), 50) << endl;

	auto re = equal_range(vec.begin(), vec.end(), 3);
	if (re.first != re.second) {
		cout << distance(re.first, re.second) << endl;
	}

	int num = 66;
	auto re1 = lower_bound(vec.begin(), vec.end(), num);
	if (re1 != vec.end() && *re1 == num) {
		cout << "Find: " << *re1 << endl;
	}
	else {
		vec.insert(re1, num);
	}

	cout << "-------------Start------------" << endl;
	vec.erase(vec.begin(), lower_bound(vec.begin(), vec.end(), 8));

	for_each(vec.begin(), vec.end(), [](int item) {
		cout << item << endl;
	});
}

