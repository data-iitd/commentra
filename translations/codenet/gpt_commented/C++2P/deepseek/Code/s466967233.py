import sys

# Read the number of elements (N) and the number of steps (K)
N, K = map(int, sys.stdin.readline().split())

# Read the elements into array A
A = [0] + list(map(int, sys.stdin.readline().split()))

# Array to track the first visit time to each position, initialized to -1
B = [-1] * (200100)

# Current position, starting at 1
now = 1
# Counter for the number of steps taken
cnt = 0

# Mark the starting position as visited at step 0
B[1] = 0

# Traverse the positions based on the values in A
for j in range(1, K + 1):
    now = A[now]  # Move to the next position based on the current position

    # Check if the current position has been visited before
    if B[now] == -1:
        B[now] = j  # Mark the position with the current step count
    else:
        # If the position has been visited, calculate the cycle length
        cnt = j  # Store the current step count
        break  # Exit the loop as we found a cycle

# If we did not reach the maximum steps K
if j < K:
    # Calculate how many additional steps to take within the cycle
    tmp = (K - B[now]) % (cnt - B[now])
    
    # Move to the final position after the calculated additional steps
    for _ in range(tmp):
        now = A[now]  # Continue moving to the next position

# Output the final position after all movements
print(now)
