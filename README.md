# Beep Timer

A lightweight **C++** program that plays a short beep at random intervals, useful as an **action reminder**, simple **training metronome**, or timing cue.
On **Windows**, it uses the system `Beep()` API; on **Linux/macOS**, it uses the `play` command from **SoX** if available.

---

## Features

* Randomized pitch and interval timing
* Cross-platform structure (`include/` for headers, `src/` for sources)
* Safe exit with **Ctrl + C**
* Modular, easy to extend (custom sounds, durations, etc.)

---

## Build Instructions

### **Windows (MSVC)**

1. Install **Visual Studio Build Tools 2022** (with C++ support).
2. Open the project folder in **VS Code**.
3. Press **Ctrl + Shift +B** to build using the pre-configured `.vscode/tasks.json`.

This creates:

```
bin/beep_timer.exe
build/*.obj
bin/vc140.pdb
```

### **Linux / macOS (g++)**

```bash
g++ -std=c++17 -I include src/*.cpp -o bin/beep_timer
```

> Optional: install `sox` to enable the `play` command for sound output.
> Otherwise, the program falls back to a terminal bell (`\a`).

---

## Run

```bash
bin/beep_timer
```

Press **Ctrl + C** to stop the program gracefully.

---

## ⚙️ Configuration

Edit the settings in `src/main.cpp`:

```cpp
BeepSettings settings {
    1000,  // base frequency in Hz
    200,   // ± pitch variation in Hz
    std::chrono::milliseconds(200),  // beep duration
    std::chrono::seconds(3),         // min interval
    std::chrono::seconds(5)          // max interval
};
```

Adjust these to control the tone, variation, and timing between beeps.

---

## 🧩 Project Structure

```
include/         → Header files (.hpp)
src/             → Source files (.cpp)
bin/             → Compiled output (.exe, .pdb)
build/           → Intermediate .obj files
.vscode/         → Build and launch configs
```

---

## 📄 License

MIT License, free to use, modify, and distribute.