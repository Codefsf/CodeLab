#include <iostream>
#include <thread>
#include <atomic>
#include <vector>
#include <mutex>
#include <thread>
#include <Windows.h>

#include <condition_variable>

#include "producerconsumer.hpp"
#include "functionobject.hpp"
#include "lockdead.hpp"
#include "sync.hpp"
#include "future.hpp"
#include "promise.hpp"

using namespace std;

mutex mtx3;

unsigned long tls = 0;

void init() {
	tls = ::TlsAlloc();
	int* value = new int(100);
	::TlsSetValue(tls, value);

	unique_lock<mutex> lc(mtx3);
	cout << __func__ << " " << this_thread::get_id()
		 << " " << tls << endl;
}

void method() {
	int* value = (int*)::TlsGetValue(tls);
	if (!value) {
		cout << __func__ << "not init" << endl;
		return;
	}
	cout << __func__ << " " << this_thread::get_id()
		<< " " << *value << endl;
}

void threadTest() {
	init();

	method();

	this_thread::sleep_for(100s);
}

int main() {
	//init();

	thread th1(threadTest);
	/*thread th2(threadTest);
	thread th3(threadTest);
	thread th4(threadTest);
	thread th5(threadTest);
	thread th6(threadTest);*/

	method();

	th1.join();
	/*th2.join();
	th3.join();
	th4.join();
	th5.join();
	th6.join();*/
}