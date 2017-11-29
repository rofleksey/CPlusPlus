//
// Created by eugene on 11.10.2017
//
#ifdef _GTEST

#include "thread_pool.h"

#include <thread>
#include <vector>
#include <iostream>
#include <gtest/gtest.h>



TEST(para, TestVector) {
	thread_pool pool(10);
	std::vector<int> v {1, 2, 3, 4, 5};
	pool.parallel(v.begin(), v.end(), [](int ii){return ii*ii;});
	std::vector<int> result{1, 4, 9, 16, 25};
	ASSERT_EQ(v, result);
}

TEST(para, TestSingleElement) {
	thread_pool pool(10);
	std::vector<int> v {1};
	pool.parallel(v.begin(), v.end(), [](int ii){
		return 1488;
	});
	std::vector<int> result{1488};
	ASSERT_EQ(v, result);
}

TEST(para, TestTwoElements) {
	thread_pool pool(10);
	std::vector<int> v {151, 5632};
	pool.parallel(v.begin(), v.end(), [](int ii){
		return 1337+ii;
	});
	std::vector<int> result{1488, 6969};
	ASSERT_EQ(v, result);
}

TEST(para, TestWait) {
	thread_pool pool(10);
	std::vector<int> v {1, 2, 3, 4, 5};
	auto start = std::chrono::steady_clock::now();
	pool.parallel(v.begin(), v.end(), [](int ii){
		std::this_thread::sleep_for(std::chrono::seconds(1));
		return ii;
	});
	bool b = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count() < 1500;
	ASSERT_TRUE(b);
}

#endif // _GTEST
