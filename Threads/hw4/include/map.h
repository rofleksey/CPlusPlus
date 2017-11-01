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
Future<typename std::result_of<F(T)>::type> Map(thread_pool & pool, const Future<T> & futa, const F & func) {
	using K = typename std::result_of<F(T)>::type;
	std::shared_ptr<Promise<K>> p = std::shared_ptr<Promise<K>>(new Promise<K>());
	pool.execute([&futa, &func, p] {
		p->Set(std::move(func(futa.Get())));
	});
	return std::move(p->GetFuture());
}



