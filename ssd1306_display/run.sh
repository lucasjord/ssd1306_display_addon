#!/bin/sh

set -e

echo "[INFO] Cloning SSD1306 repo..."
#git clone https://github.com/UCTRONICS/U6143_ssd1306.git /opt/ssd1306 # original 
git clone https://github.com/lucasjord/U6143_ssd1306.git /opt/ssd1306  # new for this

echo "[INFO] Compiling display.c..."
cd /opt/ssd1306/C || exit 1
#gcc display.c -o display -lwiringPi
gcc display.c -o display -li2c

echo "[INFO] Running the program..."
./display

