#include <type_traits>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class MyTemplate {
public:
	MyTemplate(const T &t) : 
		m_data(t) 
	{}

	~MyTemplate() {}

	void setData(const T &t) {
		if (is_signed<T>::value) {
			cout << "Set signed value" << endl;
			m_data = t;
		}
		else {
			cout << "No set signed value" << endl;
		}
	}

	void Print() {
		cout << typeid(m_data).name() << endl;
	}
private:
	T	m_data;
};


void testTypeTraits()
{
	MyTemplate<int> te(5);
	te.Print();

	te.setData(8);
	te.Print();
}