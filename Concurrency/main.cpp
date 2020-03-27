#include <iostream>
#include <thread>
#include <atomic>
#include <vector>
#include <mutex>

using namespace std;

atomic<int> g_at = 0;
mutex g_mutex;

void output() {
	lock_guard<mutex> mu(g_mutex);
	cout << "Thread id :" << g_at++ << endl;

	if (g_at == 5)
		this_thread::sleep_for(chrono::seconds(5));
}

int main() {
	vector<thread> ths;
	for (int i = 0; i < 10; i++) {
		ths.push_back(thread(output));
	}

	for (auto &item : ths) {
		cout << "Joinable:" << item.joinable() << endl;
		item.join();
	}
}