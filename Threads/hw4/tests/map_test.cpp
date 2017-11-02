//
// Created by eugene on 11.10.2017
//
#ifdef _GTEST

#include "map.h"

#include <thread>
#include <vector>
#include <chrono>
#include <iostream>
#include <gtest/gtest.h>


TEST(m1, map_add_1_test) {
	//thread_pool::init();
	thread_pool pool(10);
	Promise<int> p;
	p.SetPool(&pool);
	pool.execute([&p](){
		p.Set(0);
	});
	Future<long> futa = Map(std::move(p.GetFuture()), [](int ii){
		return (long)(ii+1);
	});
	ASSERT_EQ(futa.Get(), 1);
}

TEST(m1, map_add_1_test_nothread) {
	//thread_pool::init();
	thread_pool pool(10);
	Promise<int> p;
	p.Set(0);
	Future<long> futa = Map(std::move(p.GetFuture()), [](int ii){
		return (long)(ii+1);
	});
	ASSERT_EQ(futa.Get(), 1);
}

TEST(m1, map_add_1_test_maps_thread) {
	//thread_pool::init();
	thread_pool pool(10);
	std::shared_ptr<Promise<int>> p(new Promise<int>());
	p->Set(0);
	pool.execute([p]{
		Future<long> futa = Map(std::move(p->GetFuture()), [](int ii){
			return (long)(ii+1);
		});	
		ASSERT_EQ(futa.Get(), 1);
	});
	std::this_thread::sleep_for(std::chrono::seconds(1));
}


TEST(m1, map_vector_sum_test) {
	int32_t const cnt_threads = 10;
	//thread_pool::init();
	thread_pool pool(cnt_threads);
	Promise<std::vector<int>> p;
	p.SetPool(&pool);
	pool.execute([&p](){
		std::vector<int> v = {11, 9, 2001};
		p.Set(v);
	});
	Future<int> futa = Map(std::move(p.GetFuture()), [](std::vector<int> vv){
		int elmao = 0;
		for(int & ii : vv) {
			elmao += ii;
		}
		return elmao;
	});
	ASSERT_EQ(futa.Get(), 2021);
}


#endif // _GTEST
