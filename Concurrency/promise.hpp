#include <iostream>
#include <memory>
#include <future>
#include <thread>

using namespace std;

void work1(promise<int> pro) {
	cout << "Start" << endl;
	this_thread::sleep_for(5s);

	pro.set_value(10);

	cout << "End" << endl;
}


void  testPromise() {
	promise<int> pro;
	auto fu = pro.get_future();

	thread th(work1, move(pro));

	th.join();

	cout << fu.get() << endl;
}