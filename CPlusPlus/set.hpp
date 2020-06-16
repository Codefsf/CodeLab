#include <set>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class MySetItem {
public:
	MySetItem(int num) : m_num(num){}
	~MySetItem() {}

	bool operator<(const MySetItem& item) const {
		return m_num < item.m_num;
	}
//For test
//private:
	int	m_num {0};
};

bool lessFunction(string* left, string* right) {
	return *left < *right;
};

void testSet()
{
	/*set<MySetItem> myset;

	for (int i = 100; i > 0; i--) {
		myset.insert(MySetItem(i));
	}*/

	/*for (auto itr = myset.begin(); itr != myset.end(); itr++) {
		cout << (*itr).m_num << endl;
	}*/

	/*for (auto &item : myset) {
		cout << item.m_num << endl;
	}*/

	auto lessFunctionLambda = [](string* left, string* right) {
		return *left < *right;
	};

	set<string*, decltype(lessFunction)> myStrSet;
	myStrSet.insert(new string("ahorse"));
	myStrSet.insert(new string("bmonkey"));
	myStrSet.insert(new string("cpig"));
	myStrSet.insert(new string("dfish"));

	for (auto &item : myStrSet) {
		cout << *item << endl;
	}
}