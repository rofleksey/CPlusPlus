//
// Created by eugene on 11.10.2017
//
#ifdef _GTEST

#include "flatten.h"

#include <thread>
#include <vector>
#include <iostream>
#include <gtest/gtest.h>



TEST(ft, Test1) {
	Promise<int> p1;
	Promise<double> p2;
	Promise<Future<int>> p3;
	Promise<int> p4;
	p1.Set(1337);
	p2.Set(1488.6969);
	p4.Set(228);
	p3.Set(p4.GetFuture());
	auto t = std::make_tuple('s', std::move(p1.GetFuture()), std::move(p2.GetFuture()), std::move(p3.GetFuture()));
	auto t1 = Flatten(t).Get();
	auto result = std::make_tuple('s', 1337, 1488.6969, 228);
	ASSERT_EQ(t1, result);
}

#endif // _GTEST
