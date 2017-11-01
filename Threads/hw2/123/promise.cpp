#include <functional>
#include <queue>
#include <thread>
#include <mutex>
#include <vector>
#include <condition_variable>
#include <atomic>
#include <memory>
#include "shared_state.h"
#include "promise.h"

template<typename T>
Promise<T>::Promise() {
	state = std::shared_ptr<shared_state<T>>(new shared_state<T>());
}

template<typename T>
Promise<T>::~Promise() {
	state->onPromiseDestroyed();
}

template<typename T>
Promise<T>::Promise(Promise<T> && p) {
	state = p.state;
}

template<typename T>
Future<T> Promise<T>::GetFuture() {
	return Future<T>(state);
}

template<typename T>
void Promise<T>::Set(const T& o) {
	std::unique_lock<std::mutex> l(state->fMutex);
	checkError();
	state->set(o);
}

template<typename T>
void Promise<T>::Set(T&& o) {
	std::unique_lock<std::mutex> l(state->fMutex);
	checkError();
	state->set(o);
}

template<typename T>
void Promise<T>::SetException(const std::exception_ptr & o) {
	std::unique_lock<std::mutex> l(state->fMutex);
	checkError();
	state->setError(o);
}

template<typename T>
bool Promise<T>::checkError() {
	if (state->isSet) {
		throw std::runtime_error("Attempting to call promise's set method multiple times!");
	}
}

//void


Promise<void>::Promise() {
	state = std::shared_ptr<shared_state<void>>(new shared_state<void>());
}
Promise<void>::~Promise() {
	state->onPromiseDestroyed();
}
Promise<void>::Promise(Promise<void> && p) {
	state = p.state;
}
Future<void> Promise<void>::GetFuture() {
	return Future<void>(state);
}
void Promise<void>::Set() {
	std::unique_lock<std::mutex> l(state->fMutex);
	checkError();
	state->set();
}
void Promise<void>::SetException(const std::exception_ptr & o) {
	std::unique_lock<std::mutex> l(state->fMutex);
	checkError();
	state->setError(o);
}
bool Promise<void>::checkError() {
	if (state->isSet) {
		throw std::runtime_error("Attempting to call promise's set method multiple times!");
	}
}

//T&
template<typename T>
Promise<T&>::Promise() {
	state = std::shared_ptr<shared_state<T&>>(new shared_state<T&>());
}
template<typename T>
Promise<T&>::~Promise() {
	state->onPromiseDestroyed();
}

template<typename T>
Promise<T&>::Promise(Promise<T&> && p) {
	state = p.state;
}

template<typename T>
Future<T&> Promise<T&>::GetFuture() {
	return Future<T&>(state);
}

template<typename T>
void Promise<T&>::Set(T& o) {
	std::unique_lock<std::mutex> l(state->fMutex);
	checkError();
	state->set(o);
}

template<typename T>
void Promise<T&>::Set(T&& o) {
	std::unique_lock<std::mutex> l(state->fMutex);
	checkError();
	state->set(o);
}

template<typename T>
void Promise<T&>::SetException(const std::exception_ptr & o) {
	std::unique_lock<std::mutex> l(state->fMutex);
	checkError();
	state->setError(o);
}

template<typename T>
bool Promise<T&>::checkError() {
	if (state->isSet) {
		throw std::runtime_error("Attempting to call promise's set method multiple times!");
	}
}
