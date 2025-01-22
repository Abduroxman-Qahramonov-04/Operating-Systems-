#!/bin/bash

# Ensure correct number of parameters
if [ $# -ne 2 ]; then
    echo "Usage: $0 <process_name> <time_interval>"
    exit 1
fi

process_name="$1"
time_interval="$2"
zombie_count=0

while true; do
    # Get the process list
    process_info=$(ps -eo stat,comm | grep -w "$process_name")

    if [[ -z "$process_info" ]]; then
        echo "Process $process_name not found in the system."
        sleep "$time_interval"
        continue
    fi

    # Check if the process is in the Z (Zombie) state
    state=$(echo "$process_info" | head -n 1 | cut -d ' ' -f 1 | tr -d '[:space:]')

    if [[ "$state" == "Z" ]]; then
        zombie_count=$((zombie_count + 1))
        echo "Process $process_name is in Z state ($zombie_count consecutive checks)."
        if [[ $zombie_count -ge 5 ]]; then
            echo "Process $process_name has been in Z state for 5 consecutive checks. Exiting."
            exit 1
        fi
    else
        zombie_count=0
        echo "Process $process_name is not in Z state. Counter reset."
    fi

    # Wait before the next check
    sleep "$time_interval"
done
