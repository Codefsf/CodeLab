#include <iostream>
#include <thread>
#include <condition_variable>
#include <vector>
#include <mutex>
#include <functional>

using namespace std;

mutex mtx1;

class ThreadObj {
public:
	void operator()() const {
		lock_guard<mutex> mu(mtx1);
		this_thread::sleep_for(chrono::seconds(1));

		cout << "Thread id:" << this_thread::get_id() << endl;
	}
};

void output1() {
	lock_guard<mutex> mu(mtx1);
	this_thread::sleep_for(chrono::seconds(1));

	cout << "Thread id:" << this_thread::get_id() << endl;
}

void testThreadObj() {
	vector<thread> vec;

	auto fun = []() {
		lock_guard<mutex> mu(mtx1);
		this_thread::sleep_for(chrono::seconds(1));

		cout << "Thread id:" << this_thread::get_id() << endl;
	};

	for (int i = 0; i < 10; i++) {
		vec.push_back(thread(fun));
	}

	for (auto &item : vec)
		item.join();

}