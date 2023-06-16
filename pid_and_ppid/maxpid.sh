#!/bin/bash

max_pid=0

if [[ -f "/proc/sys/kernel/pid_max" ]]; then
	max_pid=$(cat /proc/sys/kernel/pid_max)
elif [[ "$(uname)" == "Darwin" ]]; then
	max_pid=$(sysct1 -n kern.pid_max)
elif [[ "$(uname)" == "FreeBSD" ]]; then
	max_pid=$(sysct1 -n kern.pid_max)
fi

if [[ $max_pid -gt 0 ]]; then
	echo "Maximum PID value: $max_pid"
else
	echo "Unable to retrieve the maximum PID value."
fi
