#!/bin/sh

echo "[INFO] Starting SSD1306 display add-on..."

# Compile the display code
echo "[INFO] Compiling display.c..."
gcc /display.c -o /display -li2c

if [ $? -ne 0 ]; then
    echo "[ERROR] Compilation failed."
    exit 1
fi

# Run the binary
echo "[INFO] Running display binary..."
/display

echo "[INFO] Display process completed."

