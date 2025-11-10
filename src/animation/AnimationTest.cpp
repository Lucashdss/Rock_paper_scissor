#include <catch2/catch_test_macros.hpp>
#include "animation.hpp"

TEST_CASE("animation basic test", "[animation]") {
    Animation hands;

    SECTION("variables are initialized correctly") {
        Texture2D rockTexture = hands.getTexture();
        REQUIRE(rockTexture.id != 0); // Check if texture is loaded
    }
    {

    }