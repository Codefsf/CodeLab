#include <vector>

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

