#include <iostream>
#include <memory>
#include <list>

/*
2020��4��16��

���ģʽ�����ģʽ
���ԭ��

���⣺

�仯�㣺�����Ԫ�ص������͹���
�ȶ��㣺���Ԫ�صĽӿ�

ʹ�ó�����1.�����ͻ��˳����н���ؼ���ʱ�����������¼��Ĵ������
		  2.���ܹ��γ����νṹ����������νṹ���Ᵽ�ֽӿ�ͳһ������һ�����ģʽ����Ϊ
		  3.

��Ƴɱ���
*/

using namespace std;

class Widget {
public:
	virtual void paint() = 0;
};

class Button : public Widget {
public:
	Button(int num) : m_num(num) {}

	void paint() {
		cout << "Paint button"  << m_num << endl;
	}

private:
	int m_num {0};
};

class Window : public Widget {
public: 
	void paint() {
		cout << "Paint window" << endl;
		for (auto &item : m_list) {
			item->paint();
		}
	}

	void addWidget(Widget* wid) {
		if (wid)
			m_list.push_back(wid);
	}

	void deleteWidget(Widget* wid) {
		for (auto itr = m_list.begin(); itr != m_list.end();) {
			if (wid == *itr)
				itr = m_list.erase(itr);
			else
				itr++;
		}
	}

private:
	list<Widget*>	m_list;
};

void testComposite() {
	Window win;
	Button btn1(1);
	Button btn2(2);
	Button btn3(3);

	win.addWidget(&btn1);
	win.addWidget(&btn2);
	win.addWidget(&btn3);

	win.paint();

	win.deleteWidget(&btn1);

	win.paint();
}
