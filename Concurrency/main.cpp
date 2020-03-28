#include <iostream>
#include <thread>
#include <atomic>
#include <vector>
#include <mutex>
#include <condition_variable>

#include "producerconsumer.hpp"

using namespace std;

atomic<int> g_at = 0;
mutex g_mutex;
condition_variable g_cv;

bool g_index = false;

void output() {
	unique_lock<mutex> mu(g_mutex);

	if (!g_index)
		g_cv.wait(mu);

	cout << "Thread id :" << g_at++ << endl;
}

void go() {
	g_index = true;
	g_cv.notify_all();
	//g_cv.notify_one();
}

int main() {
	testPC();
}