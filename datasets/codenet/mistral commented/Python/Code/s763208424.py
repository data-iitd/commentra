# Import necessary libraries: math for floor function and heapq for min heap operations
from math import floor
from heapq import heappush, heappop

# Read input: number of nodes n and edges m
n, m = map(int, input().split())

# Initialize empty min heap a to store edge weights
a = []

# Read edges and add them to the min heap
for i in map(int, input().split()):
    # Push edge weight with negative sign to maintain min heap property
    heappush(a, -i)

# Function to calculate distance between two nodes using binary power
def dis(x, y):
    # Calculate the distance by dividing x by 2 raised to the power of y
    return floor(x / (2 ** y))

# For each of the m operations:
for _ in range(m):
    # Pop the minimum edge weight from the heap
    u = heappop(a)
    # Calculate the distance to all other nodes from the popped node
    for _ in range(n):
        # Push the distance to the popped node to the heap
        heappush(a, -dis(-u, i))

# Print the sum of all distances from the source node to all other nodes
print(-sum(a))
