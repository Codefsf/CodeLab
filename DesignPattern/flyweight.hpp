#include <iostream>
#include <list>
#include <thread>
#include <chrono>

using namespace std;

class WidgetFly {
public:
	WidgetFly(bool index) :
		m_index(index) {
		m_mem = new char[1024 * 1024];
		memset(m_mem, 0, 1024 * 1024);
	}

	~WidgetFly() {
		if (m_mem)
			delete[]m_mem;
	}

	bool getState() const { return m_index; }
	void setState(const bool& index) { m_index = index; }

	bool getNum() const {
		cout << "Get num " << m_num << endl;
		return m_num; 
	}
	void setNum(const int& num) {
		cout << "Set num " << num << endl;
		memset(m_mem, 'a', 1024 * 1024);
		m_num = num; 
	}

private:
	bool	m_index;
	bool	m_num;
	char*	m_mem;
};

class WidgetPool {
public:
	WidgetPool(int num) : m_num(num) {}

	void init() {
		for (int i = 0; i < m_num; i++) {
			WidgetFly* wid = new WidgetFly(false);
			m_widgetList.push_back(wid);

			cout << "Create widget " << i << endl;
		}
	}

	WidgetFly* getWidget() {
		for (auto &item : m_widgetList) {
			if (!item->getState()) {
				item->setState(true);
				return item;
			}
		}

		return nullptr;
	}

	void backWidget(WidgetFly *wid) {
		for (auto &item : m_widgetList) {
			if (item == wid) {
				item->setState(false);
			}
		}
	}

private:
	int	m_num;
	list<WidgetFly*>	m_widgetList;
};

void testFlyweight() {
	WidgetPool pool(10);
	//pool.init();

	int num = 0;
	while (true) {
		if (num == 1000)
			break;

		//WidgetFly* wid = pool.getWidget();
		WidgetFly* wid = new WidgetFly(false);

		if (wid) {
			wid->setNum(num++);
			this_thread::sleep_for(chrono::milliseconds(10));
			//pool.backWidget(wid);

			delete wid;
		}
	}
}