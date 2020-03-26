#include <iostream>
#include <memory>

//���ԭ���������ã�

//ʹ�ó�����1.�����������ЩȨ�޿��ƣ�����ȹ��ܣ�
//			2.ʵ�����ṩ���Ĺ��ܣ��������ṩ�������ܣ�

//��Ƴɱ���

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