#!/bin/sh
set -e

echo "[INFO] Cloning SSD1306 repo..."
git clone https://github.com/UCTRONICS/U6143_ssd1306.git /opt/ssd1306

echo "[INFO] Compiling display.c with wiringPi..."
cd /opt/ssd1306/C
gcc display.c -o display -lwiringPi

echo "[INFO] Running display program..."
./display

