#!/bin/bash

# Check for required arguments (PID and string)
if [ $# -ne 2 ]; then
  echo "Usage: $0 <PID> <string>"
  exit 1
fi

# Get the PID and string from arguments
pid=$1
string=$2

# Loop through each character in the string
for char in $(echo "$string" | fold -w1); do
  # Get the ASCII code of the character
  char_code=$(echo -n "$char" | od -An -t u1)

  # Convert ASCII code to binary string with leading zeros
  binary_string=$(echo "obase=2; $char_code" | bc)
  binary_string=$(printf "%08d" "$binary_string")

  # Loop through each bit in the binary string
  for bit in {0..7}; do
    read -t 0.0001  # This line can likely be removed

    # Extract the current bit value
    bit_value=${binary_string:$bit:1}

    # Send signal based on bit value
    if [[ "$bit_value" -eq 0 ]]; then
      kill -SIGUSR2 "$pid"
    else
      kill -SIGUSR1 "$pid"
    fi
  done
done

# Send SIGUSR2 eight times after the character processing loop
for num in {0..7}; do
  read -t 0.0001  # This line can likely be removed
  kill -SIGUSR2 "$pid"
done

