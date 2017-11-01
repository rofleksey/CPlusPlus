#include <functional>
#include <queue>
#include <thread>
#include <mutex>
#include <vector>
#include <condition_variable>
#include <atomic>
#include <memory>
#include <iostream>
#include "thread_pool.h"
	thread_pool::thread_pool(int32_t num) {
		std::cerr << "Creating thread_pool with " << num << " threads!" << std::endl;
		for (int i = 0; i < num; i++) {
			workers.emplace_back([this]() -> void {
				while (true) {
					std::function<void()> task;
					{
						std::unique_lock<std::mutex> l(q_mutex);
						cond_var.wait(l, [this] {return this->stop || !q.empty(); });
						if (stop) {
							return;
						}
						task = std::move(q.front());
						q.pop();
					};
					std::cerr << "Executing task!" << std::endl;
					task();
				}
			});
		};
		std::cerr << "Created thread_pool with " << workers.size() << " threads!" << std::endl;
	}

	void thread_pool::execute(std::function<void()> const & f) {
		{
			std::unique_lock<std::mutex> l(q_mutex);
			if (stop) {
				std::cerr << "WATAFAK" << std::endl;
				return;
			}
			q.push(f);
		}
		cond_var.notify_one();
		std::cerr << "Added task to queue!" << std::endl;
	}


	thread_pool::~thread_pool() {
		{
			std::unique_lock<std::mutex> l(q_mutex);
			stop = true;
		}
		cond_var.notify_all();
		for (auto & w : workers) {
			w.join();
		}
		std::cerr << "ThreadPool destroyed!" << std::endl;
	}

