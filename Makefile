CXX = g++
CXXFLAGS = -std=c++11 -Wall -I./src -I./external

all: ebikeClient generateEBikeFile test_test_GPSSensor test_test_ebikeClient

ebikeClient: src/ebikeClient.cpp src/GPSSensor.h
	$(CXX) $(CXXFLAGS) $< -o build/$@

generateEBikeFile: src/util/generateEBikeFile.cpp
	$(CXX) $(CXXFLAGS) $< -o build/$@

test_test_GPSSensor: tests/test_GPSSensor.cpp src/GPSSensor.h
	$(CXX) $(CXXFLAGS) $< -o build/$@

test_test_ebikeClient: tests/test_ebikeClient.cpp src/GPSSensor.h src/hal/CSVHALManager.h
	$(CXX) $(CXXFLAGS) $< -o build/$@

clean:
	rm -f build/*.o build/ebikeClient build/generateEBikeFile build/test_*

.PHONY: all clean