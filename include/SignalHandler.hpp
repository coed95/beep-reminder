#pragma once

#include <atomic>

extern std::atomic<bool> stopRequested;

void setupSignalHandler();