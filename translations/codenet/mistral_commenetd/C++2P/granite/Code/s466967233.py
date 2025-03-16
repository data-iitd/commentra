
import sys

# Read input values
N, K = map(int, input().split())
A = list(map(int, input().split()))
B = [-1] * (2 * 10 ** 5 + 1)
B[1] = 0
now = 1
cnt = 0

# Simulation of the algorithm
j = 1
while j <= K:
    # Move to the next node
    now = A[now - 1]

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
        now = A[now - 1]

# Print the answer
print(now)

