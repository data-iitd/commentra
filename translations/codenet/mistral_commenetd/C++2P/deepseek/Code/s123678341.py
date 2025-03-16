import sys
import heapq

# Read input values for X, Y, Z, and K from standard input
X, Y, Z, K = map(int, input().split())

# Read input values for vectors A, B, and C from standard input
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))

# Sort vectors A, B, and C in descending order
A.sort(reverse=True)
B.sort(reverse=True)
C.sort(reverse=True)

# Create a new vector AB by adding each element of A to each element of B
AB = []
for a in A:
    for b in B:
        heapq.heappush(AB, - (a + b))  # Use a min-heap to simulate a max-heap

# Create a new vector ABC by adding each element of AB to each element of C
ABC = []
for i in range(min(K, len(AB))):
    ab = -heapq.heappop(AB)  # Pop the largest element from AB
    for c in C:
        heapq.heappush(ABC, - (ab + c))  # Use a min-heap to simulate a max-heap

# Print K smallest elements of vector ABC
for i in range(K):
    print(-heapq.heappop(ABC))  # Pop the largest element from ABC

# End-of-code
