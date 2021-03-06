#include <vector>
#include <algorithm>

using namespace std;

void testVectorBool() {
	/*测试vector<bool>类型的特点，
	  因为vector对于bool类型存储
	  方式的不同，导致通过C++11中
	  范围循环时必须用const引用，
	  而不能用非const引用。
	  如果必须要存储bool类型，可以
	  考虑deque替换vector。
	*/
	vector<bool> vec;
	vec.push_back(true);
	cout << vec.size() << endl;
	for (auto itr = vec.begin(); itr != vec.end(); itr++) {
		cout << *itr << endl;
	}

	for (const auto &item : vec) {
		cout << item << endl;
	}
}

//-----------------------------------------------
/*
vector对于自定义类型的要求：
1.可以拷贝构造
2.拥有默认构造函数
*/
class VecItem {
public:
	//VecItem() {}

	VecItem(int n) {
		num = new int(n);
	}

	//~VecItem() {}

	VecItem(const VecItem& item) = default;
	VecItem& operator=(const VecItem& item) = delete;

	int	*num {nullptr};
};

void testVectorItem()
{
	vector<VecItem> vec;

	cout << vec.size() << " " << vec.capacity() << endl;

	vec.push_back(VecItem(1));
	vec.push_back(VecItem(2));
	vec.push_back(VecItem(3));

	cout << vec.size() << " " << vec.capacity() << endl;

	for (auto &item : vec) {
		cout << *item.num << endl;
	}

	vec.push_back(VecItem(4));
	vec.push_back(VecItem(5));
	vec.push_back(VecItem(6));

	cout << "-----------------------" << endl;

	for (auto &item : vec) {
		cout << *item.num << endl;
	}
}

//-----------------------------------------------
/*
支持区间操作的函数：
insert
erase
assign
copy
reserve
*/

void outputVec(const vector<int> &vec, const string& title) {
	for (auto &item : vec) {
		cout << item << " ";
	}

	cout << title << " size:" << vec.size()
		<< " capacity:" << vec.capacity() << endl;
}

void testVecRange()
{
	vector<int> vec;

	cout << vec.size() << " " << vec.capacity() << endl;

	vec.reserve(3);

	cout << vec.size() << " " << vec.capacity() << endl;

	vec.resize(3);

	cout << vec.size() << " " << vec.capacity() << endl;

	outputVec(vec, "Before insert:");
	vec.insert(vec.begin(), 3, 3);
	outputVec(vec, "After insert:");

	outputVec(vec, "Before erase:");
	vec.erase(vec.begin(), vec.end());
	outputVec(vec, "After erase:");
}


//-----------------------------------------------
/*
remove和erase的区别
*/

void testRemoveErase()
{
	vector<int>	vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	outputVec(vec, "Before remove:");
	vec.erase(remove(vec.begin(), vec.end(), 1));
	outputVec(vec, "After remove:");
}

