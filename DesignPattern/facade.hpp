#include <iostream>

/*
���ģʽ��������ģʽ
���ԭ��

���⣺

ʹ�ó�����1.����˵�API Gateway,�����ڶ����Ϳͻ�������
		  2.�ͻ��˵�API Frontend���ṹ�ڶ�ײ�ģ���UI����
*/

using namespace std;

class Server1 {
public:
	void method1() {
		cout << __func__ << "Server1" << endl;
	}
};

class Server2 {
public:
	void method2() {
		cout << __func__ << "Server2" << endl;
	}
};

class Gateway {
public:
	void method1() {
		m_server1.method1();
	}

	void method2() {
		m_server2.method2();
	}

private:
	Server1	m_server1;
	Server2	m_server2;
};
void testFacadeClient()
{
	Gateway gate;
	gate.method1();
	gate.method2();
}

