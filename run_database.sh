#!/bin/bash

# Name of the executable
EXECUTABLE="database_app"

# Log directory name
LOG_DIR="log"

# Check if the executable is already running using ps and grep
if ps aux | grep -v grep | grep -q "$EXECUTABLE"; then
    echo "$EXECUTABLE is already running."
    exit 1
else
    echo "Starting $EXECUTABLE..."
fi

# Create a new log directory if it doesn't exist
if [ -d "$LOG_DIR" ]; then
    # Get the current date and time
    TIMESTAMP=$(date +"%Y%m%d_%H%M%S")
    # Rename the existing log folder
    mv "$LOG_DIR" "${LOG_DIR}_${TIMESTAMP}"
fi

# Create a new log directory
mkdir -p "$LOG_DIR"

# Run the executable in the background and direct output to a log file
nohup ./"$EXECUTABLE" > "$LOG_DIR/${EXECUTABLE}.log" 2>&1 &

# Save the process ID (PID) of the running executable to a file
echo $! > "$LOG_DIR/${EXECUTABLE}_pid.txt"

echo "$EXECUTABLE started successfully."
