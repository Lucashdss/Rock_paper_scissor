#include <catch2/catch_test_macros.hpp>
#include "player.hpp"

TEST_CASE("player basic test", "[player]") {
    player player;

    SECTION("stard class gives a 0 value"){
        REQUIRE(player.getMoveIndex() == 0);
    }

    SECTION("set and get move index"){
        player.setMoveIndexToPaper();
        REQUIRE(player.getMoveIndex() == 2);
    }

    SECTION("set move index to zero"){
        player.setMoveIndexToRock();
        player.setMoveIndexToZero();
        REQUIRE(player.getMoveIndex() == 0);
    }
}