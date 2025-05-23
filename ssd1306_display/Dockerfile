ARG BUILD_FROM
FROM ${BUILD_FROM}

# Add labels
LABEL maintainer="lucas.jordan.hyland@gmail.com"

# Install dependencies
RUN apk add --no-cache gcc musl-dev linux-headers git

# Copy script
COPY run.sh /run.sh
RUN chmod +x /run.sh

CMD [ "/run.sh" ]

