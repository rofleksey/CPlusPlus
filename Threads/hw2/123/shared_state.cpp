#include <functional>
#include <queue>
#include <thread>
#include <mutex>
#include <vector>
#include <condition_variable>
#include <atomic>
#include <memory>
#include "shared_state.h"


template<typename T>
shared_state<T>::shared_state() {
	isSet = false;
	promiseDestroyed = false;
	isException = false;
}

template<typename T>
void shared_state<T>::set(const T& r) {
	result = r;
	isSet = true;
	cVar.notify_all();
}

template<typename T>
void shared_state<T>::setError(const std::exception_ptr & ptr) {
	isException = true;
	exc = ptr;
	isSet = true;
	cVar.notify_all();
}

template<typename T>
void shared_state<T>::onPromiseDestroyed() {
	promiseDestroyed = true;
	cVar.notify_all();
}

//void

shared_state<void>::shared_state() {
	isSet = false;
	promiseDestroyed = false;
	isException = false;
}
void shared_state<void>::set() {
	isSet = true;
	cVar.notify_all();
}
void shared_state<void>::setError(const std::exception_ptr & ptr) {
	isException = true;
	exc = ptr;
	isSet = true;
	cVar.notify_all();
}
void shared_state<void>::onPromiseDestroyed() {
	promiseDestroyed = true;
	cVar.notify_all();
}

//T&
template<typename T>

shared_state<T&>::shared_state() {
	isSet = false;
	promiseDestroyed = false;
	isException = false;
}

template<typename T>
void shared_state<T&>::set(T& r) {
	result = &r;
	isSet = true;
	cVar.notify_all();
}

template<typename T>
void shared_state<T&>::setError(const std::exception_ptr & ptr) {
	isException = true;
	exc = ptr;
	isSet = true;
	cVar.notify_all();
}

template<typename T>
void shared_state<T&>::onPromiseDestroyed() {
	promiseDestroyed = true;
	cVar.notify_all();
}
