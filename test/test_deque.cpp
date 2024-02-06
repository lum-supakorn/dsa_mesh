#include <catch2/catch_test_macros.hpp>

#include "Deque.h"

TEST_CASE("An empty deque has zero items.") {
    Deque<int> deque;
    REQUIRE(deque.n() == 0);
}

TEST_CASE("Three insertions result in three items.") {
    Deque<int> deque;
    deque.push_back(1);
    deque.push_back(1);
    deque.push_back(1);
    REQUIRE(deque.n() == 3);
}