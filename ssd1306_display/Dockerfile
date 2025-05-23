ARG BUILD_FROM
FROM ${BUILD_FROM}

LABEL maintainer="your_email@example.com"

# Install build tools and I2C headers
RUN apk add --no-cache build-base linux-headers i2c-tools

# Copy source code and font definitions
COPY display.c /display.c
COPY oled_fonts.h /oled_fonts.h
COPY run.sh /run.sh

RUN chmod +x /run.sh

CMD [ "/run.sh" ]
