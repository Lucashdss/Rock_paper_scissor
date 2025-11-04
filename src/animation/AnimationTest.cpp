#include <catch2/catch_test_macros.hpp>
#include "animation.hpp"

TEST_CASE("animation basic test", "[animation]") {
    Animation hands("/assets/paper.png");

    SECTION("initial position is (0,0)") {
    }