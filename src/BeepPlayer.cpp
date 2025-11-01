#include "BeepPlayer.hpp"

#include <cstdlib>
#include <iostream>
#include <thread>

#ifdef _WIN32
#include <windows.h>
#endif

void playBeep(const BeepSettings& settings) {
#ifdef _WIN32
    Beep(settings.frequencyHz, static_cast<DWORD>(settings.duration.count()));
#else
    // Try using "play" from SoX; fallback to console bell
    if (system("command -v play > /dev/null 2>&1") == 0) {
        std::string cmd = "play -nq -t alsa synth "
            + std::to_string(settings.duration.count() / 1000.0)
            + " sine " + std::to_string(settings.frequencyHz)
            + " > /dev/null 2>&1";

        system(cmd.c_str());
    }
    else {
        std::cout << '\a' << std::flush;
        std::this_thread::sleep_for(settings.duration);
    }
#endif
}