#include <iostream>
#include <string>

using namespace std;

class TestMove {
public:
	TestMove(string num):m_num(num) {
		cout << __func__ << num << endl;
	};

	~TestMove() {
		cout << __func__  << m_num << endl;
	}

	TestMove(const TestMove &move) {
		m_num = move.m_num;
		cout << __func__ << " copy " << m_num << endl;
	}

	TestMove& operator=(const TestMove &move) {
		m_num = move.m_num;
		cout << __func__ << " operator= " << m_num << endl;
		return *this;
	}

	TestMove(TestMove &&move) {
		m_num = move.m_num;
		move.m_num = "";
		cout << __func__ << " move " << m_num << endl;
	}

	TestMove& operator=(TestMove &&move) {
		m_num = move.m_num;
		move.m_num = "";
		cout << __func__ << " operator= " << m_num << endl;
		return *this;
	}
private:
	string m_num;
};

void testMove()
{
	

}