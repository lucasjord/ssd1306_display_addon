ARG BUILD_FROM
FROM $BUILD_FROM

ENV LANG C.UTF-8

# Install necessary packages
RUN apk add --no-cache git build-base i2c-tools linux-headers

# Clone WiringPi and build manually (skip ./build script)
RUN git clone https://github.com/WiringPi/WiringPi.git /wiringPi && \
    cd /wiringPi/wiringPi && make && make install && \
    cd /wiringPi/devLib && make && make install

# Copy your display.c file into the container
COPY display.c /app/display.c

# Build your display binary
RUN gcc -o /app/display /app/display.c -lwiringPi

# Run it on container start
CMD [ "/app/display" ]

