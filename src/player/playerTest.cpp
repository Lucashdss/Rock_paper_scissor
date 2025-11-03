#include <catch2/catch_test_macros.hpp>
#include "player.hpp"

TEST_CASE("player basic test", "[player]") {
    player player;

    SECTION("stard class gives a 0 value"){
        REQUIRE(player.getMoveIndex() == 0);
    }
}