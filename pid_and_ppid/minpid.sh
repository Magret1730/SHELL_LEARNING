#!/bin/bash

min_pid=0

while true; do
	if ! kill -0 "$min_pid" 2>/dev/null; then
		break
	fi
	((min_pid++))
done

echo "Minimum PID value: $min_pid"
