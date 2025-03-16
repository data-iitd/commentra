
import sys

# Read the number of elements (N) and the number of steps (K)
N, K = map(int, input().split())

# Read the elements into array A
A = list(map(int, input().split()))

# Initialize array B to -1 to indicate unvisited positions
B = [-1] * (N + 1)
B[0] = 0  # Starting point is visited at step 0

# Traverse the positions based on the values in A
now = 0
cnt = 0
for j in range(1, K + 1):
    now = A[now] - 1  # Move to the next position based on the current position

    # Check if the current position has been visited before
    if B[now] == -1:
        B[now] = j  # Mark the position with the current step count
    else:
        # If the position has been visited, calculate the cycle length
        cnt = j  # Store the current step count
        break  # Exit the loop as we found a cycle

# If we did not reach the maximum steps K
if j < K:
    tmp = (K - B[now]) % (cnt - B[now])

    # Move to the final position after the calculated additional steps
    for _ in range(tmp):
        now = A[now] - 1  # Continue moving to the next position

# Output the final position after all movements
print(now + 1)  # Output the final position after all movements

