# Development Setup — Teensy 2.0 in VS Code

## Prerequisites

- [VS Code](https://code.visualstudio.com/)
- [PlatformIO IDE extension](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide) (install from VS Code extensions panel)

PlatformIO handles the compiler toolchain, Teensyduino libraries, and flashing — no Arduino IDE required.

## Project Setup

1. Open VS Code and click the PlatformIO icon in the sidebar
2. Select **New Project**
3. Fill in:
   - **Name:** CastleCabController
   - **Board:** Teensy 2.0
   - **Framework:** Arduino
4. Click **Finish** — PlatformIO will scaffold the project and install the Teensy platform

## Project Structure

```
CastleCabController/
├── platformio.ini       # Board and build configuration
├── src/
│   └── main.cpp         # Your sketch (replaces .ino, same Arduino API)
└── include/             # Header files
```

Your `platformio.ini` should look like:

```ini
[env:teensy20]
platform = teensy
board = teensy20
framework = arduino
monitor_speed = 115200
```

## Moving the Existing Sketch

Copy the contents of `CastleCabController.ino` into `src/main.cpp` and add the Arduino header at the top:

```cpp
#include <Arduino.h>
```

## Building and Uploading

| Action | VS Code shortcut | PlatformIO button |
|--------|-----------------|-------------------|
| Build  | `Ctrl+Alt+B`    | ✓ checkmark       |
| Upload | `Ctrl+Alt+U`    | → arrow           |
| Serial monitor | `Ctrl+Alt+S` | plug icon    |

When uploading, the Teensy bootloader will activate automatically. If it doesn't, press the reset button on the board.

## Serial Monitor

The serial monitor is built into PlatformIO. It connects at the baud rate set in `monitor_speed` in `platformio.ini`. Open it with the plug icon in the bottom toolbar or `Ctrl+Alt+S`.
