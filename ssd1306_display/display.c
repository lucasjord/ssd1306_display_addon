#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>

#define OLED_ADDR 0x3C
#define I2C_DEV "/dev/i2c-1"

#define COMMAND 0x00
#define DATA    0x40

static int fd;

// ASCII 5x8 font table
static const uint8_t font[][5] = {
#include "oled_fonts.h" // you'll need to copy this from UCTRONICS repo
};

void oled_write_cmd(uint8_t cmd) {
    uint8_t buf[2] = { COMMAND, cmd };
    write(fd, buf, 2);
}

void oled_write_data(uint8_t data) {
    uint8_t buf[2] = { DATA, data };
    write(fd, buf, 2);
}

void oled_set_xy(uint8_t x, uint8_t y) {
    oled_write_cmd(0xB0 + y);
    oled_write_cmd(((x & 0xF0) >> 4) | 0x10);
    oled_write_cmd((x & 0x0F) | 0x01);
}

void oled_putstr(uint8_t x, uint8_t y, const char *str) {
    oled_set_xy(x, y);
    while (*str) {
        if (*str < 32 || *str > 127) {
            str++;
            continue;
        }
        for (int i = 0; i < 5; i++) {
            oled_write_data(font[*str - 32][i]);
        }
        oled_write_data(0x00); // spacing
        str++;
    }
}

void oled_clear() {
    for (uint8_t page = 0; page < 8; page++) {
        oled_set_xy(0, page);
        for (uint8_t col = 0; col < 128; col++) {
            oled_write_data(0x00);
        }
    }
}

void oled_init() {
    oled_write_cmd(0xAE); // display off
    oled_write_cmd(0x00); // set low column
    oled_write_cmd(0x10); // set high column
    oled_write_cmd(0x40); // set start line
    oled_write_cmd(0x81); // contrast
    oled_write_cmd(0xCF);
    oled_write_cmd(0xA1); // segment remap
    oled_write_cmd(0xC8); // com scan dec
    oled_write_cmd(0xA6); // normal display
    oled_write_cmd(0xA8); // multiplex
    oled_write_cmd(0x3F);
    oled_write_cmd(0xD3); // display offset
    oled_write_cmd(0x00);
    oled_write_cmd(0xD5); // clock divide
    oled_write_cmd(0x80);
    oled_write_cmd(0xD9); // precharge
    oled_write_cmd(0xF1);
    oled_write_cmd(0xDA); // compins
    oled_write_cmd(0x12);
    oled_write_cmd(0xDB); // vcomh
    oled_write_cmd(0x40);
    oled_write_cmd(0x20); // memory mode
    oled_write_cmd(0x00);
    oled_write_cmd(0x8D); // charge pump
    oled_write_cmd(0x14);
    oled_write_cmd(0xAF); // display on
}

int main() {
    fd = open(I2C_DEV, O_RDWR);
    if (fd < 0) {
        perror("Failed to open I2C device");
        return 1;
    }

    if (ioctl(fd, I2C_SLAVE, OLED_ADDR) < 0) {
        perror("Failed to set I2C address");
        close(fd);
        return 1;
    }

    oled_init();
    oled_clear();
    oled_putstr(0, 0, "Hello from HA!");
    oled_putstr(0, 2, "SSD1306 I2C OK");

    close(fd);
    return 0;
}

