
import sys

# Read input values for N and M
N, M = map(int, input().split())

# Constants and initializations
Inf = 1 << 62
# a, b, and c are arrays of size M
a = [0] * M
b = [0] * M
c = [0] * M

# Read input values for a, b, and c
for i in range(M):
    a[i], b[i], c[i] = map(int, input().split())
    # Set c to its negation
    c[i] = -c[i]

# Initialize the dist array with the maximum value
dist = [Inf] * N
# Set the initial distance of the source node to 0
dist[0] = 0

# Dijkstra's algorithm loop
for loop in range(N):
    for i in range(M):
        # Skip if the current node's distance is still the maximum value
        if dist[a[i]-1] == Inf:
            continue
        # Update the distance if the new path is shorter
        if dist[b[i]-1] > dist[a[i]-1] + c[i]:
            dist[b[i]-1] = dist[a[i]-1] + c[i]

# Calculate the answer
ans = dist[N-1]
navigate = [False] * N

# Dijkstra's algorithm loop (second pass)
for loop in range(N):
    for i in range(M):
        # Skip if the current node's distance is still the maximum value
        if dist[a[i]-1] == Inf:
            continue
        # Update the distance if the new path is shorter
        if dist[b[i]-1] > dist[a[i]-1] + c[i]:
            dist[b[i]-1] = dist[a[i]-1] + c[i]
            navigate[b[i]-1] = True
        # If the previous node is in the navigate array, set the current node's navigate array value to true
        if navigate[a[i]-1] == True:
            navigate[b[i]-1] = True

# Print the result
if navigate[N-1]:
    print("inf")
else:
    print(-ans)

# End of the code
