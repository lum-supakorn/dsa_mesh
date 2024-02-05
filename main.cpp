#include "Deque.h"
#include <iostream>

int main() {
    Deque<int> deque;
    deque.push_back(1);
    deque.push_back(2);
    deque.push_back(3);
    std::cout << deque.access(0) << std::endl;
    std::cout << deque.access(1) << std::endl;
    std::cout << deque.access(2) << std::endl;
    return 0;
}