

import sys

# Main function to manage task processing with a buffer
def main():
    n, b = map(int, input().split()) # Read the number of tasks and buffer size
    ans = [0] * n # Array to store task completion times
    q = [] # Queue to manage buffer

    # Process each task
    for i in range(n):
        t, d = map(int, input().split()) # Read the task's start time and duration

        # Remove completed tasks from the front of the queue
        while q and q[0] <= t:
            q.pop(0)

        # Check if the task can be added to the buffer
        if len(q) <= b:
            ans[i] = (q[0] if q else t) + d
            q.append(ans[i])
        else:
            ans[i] = -1

    # Output the completion times of all tasks
    print(*ans)

if __name__ == "__main__":
    main()

