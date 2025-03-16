
import sys

# Read the number of tasks
n = int(sys.stdin.readline())

# Read the buffer size
b = int(sys.stdin.readline())

# Array to store task completion times
ans = [0] * n

# Queue to manage buffer
q = []

# Process each task
for i in range(n):
    # Read the task's start time
    t = int(sys.stdin.readline())

    # Read the task's duration
    d = int(sys.stdin.readline())

    # Remove completed tasks from the front of the queue
    while len(q) > 0 and q[0] <= t:
        q.pop(0)

    # Check if the task can be added to the buffer
    if len(q) <= b:
        ans[i] = (q[0] if len(q) > 0 else t) + d
        q.append(ans[i])
    else:
        ans[i] = -1

# Output the completion times of all tasks
for i in range(n):
    print(ans[i], end=" ")

# 