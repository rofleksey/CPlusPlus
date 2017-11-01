#include <functional>
#include <queue>
#include <thread>
#include <mutex>
#include <vector>
#include <condition_variable>
#include <atomic>
#include <memory>
#include "shared_state.h"
#include "future.h"

template<typename T>
Future<T>::Future(Future<T> && f) {
	state = std::move(f.state);
}

template<typename T>
const T& Future<T>::Get() const {
	Wait();
	if (state->isException) {
		std::rethrow_exception(state->exc);
	}
	return state->result;
}

template<typename T>
bool Future<T>::IsReady() const {
	return state->isSet;
}

template<typename T>
void Future<T>::Wait() const{
	if (state->isSet) {
		return;	
	}
	std::unique_lock<std::mutex> l(state->fMutex);
	while (!state->isSet && !state->promiseDestroyed) {
		state->cVar.wait(l);
	}
	if (state->promiseDestroyed && !state->isSet) {
		throw std::runtime_error("Can't wait for value any longer - promise has been destroyed!");
	}
}

template<typename T>
Future<T>::Future(std::shared_ptr<shared_state<T>> s) {
	state = s;
}

//void


Future<void>::Future(Future<void> && f) {
	state = std::move(f.state);
}

void Future<void>::Get() const {
	Wait();
	if (state->isException) {
		std::rethrow_exception(state->exc);
	}
}

bool Future<void>::IsReady() const {
	return state->isSet;
}

void Future<void>::Wait() const {
	if (state->isSet) {
		return;
	}
	std::unique_lock<std::mutex> l(state->fMutex);
	while (!state->isSet && !state->promiseDestroyed) {
		state->cVar.wait(l);
	}
	if (state->promiseDestroyed && !state->isSet) {
		throw std::runtime_error("Can't wait for value any longer - promise has been destroyed!");
	}
}


Future<void>::Future(std::shared_ptr<shared_state<void>> s) {
	state = s;
}

//T&

template<typename T>
Future<T&>::Future(Future<T&> && f) {
	state = std::move(f.state);
}

template<typename T>
T& Future<T&>::Get(){
	Wait();
	if (state->isException) {
		std::rethrow_exception(state->exc);
	}
	return *state->result;
}

template<typename T>
bool Future<T&>::IsReady() const {
	return state->isSet;
}

template<typename T>
void Future<T&>::Wait() const{
	if (state->isSet) {
		return;	
	}
	std::unique_lock<std::mutex> l(state->fMutex);
	while (!state->isSet && !state->promiseDestroyed) {
		state->cVar.wait(l);
	}
	if (state->promiseDestroyed && !state->isSet) {
		throw std::runtime_error("Can't wait for value any longer - promise has been destroyed!");
	}
}

template<typename T>
Future<T&>::Future(std::shared_ptr<shared_state<T&>> s) {
	state = s;
}
