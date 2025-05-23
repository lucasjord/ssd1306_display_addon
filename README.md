# SSD1306 Display Home Assistant Add-on

This Home Assistant add-on clones, compiles, and runs the UCTRONICS SSD1306 display demo C code on startup.

## Features

- Clones the [U6143_ssd1306 GitHub repo](https://github.com/lucasjord/U6143_ssd1306/)
- Compiles `display.c` using `gcc`
- Runs the display demo program on boot

## Installation

1. Copy this repo into your Home Assistant `addons` directory (or fork and host it).
2. In Home Assistant UI:
   - Navigate to **Settings → Add-ons → Add-on Store**
   - Click **⋮ → Repositories**
   - Add your local repo path or GitHub URL
   - Install and start the add-on

## Notes

- Requires access to I2C `/dev/i2c-1`
- Uses `wiringPi` (ensure your device supports it)

## License

MIT

