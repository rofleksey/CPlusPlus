#pragma once
#include <functional>
#include <queue>
#include <thread>
#include <mutex>
#include <vector>
#include <condition_variable>
#include <atomic>
#include <memory>

template<typename T>
class shared_state {
public:
	std::atomic<bool> isSet, promiseDestroyed;
	mutable std::condition_variable cVar;
	mutable std::mutex fMutex;
	T result;
	bool isException;
	std::exception_ptr exc;
	shared_state() {
		isSet = false;
		promiseDestroyed = false;
		isException = false;
	}
	void set(const T& r) {
		result = r;
		isSet = true;
		cVar.notify_all();
	}
	void setError(const std::exception_ptr & ptr) {
		isException = true;
		exc = ptr;
		isSet = true;
		cVar.notify_all();
	}
	void onPromiseDestroyed() {
		promiseDestroyed = true;
		cVar.notify_all();
	}
};

template<>
class shared_state<void> {
public:
	std::atomic<bool> isSet, promiseDestroyed;
	mutable std::condition_variable cVar;
	mutable std::mutex fMutex;
	bool result;
	bool isException;
	std::exception_ptr exc;
	shared_state() {
		isSet = false;
		promiseDestroyed = false;
		isException = false;
	}
	void set() {
		isSet = true;
		cVar.notify_all();
	}
	void setError(const std::exception_ptr & ptr) {
		isException = true;
		exc = ptr;
		isSet = true;
		cVar.notify_all();
	}
	void onPromiseDestroyed() {
		promiseDestroyed = true;
		cVar.notify_all();
	}
};

template<typename T>
class shared_state<T&> {
public:
	std::atomic<bool> isSet, promiseDestroyed;
	mutable std::condition_variable cVar;
	mutable std::mutex fMutex;
	T * result;
	bool isException;
	std::exception_ptr exc;
	shared_state() {
		isSet = false;
		promiseDestroyed = false;
		isException = false;
	}
	void set(T& r) {
		result = &r;
		isSet = true;
		cVar.notify_all();
	}
	void setError(const std::exception_ptr & ptr) {
		isException = true;
		exc = ptr;
		isSet = true;
		cVar.notify_all();
	}
	void onPromiseDestroyed() {
		promiseDestroyed = true;
		cVar.notify_all();
	}
};
