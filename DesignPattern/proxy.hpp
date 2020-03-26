#include <iostream>
#include <memory>

//设计原则：依赖倒置；

//使用场景：1.代理类可以做些权限控制，缓存等功能；
//			2.实现类提供核心功能，代理类提供辅助功能；

//设计成本：

using namespace std;

class SubjectBase {
public:
	SubjectBase() = default;
	virtual ~SubjectBase() {};

	virtual void method() = 0;
};

class SubjectP : public SubjectBase{
public:
	SubjectP() = default;
	~SubjectP() {};

	void method() {
		cout << "Subject method" << endl;
	}
};

class SubjectProxy {
public:
	SubjectProxy() : m_impl(nullptr) {}
	~SubjectProxy() = default;

	void setProxy(shared_ptr<SubjectBase> impl) {
		m_impl = impl;
	}

	void deleteProxy()
	{
		m_impl.reset();
	}

	bool method() {
		if (!login())
			return false;
		
		m_impl->method();

		if (!logout())
			return false;
	}

	bool login() {
		cout << "Login" << endl;
		return true;
	}

	bool logout() {
		cout << "Logout" << endl;
		return true;
	}

private:
	shared_ptr<SubjectBase> m_impl;
};

void testProxy() 
{
	unique_ptr<SubjectProxy> proxy(new SubjectProxy);
	shared_ptr<SubjectBase> impl(new SubjectP);

	proxy->setProxy(impl);
	proxy->method();
}