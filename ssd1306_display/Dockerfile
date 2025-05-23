ARG BUILD_FROM
FROM $BUILD_FROM

ENV LANG C.UTF-8

RUN apk add --no-cache git build-base i2c-tools linux-headers

# Build WiringPi manually
RUN git clone https://github.com/WiringPi/WiringPi.git /wiringPi && \
    cd /wiringPi/wiringPi && make && make install && \
    cd /wiringPi/devLib && make && make install

# Clone the full SSD1306 repo
RUN git clone https://github.com/UCTRONICS/U6143_ssd1306.git /ssd1306

# Build all .c files in /ssd1306/C and output executable /app/display
#RUN gcc /ssd1306/C/*.c -o /app/display -lwiringPi
RUN gcc -g -rdynamic /ssd1306_display/*.c -o /app/display -lwiringPi

CMD ["/app/display"]

