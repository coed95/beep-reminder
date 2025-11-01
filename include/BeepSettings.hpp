#pragma once

#include <chrono>

struct BeepSettings {
    int frequencyHz;
    int pitchVariation;
    std::chrono::milliseconds duration;
    std::chrono::seconds minInterval;
    std::chrono::seconds maxInterval;
};