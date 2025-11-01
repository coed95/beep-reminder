#include "BeepPlayer.hpp"
#include "BeepSettings.hpp"
#include "SignalHandler.hpp"

#include <chrono>
#include <cstdlib>
#include <iostream>
#include <thread>

using namespace std::chrono;

int main() {
    setupSignalHandler();

    BeepSettings settings {
        1000,               // frequencyHz
        200,                // pitchVariation
        milliseconds(200),  // duration
        seconds(3),         // minInterval
        seconds(5)          // maxInterval
    };

    std::cout << "Beep timer started (Ctrl+C to stop)\n";
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    while (!stopRequested) {
        // random frequency shift
        int delta = (std::rand() % (2 * settings.pitchVariation + 1)) - settings.pitchVariation;

        int actualFrequencyHz = settings.frequencyHz + delta;

        // clamp to not go negative or too low
        if (actualFrequencyHz < 37) {
            actualFrequencyHz = 37;
        }

        playBeep( {
            actualFrequencyHz,
            settings.pitchVariation,
            settings.duration,
            settings.minInterval,
            settings.maxInterval
        } );

        auto range = settings.maxInterval - settings.minInterval;
        auto delay = settings.minInterval + milliseconds(std::rand() % duration_cast<milliseconds>(range).count());

        std::this_thread::sleep_for(delay);
    }

    std::cout << "\nBeep timer stopped.\n";

    return 0;
}