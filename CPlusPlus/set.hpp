#include <set>
#include <iostream>

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

void testSet()
{
	set<MySetItem> myset;
	
	for (int i = 10; i > 0; i--) {
		myset.insert(MySetItem(i));
	}

	/*for (auto itr = myset.begin(); itr != myset.end(); itr++) {
		cout << (*itr).m_num << endl;
	}*/

	for (auto &item : myset) {
		cout << item.m_num << endl;
	}
}