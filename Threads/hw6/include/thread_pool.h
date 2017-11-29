#pragma once
#include <functional>
#include <queue>
#include <thread>
#include <mutex>
#include <vector>
#include <condition_variable>
#include <atomic>
#include <memory>
#include <vector>
#include <iostream>
#include "promise.h"
#include "future.h"
class thread_pool
{
public:
	thread_pool(int32_t num);
	void execute(std::function<void()> const & f);
	~thread_pool();
	
	static thread_local thread_pool * curPool;

	template <typename T, typename F>
	void parallel(T a, T b, F f){
		auto c = a;
		std::vector<Future<void>> waiters;
		while(c != b) {
			if(c+1 == b) {
				*c = f(*c);
			} else {
				std::shared_ptr<Promise<void>> p(new Promise<void>);
				waiters.push_back(std::move(p->GetFuture()));
				execute([c, &f, p](){
					*c = f(*c);
					p->Set();	
				});
			}
			c++;
		} 
		for(size_t i = 0; i < waiters.size(); i++) {
			waiters[i].Wait();
		}
	}
private:
	std::queue<std::function<void()> > q;
	std::mutex q_mutex;
	std::vector<std::thread> workers;
	std::condition_variable cond_var;
	std::atomic<bool> stop;
};

