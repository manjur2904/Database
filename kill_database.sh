#!/bin/bash

# Name of the executable
EXECUTABLE="database_app"

# Log directory name
LOG_DIR="log"

# Check if the executable is running
PID=$(ps -ef | grep "$EXECUTABLE" | grep -v grep | awk '{print $2}')

if [ ! -z "$PID" ]; then
    echo "Stopping $EXECUTABLE...$PID"

    # Kill the process
    kill -9 $PID

    # Wait for the process to terminate
    wait $PID 2>/dev/null

    # Confirm the process has been killed
    if ! ps -p $PID > /dev/null; then
        echo "$EXECUTABLE stopped successfully."
    else
        echo "Failed to stop $EXECUTABLE."
        exit 1
    fi

    # Optionally, remove the PID file
    # if [ -f "$LOG_DIR/${EXECUTABLE}_pid.txt" ]; then
    #     rm -f "$LOG_DIR/${EXECUTABLE}_pid.txt"
    # fi
else
    echo "$EXECUTABLE is not running."
fi
