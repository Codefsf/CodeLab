#include <iostream>
#include <memory>
#include <list>

/*
2020年4月16日

设计模式：组合模式
设计原则：

问题：

变化点：组合中元素的数量和功能
稳定点：组合元素的接口

使用场景：1.构建客户端程序中界面控件树时，对于整体事件的处理机制
		  2.当能够形成树形结构，整体的树形结构对外保持接口统一，就是一个组合模式的行为
		  3.

设计成本：
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
