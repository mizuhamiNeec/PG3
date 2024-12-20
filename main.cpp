#include <iostream>
#include <thread>
#include <mutex>

namespace {
	std::mutex mutex;
	int currentThread = 1;

	void Print(const int threadNum) {
		while (true) {
			std::lock_guard<std::mutex> lock(mutex);
			if (currentThread == threadNum) {
				std::cout << "thread " << threadNum << '\n';
				currentThread++;
				break;
			}
		}
	}
}

int main() {
	std::thread t1(Print, 1);
	std::thread t2(Print, 2);
	std::thread t3(Print, 3);

	t1.join();
	t2.join();
	t3.join();

	return 0;
}