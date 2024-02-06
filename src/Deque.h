#pragma once

#include <new>          // std::bad_alloc
#include <stdexcept>    // std::out_of_range
#include <cmath>        // std::ceil

template<class T>
class Deque {
public:
    explicit Deque() : _data((T*)std::malloc(sizeof(T))), _n(0), _max(1) {}
    ~Deque() { std::free(_data); }
    T access(std::size_t k);
    void push_front(T r);
    void push_back(T r);
    T pop_front();
    T pop_back();
    std::size_t n();
private:
   T* _data;
   std::size_t _n;
   std::size_t _max;
   void resize(std::size_t newSize);
};

template<class T>
void Deque<T>::push_front(T r) {
    if (_n == _max) {
        auto newSize = static_cast<std::size_t>(std::ceil(_n*1.5));
        resize(newSize);
        _max = newSize;
    } else if (_n == 0) {
        _data[0] = r;
        _n++;
        return;
    }
    // To make room for the first item, we must move every other items by 1 slot. This process is O(n) and inefficient.
    // This is why a deque is usually implemented as a doubly-linked list.
    for (std::size_t i = _n; i--;) { // Decrementing loop with unsigned integer
        _data[i+1] = _data[i];
    }
    _data[0] = r;
    _n++;
}

template<class T>
T Deque<T>::pop_back() {
    if (_n > 0) {
        // Data remains (no shrinking yet) but can be overwritten
        _n--;
        return _data[_n];
    } else {
        throw std::out_of_range("Popping an empty deque");
    }
}

template<class T>
std::size_t Deque<T>::n() {
    return _n;
}

template<class T>
void Deque<T>::push_back(T r) {
    if (_n == _max) {
        auto newSize = static_cast<std::size_t>(std::ceil(_n*1.5));
        resize(newSize);
        _max = newSize;
    }
    _data[_n] = r;
    _n++;
}

template<class T>
T Deque<T>::access(std::size_t k) {
    if (k >= _n) {
        throw std::out_of_range("Deque index out of range");
    } else {
        return _data[k];
    }
}

template<class T>
void Deque<T>::resize(std::size_t newSize) {
    if (newSize == 0) {
        std::free(_data);
        _data = nullptr;
    } else {
        if (void* mem = std::realloc(_data, newSize*sizeof(T))) {
            _data = static_cast<T*>(mem);
        } else {
            throw std::bad_alloc();
        }
    }
}
