#include <iostream>
#include <thread>
#include <atomic>
#include <vector>
#include <mutex>
#include <condition_variable>

#include "producerconsumer.hpp"
#include "functionobject.hpp"
#include "lockdead.hpp"
#include "sync.hpp"

using namespace std;

int main() {
	testSync();
}