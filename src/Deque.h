#pragma once

#include <cstddef>
#include <memory>

template<class T>
class Deque {
public:
    T access(std::size_t k);
    void push_front(T r);
    void push_back(T r);
    T pop_front();
    T pop_back();
private:
   std::unique_ptr<T[]> _data;
};
