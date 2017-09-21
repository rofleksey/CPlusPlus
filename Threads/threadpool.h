#pragma once
#include <functional>
#include <queue>
#include <thread>
#include <mutex>
#include <vector>
#include <condition_variable>
#include <atomic>
#include <memory>
#include "promise.h"
#include "future.h"
class threadpool
{
public:
	threadpool(unsigned int num = 1) {
		for (unsigned int i = 0; i < num; i++) {
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
					task();
				}
			});
		};
	}

	void execute(std::function<void()> const & f) {
		{
			std::unique_lock<std::mutex> l(q_mutex);
			if (stop) {
				return;
			}
			q.push(f);
		}
		cond_var.notify_one();
	}

	template<class F, class... Args>
	std::shared_ptr<future<typename std::result_of<F(Args...)>::type>> execPromise(F&& f, Args&&... args) {
		using r = typename std::result_of<F(Args...)>::type;
		std::function<r()> tmpFunc = std::bind(std::forward<F>(f), std::forward<Args>(args)...);
		std::shared_ptr<promise<r>> promisePtr(new promise<r>());
		std::function<void()> func = [promisePtr, tmpFunc]() {
			try {
				promisePtr->set(tmpFunc());
			}
			catch (...) {
				std::exception_ptr ptr = std::current_exception();
				promisePtr->setException(ptr);
			}
		};
		execute(func);
		return promisePtr->getFuture();	
	}


	~threadpool() {
		{
			std::unique_lock<std::mutex> l(q_mutex);
			stop = true;
		}
		cond_var.notify_all();
		for (auto & w : workers) {
			w.join();
		}
	}
private:
	std::queue<std::function<void()> > q;
	std::mutex q_mutex;
	std::vector<std::thread> workers;
	std::condition_variable cond_var;
	std::atomic<bool> stop;
};

