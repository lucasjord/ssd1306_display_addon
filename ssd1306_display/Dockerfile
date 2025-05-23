FROM debian:bullseye-slim

# Install dependencies
RUN apt-get update && apt-get install -y \
    git build-essential gcc make i2c-tools libi2c-dev

# Clone and build wiringPi
#RUN git clone https://github.com/WiringPi/WiringPi.git /wiringPi && \
#    cd /wiringPi && ./build

# Install dependencies
RUN apt-get update && apt-get install -y \
    git build-essential gcc make i2c-tools libi2c-dev curl

# Clone WiringPi repo
RUN git clone https://github.com/WiringPi/WiringPi.git /wiringPi

# List files to confirm presence of build script
RUN ls -l /wiringPi && cat /wiringPi/build

# Make build script executable just in case
RUN chmod +x /wiringPi/build

# Run build script
RUN cd /wiringPi && ./build


# Copy run script
COPY run.sh /run.sh
RUN chmod +x /run.sh

CMD [ "/run.sh" ]

