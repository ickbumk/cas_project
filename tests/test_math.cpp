// #include <catch2/catch_test_macros.hpp>
#include "mathUtils.hpp"
#include <catch2/catch.hpp>

TEST_CASE("minValue and maxValue") {
    std::vector<double> vals = {3.2, -5.5, 2.1, 9.9};

    REQUIRE(minValue(vals) == Approx(-5.5));
    REQUIRE(maxValue(vals) == Approx(9.9));

    std::vector<double> emptyVec;
    REQUIRE(minValue(emptyVec) == std::numeric_limits<double>::infinity());
    REQUIRE(maxValue(emptyVec) == -std::numeric_limits<double>::infinity());
}


TEST_CASE("calculateDistance") {
    std::vector<Vec3> vertices = {{0, 0, 0}, {1, 0, 0}, {0, 1, 0}};
    Vec3 point = {0, 0, 0};
    auto dists = calculateDistance(vertices, point);
    REQUIRE(dists.size() == 3);
    REQUIRE(dists[0] == Approx(0.0));
    REQUIRE(dists[1] == Approx(1.0));
    REQUIRE(dists[2] == Approx(1.0));
}
