#include <iostream>
#include <mutex>

using namespace std;

class LockDead {
public:
	void lockprintf()
	{
		lock_guard<mutex> guard(m_mutex);
		printf();
		cout << __func__ << endl;
	}

	void printf() 
	{
		lock_guard<mutex> guard(m_mutex);
		cout << __func__ << endl;
	}
private:
	mutex	m_mutex;
};

void testLockDead() {
	LockDead ld;
	ld.lockprintf();
	ld.printf();
}