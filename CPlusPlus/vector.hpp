#include <vector>

using namespace std;

void testVectorBool() {
	/*����vector<bool>���͵��ص㣬
	  ��Ϊvector����bool���ʹ洢
	  ��ʽ�Ĳ�ͬ������ͨ��C++11��
	  ��Χѭ��ʱ������const���ã�
	  �������÷�const���á�
	  �������Ҫ�洢bool���ͣ�����
	  ����deque�滻vector��
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
vector�����Զ������͵�Ҫ��
1.���Կ�������
2.ӵ��Ĭ�Ϲ��캯��
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

