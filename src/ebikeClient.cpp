#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <thread>
#include "hal/CSVHALManager.h"
#include "GPSSensor.h"

std::string getCurrentTimestamp() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::tm* now_tm = std::localtime(&now_time);
    
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", now_tm);
    return std::string(buffer);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <csv_file> <port_id>\n";
        return 1;
    }

    try {
        // Initialize HAL with 1 port
        CSVHALManager hal(1);
        hal.initialise(argv[1]);

        // Create and attach GPS sensor (ID=0)
        auto gps = std::make_shared<GPSSensor>(0);
        hal.attachDevice(std::stoi(argv[2]), gps);

        // Read and print 5 GPS readings
        for (int i = 0; i < 5; i++) {
            auto reading = hal.read(std::stoi(argv[2]));
            std::cout << "[" << getCurrentTimestamp() << "] " 
                      << gps->format(reading) << std::endl;
            
            // Pause 5 seconds between readings
            std::this_thread::sleep_for(std::chrono::seconds(5));
        }

        hal.releaseDevice(std::stoi(argv[2]));
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}