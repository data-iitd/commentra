import sys
import math

N = int(input())
A = list(map(int, input().split()))
A.sort(reverse=True)

index = 0
max_diff = float('inf')

for i in range(1, N):
    if max_diff > abs(A[0] - 2 * A[i]):
        max_diff = abs(A[0] - 2 * A[i])
        index = i

print(A[0], A[index])

# <END-OF-CODE>
