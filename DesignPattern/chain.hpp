#include <iostream>
#include <list>

using namespace std;

class Handler {
public:
	virtual bool process(int index) = 0;
};

class HandlerGreater : public Handler {
public:
	bool process(int index) {
		cout << "Process greater " << index << endl;
		if (index > 0)
			return true;
		else
			return false;
	}
};

class HandlerLess : public Handler {
public:
	bool process(int index) {
		cout << "Process less " << index << endl;
		if (index < 0)
			return true;
		else
			return false;
	}
};

class HandleChain {
public:
	void addHandle(Handler *handle) {
		if (handle)
			m_list.push_back(handle);
	}

	void removeHandle(Handler *handle) {
		for (auto itr = m_list.begin(); itr != m_list.end();) {
			if (*itr == handle) {
				itr = m_list.erase(itr);
			}
			else {
				itr++;
			}
		}
	}

	void process(int index) {
		for (auto &item : m_list) {
			if (item->process(index))
				return;
		}
	}
private:
	list<Handler*>	m_list;
};


void testChain() {
	HandlerGreater gr;
	HandlerLess	   le;

	HandleChain	   ch;

	ch.addHandle(&gr);
	ch.addHandle(&le);

	ch.process(-5);
}