#include <iostream>
#include <memory>
#include <vector>
#include <list>

/*
���ģʽ��״̬ģʽ
���ԭ��

���⣺��ν��״̬ģʽ����չ���⣿ʹ����Ͽ���ԭ��

ʹ�ó�����1.
		  2.
		  3.

��Ƴɱ���
*/

using namespace std;

class StateBase {
public:
	virtual void method() = 0;
};

class State1 : public StateBase {
public:
	void method() {
		cout << "State1 method" << endl;
	}
};

class State2 : public StateBase {
public:
	void method() {
		cout << "State2 method" << endl;
	}
};

class State3 : public StateBase {
public:
	void method() {
		cout << "State3 method" << endl;
	}
};

class Context {
public:
	void init() {

	}

	void method() {

	}

private:
	list<unique_ptr<StateBase>> m_vec;
};



void testState() {

}