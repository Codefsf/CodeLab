#include <iostream>
#include <memory>
#include <list>
#include <mutex>

using namespace std;

class Observer;
class Subject {
public:
	Subject() {}
	~Subject() {}

	void sub(const weak_ptr<Observer> &obs) {
		lock_guard<mutex> lock(m_mutex);
		auto itr = find(m_list.begin(), m_list.end(), obs);
		if (itr == m_list.end()) {
			m_list.push_back(obs);
		}
	}

	void notify() {
		lock_guard<mutex> lock(m_mutex);
		for (auto &item : m_list) {
			if (item.expired()) {
				m_list.erase(item);
				continue;
			}

			auto sh = item.lock();
			if (sh != nullptr) {
				sh->update();
			}
		}
	}

private:
	list<weak_ptr<Observer>>	m_list;
	mutex						m_mutex;
};

class Observer {
public:
	Observer(int num) : 
		m_num(num)
	{
	}

	~Observer() {}

	void update() {
		cout << "Update observer" << endl;
	}

private:
	int		m_num { 0 };
};

void testObserver()
{
	
}