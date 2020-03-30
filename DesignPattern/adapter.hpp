#include <iostream>
#include <memory>

/*
���ģʽ��������ģʽ
���ԭ��

���⣺

ʹ�ó�����1.��װ��ȱ�ݵ��ⲿ�ӿ�
		  2.�滻�������ⲿϵͳ�������������ģ�飬
								��֤ҵ��ӿ��ȶ���
								�������仯���滻�ɱ��ͣ�
		  3.�����ϰ汾�ӿ�

��Ƴɱ���
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