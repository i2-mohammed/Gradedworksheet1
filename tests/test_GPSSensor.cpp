#define CATCH_CONFIG_MAIN
#include "../external/catch.hpp"
#include "../src/GPSSensor.h"

TEST_CASE("GPSSensor ID and Dimension", "[GPSSensor]") {
    GPSSensor gps(0);
    
    // Test Case 1: Sensor properties (2 assertions)
    SECTION("Sensor Identification") {
        REQUIRE(gps.getId() == 0);
        REQUIRE(gps.getDimension() == 2);
    }
}

TEST_CASE("GPSSensor Data Formatting", "[GPSSensor]") {
    GPSSensor gps(0);
    std::vector<uint8_t> mockData = {'5','1','.','4','5',',','-','2','.','6'};
    
    // Test Case 2: Data formatting (1 assertion)
    REQUIRE(gps.format(mockData) == "GPS: 51.45; -2.6");
}