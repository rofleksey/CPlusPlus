#pragma once
#include <functional>
#include <queue>
#include <thread>
#include <mutex>
#include <vector>
#include <condition_variable>
#include <atomic>
template<typename T>
class future {

	template<typename T>
	friend class promise;

public:
	future(future<T> && f) {
		result = std::move(f.result);
		isSet = std::move(f.isSet);
		fMutex = std::move(f.fMutex);
		isException = std::move(f.isException);
		exc = std::move(f.exc);
	}
	const T & get() const {
		wait();
		if (isException) {
			std::rethrow_exception(exc);
		}
		return result;
	}
	bool isReady() const {
		return isSet;
	}
	void wait() const{
		if (isSet) {
			return;	
		}
		std::unique_lock<mutex> l(fMutex);
		while (!isSet) {
			cVar.wait(l);
		}
	}
private:
	std::atomic<bool> isSet;
	mutable std::condition_variable cVar;
	mutable std::mutex fMutex;
	T result;
	bool isException;
	std::exception_ptr exc;
	future() {
		isSet = false;
		isException = false;
	}
	void setInternal(const T& r) {
		result = r;
		isSet = true;
		cVar.notify_all();
	}
	void setInternalError(const std::exception_ptr & ptr) {
		isException = true;
		exc = ptr;
		isSet = true;
		cVar.notify_all();
	}
};