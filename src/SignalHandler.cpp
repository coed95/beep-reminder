#include "SignalHandler.hpp"

#include <csignal>
#include <iostream>

std::atomic<bool> stopRequested { false };

void signalHandler(int signal) {
    if (signal == SIGINT) {
        stopRequested = true;
        std::cout << "\nStopping...\n";
    }
}

void setupSignalHandler() {
    std::signal(SIGINT, signalHandler);
}