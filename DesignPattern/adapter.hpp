#include <iostream>
#include <memory>

/*
设计模式：适配器模式
设计原则：

问题：

使用场景：1.封装有缺陷的外部接口
		  2.替换依赖的外部系统（常用与第三方模块，
								保证业务接口稳定，
								第三方变化点替换成本低）
		  3.兼容老版本接口

设计成本：
*/

using namespace std;

class Target {
public:
	void function1() {
		cout << __func__ << endl;
	}

	void function2() {
		cout << __func__ << endl;
	}

	void function3() {
		cout << __func__ << endl;
	}
};

class Adapter {
public:
	Adapter() : m_target(new Target){}

	void method1() {
		cout << __func__ << endl;
		m_target->function1();
	}

	void method2() {
		cout << __func__ << endl;
		m_target->function2();
	}

	void method3() {
		cout << __func__ << endl;
		m_target->function3();
	}

private:
	unique_ptr<Target>	m_target;
};

void testAdapter() {
	unique_ptr<Adapter> ada(new Adapter);
	ada->method1();
	ada->method2();
	ada->method3();
}