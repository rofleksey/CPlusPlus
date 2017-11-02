//
// Created by eugene on 11.10.2017
//
#pragma once
#include <thread>
#include <iostream>
#include <memory>
#include <functional>
#include "thread_pool.h"
#include "promise.h"
#include "future.h"

template<typename T, typename F>
Future<typename std::result_of<F(T)>::type> Map(thread_pool * pool, Future<T> && futa, const F & func) {
	using K = typename std::result_of<F(T)>::type;
	std::shared_ptr<Promise<K>> p = std::shared_ptr<Promise<K>>(new Promise<K>());
	if(pool != nullptr) {
		pool->execute([&futa, &func, p] {
			p->Set(std::move(func(futa.Get())));
		});
	} else {
		std::thread([&futa, &func, p]{
			p->Set(std::move(func(futa.Get())));
		}).detach();
	}
	return std::move(p->GetFuture());
}


template<typename T, typename F>
Future<typename std::result_of<F(T)>::type> Map(Future<T> && futa, const F & func) {
	thread_pool * pool;
	if(futa.GetPool() != nullptr) {
		std::cerr << "Using future's pool" << std::endl;
		pool = futa.GetPool();
	} else if(thread_pool::curPool != nullptr){
		std::cerr << "Using Map's pool" << std::endl;
		pool = thread_pool::curPool;

	} else {
		std::cerr << "Using new std::thread" <<std::endl;
		pool = nullptr;
	}
	std::cerr<< (pool == nullptr) << std::endl;
	return std::move(Map(pool, std::move(futa), func));
}

