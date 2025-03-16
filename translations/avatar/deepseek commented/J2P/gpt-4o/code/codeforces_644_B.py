from collections import deque

def main():
    n = int(input())  # Read the number of tasks
    b = int(input())  # Read the buffer size
    ans = [0] * n  # Array to store task completion times
    q = deque()  # Queue to manage buffer

    # Process each task
    for i in range(n):
        t, d = map(int, input().split())  # Read the task's start time and duration

        # Remove completed tasks from the front of the queue
        while q and q[0] <= t:
            q.popleft()

        # Check if the task can be added to the buffer
        if len(q) < b:
            ans[i] = (t if not q else q[-1]) + d
            q.append(ans[i])
        else:
            ans[i] = -1

    # Output the completion times of all tasks
    print(" ".join(map(str, ans)))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
