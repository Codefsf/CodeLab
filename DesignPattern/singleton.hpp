#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

static SingleTon* instance = nullptr;
static mutex singleMutex;

class SingleTon {
	static SingleTon* getInstance() {
		if (instance == nullptr) {
			lock_guard<mutex> guard(singleMutex);
			if (instance == nullptr) {
				instance = new SingleTon;
			}
		}

		return instance;
	}
};

void test1() {

}

void test2() {

}

void testSington()
{
	thread t1(test1);
	thread t2(test2);

	t1.join();
	t2.join();
}