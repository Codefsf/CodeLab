#include <iostream>
#include <memory>
#include <future>
#include <thread>

using namespace std;

int work() {
	cout << "Start thread" << endl;
	this_thread::sleep_for(10s);

	cout << "End thread" << endl;
	return 2;
}


void  testFuture() {
	auto fu = async(launch::async, work);

	cout << "Output:" << fu.get();
}