# Development Setup

## Prerequisites

- [VS Code](https://code.visualstudio.com/)
- [PlatformIO IDE extension](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide) — install from the VS Code extensions panel

PlatformIO handles the compiler toolchain, Teensyduino libraries, and flashing automatically. No Arduino IDE required.

## Getting Started

1. Clone the repository and open the project folder in VS Code:
   ```
   git clone <repo-url>
   cd CastleCabController
   code .
   ```
2. PlatformIO will detect `platformio.ini` and prompt you to install dependencies — click **Yes** (or let it install automatically).
3. Wait for the Teensy platform and framework to finish downloading (first-time only).

## Project Structure

```
CastleCabController/
├── platformio.ini       # Board and build configuration (Teensy 2.0, Arduino framework)
├── src/
│   └── main.cpp         # Main sketch
└── PINOUT.md            # Arduino integer → board label mapping for the Teensy 2.0
```

## Building and Uploading

| Action | VS Code shortcut | PlatformIO toolbar button |
|--------|-----------------|--------------------------|
| Build  | `Ctrl+Alt+B`    | ✓ checkmark              |
| Upload | `Ctrl+Alt+U`    | → arrow                  |
| Serial monitor | `Ctrl+Alt+S` | plug icon           |

Connect the Teensy 2.0 via USB before uploading. The Teensy bootloader activates automatically; if the upload stalls, press the reset button on the board.

## Serial Monitor

The serial monitor runs at 115200 baud (`Serial.begin(115200)` in `setup()`). Open it with the plug icon in the bottom toolbar or `Ctrl+Alt+S`.

## Pin Numbering

The Teensy 2.0 board labels pins with port names (e.g. `D0`, `B1`) rather than integers. Use `PINOUT.md` to look up the Arduino integer for any board-label pin.
