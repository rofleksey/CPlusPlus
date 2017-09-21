#pragma once
#include <functional>
#include <queue>
#include <thread>
#include <mutex>
#include <vector>
#include <condition_variable>
#include <atomic>
#include <memory>
#include "future.h"

template<typename T>
class promise {
public:
	promise() {
		futa = std::shared_ptr<future<T>>(new future<T>());
	}
	promise(promise<T> && p) {
		futa = p.futa;
	}
	std::shared_ptr<future<T>> getFuture() {
		return futa;
	}
	void set(const T& o) {
		checkError();
		std::unique_lock<std::mutex> l(futa->fMutex);
		futa->setInternal(o);
	}
	void set(T&& o) {
		checkError();
		std::unique_lock<std::mutex> l(futa->fMutex);
		futa->setInternal(o);
	}
	void setException(const std::exception_ptr & o) {
		checkError();
		std::unique_lock<std::mutex> l(futa->fMutex);
		futa->setInternalError(o);
	}
private:
	std::shared_ptr<future<T>> futa;
	bool checkError() {
		if (futa->isSet) {
			throw std::exception("Promise's set method is called multiple times!");
		}
	}
};