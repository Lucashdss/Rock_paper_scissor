#include <catch2/catch_test_macros.hpp>
#include "cpuEnemy.hpp"

TEST_CASE("cpu basic test", "[cpuEnemy]") {
    cpuEnemy cpu;

    SECTION("stard class gives a 0 value"){
        REQUIRE(cpu.getMoveIndex() == 0);
    }

    SECTION("Generate random move between 1 and 3"){
        int moveIndex = cpu.generateRandomMoveIndex();
        REQUIRE(moveIndex >= 1);
        REQUIRE(moveIndex <= 3);
    }

    SECTION("set move index to zero"){
        cpu.setMoveIndex(cpu.Paper);
        cpu.setMoveIndexToZero();
        REQUIRE(cpu.getMoveIndex() == 0);
    }
}