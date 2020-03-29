#include <thread>
#include <condition_variable>
#include <iostream>
#include <queue>

using namespace std;

mutex				mtx;
condition_variable	condiPro, condiCon;
queue<int>		g_que;
int g_max		= 10;

void producer() {
	while (true) {
		this_thread::sleep_for(chrono::seconds(1));

		unique_lock<mutex> mu(mtx);
		condiPro.wait(mu, []() { return g_que.size() != 0; });

		cout << "Producer:" << endl;

		condiCon.notify_all();
	}
}

void consumer() {
	while (true)
	{
		this_thread::sleep_for(chrono::seconds(1));
		unique_lock<mutex> mu(mtx);
		condiCon.wait(mu, [](){ return g_que.size() != 0; });

		cout << "-------Consumer:"  << this_thread::get_id() << endl;

		condiPro.notify_all();
	}
}

void testPC() {
	vector<thread> consumers, producers;

	consumers[3];

	for (int i = 0; i < 2; i++) {
		producers.push_back(thread(producer));
	}

	for (int i = 0; i < 2; i++) {
		consumers.push_back(thread(consumer));
	}

	for (auto &item : consumers)
		item.join();

	for (auto &item : producers)
		item.join();
}
