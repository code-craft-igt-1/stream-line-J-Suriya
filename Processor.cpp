#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <sstream>
#include "Sender.h"

class Processor {
public:
    void processReadings(const std::vector<Reading>& readings) {
        for (const auto& reading : readings) {
            processValue(temperatureValues, reading.temperature, "Temperature");
            processValue(pulseValues, reading.pulseRate, "Pulse Rate");
            processValue(spo2Values, reading.spo2, "SPO2");
        }
    }

private:
    std::vector<double> temperatureValues;
    std::vector<int> pulseValues;
    std::vector<int> spo2Values;

    template<typename T>
    void processValue(std::vector<T>& values, T value, const std::string& parameterName) {
        values.push_back(value);
        if (values.size() > 5) {
            values.erase(values.begin());
        }

        T minVal = *std::min_element(values.begin(), values.end());
        T maxVal = *std::max_element(values.begin(), values.end());
        double avg = std::accumulate(values.begin(), values.end(), 0.0) / values.size();

        std::cout << parameterName << " - Min: " << minVal << ", Max: " << maxVal << ", Avg: " << avg << std::endl;
    }
};

int main() {
    Sender sender;
    sender.generateReadings();

    Processor processor;
    processor.processReadings(sender.getReadings());

    return 0;
}
has context menu