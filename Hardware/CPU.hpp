#include <iostream>
#include <thread>
#include <list>
#include <chrono>

using namespace std;

void CpuUsage() {
	cout << "Start thread id " << this_thread::get_id() << endl;
	while (true) {
		char* mem = new char[1024 * 1024];
		this_thread::sleep_for(2s);
	}
}

void testCPU() {
	list<thread> vec;
	for (int i = 0; i < 9; i++) {
		thread th(CpuUsage);
		vec.push_back(move(th));
	}

	for (auto &item : vec) {
		item.join();
	}
}