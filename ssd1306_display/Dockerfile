FROM debian:bullseye-slim

# Install dependencies
RUN apt-get update && apt-get install -y \
    git build-essential gcc make i2c-tools libi2c-dev

# Clone and build wiringPi
RUN git clone https://github.com/WiringPi/WiringPi.git /wiringPi && \
    cd /wiringPi && ./build

# Copy run script
COPY run.sh /run.sh
RUN chmod +x /run.sh

CMD [ "/run.sh" ]

