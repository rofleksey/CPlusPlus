#include "promise.h"
#include "future.h"
#include <iostream>
#include <tuple>


template<typename T, typename Q = void>
struct nested_type_getter {
    typedef T type_t;
};

template<typename T>
struct nested_type_getter<Future<T>> {
    typedef typename nested_type_getter<T>::type_t type_t;
};

template <typename ...Args>
struct nested_type_getter<std::tuple<Args...>> {
    typedef std::tuple<typename nested_type_getter<Args>::type_t...> type_t;
};


template<typename T>
T DiveFunc(const Future<T> &future) {
    return std::move(future.Get());
}
template <typename T>
auto DiveFunc(const Future<Future<T>> & future){
    return std::move(DiveFunc(std::move(future.Get())));
}

template <typename T>
auto DiveFunc(T f) {
    return f;
}

template<typename ...Args, std::size_t... I>
auto FlattenImpl(const std::tuple<Args...>& a, std::index_sequence<I...>){
    return std::make_tuple(DiveFunc(std::get<I>(a))...);
}

template <class ... TPar, typename Indices = std::make_index_sequence<sizeof...(TPar)>>
auto Flatten(std::tuple<TPar...> & tuple){
    using K = typename nested_type_getter<std::tuple<TPar...>>::type_t;
    std::shared_ptr<Promise<K>> p (new Promise<K>);
    std::thread([p, &tuple](){
        auto t = FlattenImpl(tuple, Indices{});
        p->Set(t);
    }).detach();
    return p->GetFuture();
}
