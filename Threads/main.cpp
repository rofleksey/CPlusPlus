// ConsoleApplication3.cpp: определяет точку входа для консольного приложения.
//
#include <iostream>
#include <memory>
#include "threadpool.h"
using namespace std;

int f(int d) {
	if (d == 0) {
		throw std::runtime_error("Division by zero!");
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	return d;
}


int main() {
	threadpool pool(2);
	vector<std::shared_ptr<future<int>>> vec;
	vec.push_back(pool.execPromise(f, 47));
	vec.push_back(pool.execPromise(f, 69));
	vec.push_back(pool.execPromise(f, 228));
	vec.push_back(pool.execPromise(f, 1337));
	vec.push_back(pool.execPromise(f, 0));
	for (int i = 0; i < vec.size(); i++) {
		try {
			cout << vec[i]->get() << endl;
		}
		catch (const std::exception& e) {
			cout << e.what() << endl;
		}
	}
	system("pause");
	return 0;
}

