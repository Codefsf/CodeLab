#include <iostream>
#include <memory>

/*设计原则：开闭原则；

使用场景：1.定义接口的同时，定义了接口的调用方式
		  2.不变的部分：接口的调用顺序
		  3.可变的部分：接口的实现逻辑
		  4.可通过扩展子类来增加父类功能

设计成本：
*/

using namespace std;

class TemplateBase {
public:
	TemplateBase() = default;
	virtual ~TemplateBase() {};

protected:
	virtual void login() = 0;
	virtual void output() = 0;
	virtual void logout() = 0;

public:
	void templateMethod() {
		login();
		output();
		logout();
	}
};

class TemplateDriver : public TemplateBase {
public:
	void login() {
		cout << "Login" << endl;
	}
	void output() {
		cout << "Output" << endl;
	}
	void logout() {
		cout << "Logout" << endl;
	}
};

class TemplateDriver1 : public TemplateBase {
public:
	void login() {
		cout << "--------Login" << endl;
	}
	void output() {
		cout << "--------Output" << endl;
	}
	void logout() {
		cout << "--------Logout" << endl;
	}
};

void testTemplateMethod() {
	unique_ptr<TemplateBase> base(new TemplateDriver);
	base->templateMethod();

	unique_ptr<TemplateBase> base1(new TemplateDriver1);
	base1->templateMethod();
}