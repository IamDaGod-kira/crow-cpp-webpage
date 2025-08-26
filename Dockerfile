# Use an official C++ build image
FROM ubuntu:22.04

# Install dependencies
RUN apt-get update && \
    apt-get install -y libasio g++ cmake make git curl && \
        apt-get clean && rm -rf /var/lib/apt/lists/*

	# Set working directory
	WORKDIR /app

	# Copy project files
	COPY . .

	# Build the project
	RUN g++ -std=c++17 -O2 main.cpp -o app -lpthread

	# Expose Render's default port (you can set PORT in Render dashboard)
	EXPOSE 10000

	# Run the app
	CMD ["./app"]
