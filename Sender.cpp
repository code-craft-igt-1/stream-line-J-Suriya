#include "Sender.h"
#include <iostream>
#include <random>

float Sender::generateTemperature() const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> tempDist(36.0, 37.5);
    return static_cast<float>(tempDist(gen));
}

int Sender::generatePulseRate() const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> pulseDist(60, 100);
    return pulseDist(gen);
}

int Sender::generateSpo2() const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> spo2Dist(90, 100);
    return spo2Dist(gen);
}

void Sender::generateReadings() {
    for (int i = 0; i < 50; ++i) {
        Reading reading;
        reading.temperature = generateTemperature();
        reading.pulseRate = generatePulseRate();
        reading.spo2 = generateSpo2();
        readings.push_back(reading);
    }
}

void Sender::sendReadings() const {
    for (const auto& reading : readings) {
        std::cout << "Temperature: " << reading.temperature
                  << ", Pulse Rate: " << reading.pulseRate
                  << ", SPO2: " << reading.spo2 << std::endl;
    }
}

const std::vector<Reading>& Sender::getReadings() const {
    return readings;
}