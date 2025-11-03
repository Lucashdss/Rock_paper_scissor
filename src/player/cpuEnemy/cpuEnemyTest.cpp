#include <catch2/catch_test_macros.hpp>
#include "cpuEnemy.hpp"

TEST_CASE("cpu basic test", "[cpuEnemy]") {
    cpuEnemy cpu;

    SECTION("stard class gives a 0 value"){
        REQUIRE(cpu.getMoveIndex() == 0);
    }
}