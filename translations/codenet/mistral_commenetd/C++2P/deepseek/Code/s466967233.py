import sys

# Read input values
N, K = map(int, sys.stdin.readline().split())

# Read array A
A = [0] + list(map(int, sys.stdin.readline().split()))

# Initialize B array with -1
B = [-1] * (200100)

# B[1] is always 0
B[1] = 0

# Simulation of the algorithm
now = 1
cnt = 0
j = 1

while j <= K:
    # Move to the next node
    now = A[now]

    # If the node has not been reached yet, update B[now]
    if B[now] == -1:
        B[now] = j
    else:
        # If the node has already been reached, calculate the answer
        cnt = j
        break

    j += 1

# If the simulation has not reached the end, calculate the answer
if j < K:
    tmp = (K - B[now]) % (cnt - B[now])

    # Move to the final node
    for _ in range(tmp):
        now = A[now]

# Print the answer
print(now)

