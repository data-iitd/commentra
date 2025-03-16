
from math import floor
from heapq import heappush, heappop

# Read the number of elements (n) and the number of operations (m)
n, m = map(int, input().split())

# Initialize an empty heap
a = []

# Read n integers from input, convert them to negative values, and push them onto the heap
for i in map(int, input().split()):
    heappush(a, -i)

# Define a lambda function to calculate the division of a number by a power of two
dis = lambda x,y: x // 2**y

# Perform m operations to halve the largest elements in the heap
for _ in range(m):
    heappush(a, -dis(-heappop(a), 1))

# Print the sum of the heap elements, which are negative values, converted back to positive
print(-sum(a))

