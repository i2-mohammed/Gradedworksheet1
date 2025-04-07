#ifndef GPSSENSOR_H
#define GPSSENSOR_H

#include "hal/ISensor.h"
#include <vector>
#include <string>

class GPSSensor : public ISensor {
public:
    GPSSensor(int id) : sensorId(id) {}

    int getId() const override { return sensorId; }
    int getDimension() const override { return 2; } // Lat + Lon

    std::string format(std::vector<uint8_t> reading) override {
        std::string dataStr(reading.begin(), reading.end());
        size_t commaPos = dataStr.find(',');
        return "GPS: " + dataStr.substr(0, commaPos) + "; " + dataStr.substr(commaPos + 1);
    }

private:
    int sensorId;
};

#endif // GPSSENSOR_H