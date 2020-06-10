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

