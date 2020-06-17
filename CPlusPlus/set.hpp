#include <set>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class MySetItem {
public:
	MySetItem(int num, string name) :
		m_num(num),
		m_name(name){}

	~MySetItem() {}

	bool operator<(const MySetItem& item) const {
		return m_num < item.m_num && m_name < item.m_name;
	}
//For test
//private:
	int		m_num {0};
	string	m_name{ "" };
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

	MySetItem item1(1, "name1");
	MySetItem item2(2, "name2");
	MySetItem item3(3, "name3");
	
	set<MySetItem> myset;
	myset.insert(item1);
	myset.insert(item2);
	myset.insert(item3);

	for (auto &item : myset) {
		cout << item.m_name << " " << item.m_num << endl;
	}

	MySetItem item4(3, "name3");
	auto itr = myset.find(item4);

	cout << (*itr).m_name << " " << (*itr).m_num << endl;
}