
import sys

def main():
    # Read the number of elements (n) and the maximum size of the queue (b)
    n, b = map(int, input().split())

    # Initialize an array to store the results
    ans = [0] * n

    # Create a list to act as a queue for managing time values
    q = []

    # Process each element based on the input
    for i in range(n):
        # Read the time (t) and duration (d) for the current element
        t, d = map(int, input().split())

        # Remove elements from the front of the queue that are no longer valid (i.e., their time is less than or equal to t)
        while q and q[0] <= t:
            q.pop(0)

        # Check if the size of the queue is within the allowed limit
        if len(q) <= b:
            # If the queue is empty, set the answer to the current time (t) plus duration (d)
            # Otherwise, set it to the last element in the queue plus duration (d)
            ans[i] = q[-1] + d if q else t + d

            # Add the computed answer to the queue
            q.append(ans[i])
        else:
            # If the queue size exceeds the limit, set the answer to -1
            ans[i] = -1

    # Print the results stored in the ans array
    print(*ans)

if __name__ == "__main__":
    main()

