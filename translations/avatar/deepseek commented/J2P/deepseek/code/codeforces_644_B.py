import sys

def main():
    n = int(input().strip())  # Read the number of tasks
    b = int(input().strip())  # Read the buffer size
    ans = [0] * n  # Array to store task completion times
    q = []  # Queue to manage buffer

    # Process each task
    for i in range(n):
        t, d = map(int, input().strip().split())  # Read the task's start time and duration

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
    print(" ".join(map(str, ans)))

if __name__ == "__main__":
    main()
