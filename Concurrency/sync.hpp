#include <iostream>
#include <mutex>
#include <condition_variable>
#include <queue>

using namespace std;

mutex				g_mutex1, g_mutex2, g_mutex3;
condition_variable	g_condition1, g_condition2;
queue<int>			g_queue;
int					g_int = 0;


	static void input() 
	{
		while (true) {
			unique_lock<mutex> lc(g_mutex1);
			g_condition1.wait(lc);

			{
				unique_lock<mutex> lc(g_mutex3);
				g_queue.push(g_int++);
				cout << "Input:" << g_queue.back() << endl;
			}
			this_thread::sleep_for(1s);
			g_condition2.notify_all();
		}
	}

	static void output() 
	{
		while (true) {
			unique_lock<mutex> lc(g_mutex2);
			g_condition2.wait(lc, []() { return g_queue.size() != 0; });

			{
				unique_lock<mutex> lc(g_mutex3);
				int num = g_queue.front();
				g_queue.pop();

				cout << "----------Output:" << num << endl;
			}

			this_thread::sleep_for(1s);
			g_condition1.notify_all();
		}
	}

void testSync()
{
	g_queue.push(g_int++);

	thread th1(input);
	thread th11(input);
	thread th111(input);
	thread th1111(input);
	thread th11111(input);


	thread th2(output);

	th1.join();
	th11.join();
	th111.join();
	th1111.join();
	th11111.join();

	th2.join();
}