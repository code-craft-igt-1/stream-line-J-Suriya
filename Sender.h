#ifndef SENDER_H_
#define SENDER_H_

#include <vector>
#include <string>

struct Reading {
    float temperature;
    int pulseRate;
    int spo2;
};

class Sender {
 public:
    void generateReadings();
    void sendReadings() const;

    // Getter for readings to use in tests
    const std::vector<Reading>& getReadings() const;

 private:
    std::vector<Reading> readings;

    float generateTemperature() const;
    int generatePulseRate() const;
    int generateSpo2() const;
};

#endif  // SENDER_H_
