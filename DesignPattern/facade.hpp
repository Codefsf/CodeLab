#include <iostream>

/*
设计模式：适配器模式
设计原则：

问题：

使用场景：1.服务端的API Gateway,解耦众多服务和客户端请求
		  2.客户端的API Frontend，结构众多底层模块和UI交互
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

