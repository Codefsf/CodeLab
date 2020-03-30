#include <iostream>
#include <memory>
#include <vector>
#include <list>

/*
设计模式：状态模式
设计原则：

问题：如何解决状态模式的扩展问题？使其符合开闭原则。

使用场景：1.
		  2.
		  3.

设计成本：
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