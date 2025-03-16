import sys
import heapq

# Step 1: Reading Inputs
X, Y, Z, K = map(int, input().split())

# Step 2: Vector Initialization and Input
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))

# Step 3: Sorting
A.sort(reverse=True)
B.sort(reverse=True)
C.sort(reverse=True)

# Step 4: Combining A and B
AB = []
for a in A:
    for b in B:
        heapq.heappush(AB, -(a + b))

# Step 5: Sorting AB
AB = [-x for x in AB]
AB.sort(reverse=True)

# Step 6: Combining AB and C
ABC = []
for i in range(min(K, len(AB))):
    for j in range(Z):
        heapq.heappush(ABC, -(AB[i] + C[j]))

# Step 7: Sorting ABC
ABC = [-x for x in ABC]
ABC.sort(reverse=True)

# Step 8: Output
for i in range(K):
    print(ABC[i])

