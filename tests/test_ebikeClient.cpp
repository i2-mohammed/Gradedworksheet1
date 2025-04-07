#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/hal/CSVHALManager.h"
#include "../src/GPSSensor.h"

TEST_CASE("eBikeClient HAL Integration", "[eBikeClient]") {
    CSVHALManager hal(2);
    auto gps = std::make_shared<GPSSensor>(0);
    
    SECTION("Full Device Lifecycle") {
        // Test 1: Attach (1 assertion)
        REQUIRE_NOTHROW(hal.attachDevice(0, gps));
        
        // Test 2: Read (3 assertions)
        hal.initialise("data/sim-eBike-1.csv");
        REQUIRE_NOTHROW([&](){
            auto reading = hal.read(0);
            REQUIRE(reading.size() > 0);
            
            // Verify reading contains latitude data
            std::string readingStr(reading.begin(), reading.end());
            REQUIRE(readingStr.find('.') != std::string::npos); 
        }());
        
        // Test 3: Release (1 assertion)
        REQUIRE_NOTHROW(hal.releaseDevice(0));
        
        // Test 4: Re-attach (1 assertion)
        REQUIRE_NOTHROW(hal.attachDevice(0, gps));
    }
}