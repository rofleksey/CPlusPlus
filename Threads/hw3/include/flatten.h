//
// Created by eugene on 11.10.2017
//
#pragma once
#include <thread>
#include <iostream>
#include <memory>
#include "promise.h"
#include "future.h"

template<typename T>
struct nested_type_getter;

template<typename T>
struct nested_type_getter<Future<T>> {
    typedef T type_t;
};

template<typename T>
struct nested_type_getter<Future<Future<T>>> {
    typedef typename nested_type_getter<Future<T>>::type_t type_t;
};


template<typename T>
auto Flatten(const Future<Future<T>> & f) {
	std::shared_ptr<Promise<typename nested_type_getter<Future<T>>::type_t>> p(new Promise<typename nested_type_getter<Future<T>>::type_t>());
	std::thread([p, &f](){
        	p->Set(std::move(FlattenImpl(f)));
    	}).detach();
	return std::move(p->GetFuture());
	//return std::move(Flatten(std::move(f.Get())));
}

template<typename T>
auto Flatten(const Future<T> & f) {
	std::shared_ptr<Promise<T>> p(new Promise<T>());
	std::thread([p, &f](){
        	p->Set(std::move(f.Get()));
    	}).detach();
	return std::move(p->GetFuture());
	//return std::move(f);
}

template<typename T>
auto FlattenImpl(const Future<Future<T>> & f) {
	return std::move(FlattenImpl(std::move(f.Get())));
}



template<typename T>
auto FlattenImpl(const Future<T> & f) {
	return std::move(f.Get());
}

template<template<typename, typename...> class C, typename T>
Future<C<T>> Flatten(C<Future<T>> const & col) {
	std::shared_ptr<Promise<C<T>>> p(new Promise<C<T>>());
	std::thread t([p, &col](){
		C<T> output = C<T>();
        	for(const Future<T> & f : col) {
			output.insert(std::end(output), f.Get());
		}
		p->Set(output);
    	});
	t.detach();
	return std::move(p->GetFuture());
}
