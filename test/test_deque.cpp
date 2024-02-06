#include <catch2/catch_test_macros.hpp>

#include "Deque.h"

TEST_CASE("The number of items in the deque must be consistent with the number of insertions and removals.") {
    Deque<int> deque;

    SECTION("An empty deque has zero items.") {
        REQUIRE(deque.n() == 0);
    }

    SECTION("Three insertions result in three items.") {
        deque.push_back(1);
        deque.push_back(1);
        deque.push_back(1);
        REQUIRE(deque.n() == 3);
    }

    SECTION("Three insertions and one removal result in two items.") {
        deque.push_back(1);
        deque.push_back(1);
        deque.push_back(1);
        deque.pop_back();
        REQUIRE(deque.n() == 2);
    }

    SECTION("Three insertions, one removal, and one insertion result in three items.") {
        deque.push_back(1);
        deque.push_back(1);
        deque.push_back(1);
        deque.pop_back();
        deque.push_back(1);
        REQUIRE(deque.n() == 3);
    }
}