#include <catch2/catch_test_macros.hpp>

#include "Deque.h"

TEST_CASE("The number of items in the deque must be consistent with the number of insertions and removals.") {
    Deque<int> deque;

    SECTION("An empty deque has zero items.") {
        REQUIRE(deque.n() == 0);
    }

    SECTION("Three back insertions result in three items.") {
        deque.push_back(1);
        deque.push_back(1);
        deque.push_back(1);
        REQUIRE(deque.n() == 3);
    }

    SECTION("Three back insertions and one back removal result in two items.") {
        deque.push_back(1);
        deque.push_back(1);
        deque.push_back(1);
        deque.pop_back();
        REQUIRE(deque.n() == 2);
    }

    SECTION("Three back insertions, one back removal, and one back insertion result in three items.") {
        deque.push_back(1);
        deque.push_back(1);
        deque.push_back(1);
        deque.pop_back();
        deque.push_back(1);
        REQUIRE(deque.n() == 3);
    }

    SECTION("Three front insertions result in three items.") {
        deque.push_front(1);
        deque.push_front(1);
        deque.push_front(1);
        REQUIRE(deque.n() == 3);
    }

    SECTION("A combination of front and back insertions must result in a correct item order.") {
        deque.push_back(3);
        deque.push_front(2);
        deque.push_back(4);
        deque.push_front(1);
        REQUIRE(deque.access(0) == 1);
        REQUIRE(deque.access(1) == 2);
        REQUIRE(deque.access(2) == 3);
        REQUIRE(deque.access(3) == 4);
        REQUIRE(deque.n() == 4);
    }

    SECTION("Three front insertions and two front removals result in one item.") {
        deque.push_front(1);
        deque.push_front(1);
        deque.push_front(1);
        deque.pop_front();
        deque.pop_front();
        REQUIRE(deque.n() == 1);
    }

    SECTION("A combination of front insertions and front removals must result in a correct item order.") {
        deque.push_front(4);
        deque.push_front(3);
        deque.push_front(2);
        deque.push_front(1);
        deque.push_front(0);
        deque.push_front(0);
        deque.push_front(0);
        REQUIRE(deque.n() == 7);
        deque.pop_front();
        REQUIRE(deque.n() == 6);
        deque.pop_front();
        REQUIRE(deque.n() == 5);
        deque.pop_front();
        REQUIRE(deque.access(0) == 1);
        REQUIRE(deque.access(1) == 2);
        REQUIRE(deque.access(2) == 3);
        REQUIRE(deque.access(3) == 4);
        REQUIRE(deque.n() == 4);
    }
}