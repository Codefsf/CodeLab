#include <iostream>
#include <memory>

/*���ԭ�򣺿���ԭ��

ʹ�ó�����1.����ӿڵ�ͬʱ�������˽ӿڵĵ��÷�ʽ
		  2.����Ĳ��֣��ӿڵĵ���˳��
		  3.�ɱ�Ĳ��֣��ӿڵ�ʵ���߼�
		  4.��ͨ����չ���������Ӹ��๦��

��Ƴɱ���
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