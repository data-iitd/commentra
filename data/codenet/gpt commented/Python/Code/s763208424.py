from math import floor  # Import the floor function from the math module
from heapq import heappush, heappop  # Import heappush and heappop from the heapq module for heap operations

# Read two integers n and m from input, where n is the number of elements and m is the number of operations
n, m = map(int, input().split())

# Initialize an empty list to use as a max-heap (using negative values)
a = []

# Read n integers from input and push their negative values into the max-heap
for i in map(int, input().split()):
    heappush(a, -i)

# Define a function to compute the discounted value based on the given formula
dis = lambda x, y: x // 2**y

# Perform m operations on the max-heap
for _ in range(m):
    # Pop the largest element from the heap, apply the discount, and push the discounted value back into the heap
    heappush(a, -dis(-heappop(a), 1))

# Calculate the sum of the elements in the heap (negating back to positive) and print the result
print(-sum(a))
