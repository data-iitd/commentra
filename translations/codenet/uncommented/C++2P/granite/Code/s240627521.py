
import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
A.sort(reverse=True)
max_diff = float('inf')
index = 1
for i in range(1, N):
    diff = abs(A[0] - 2 * A[i])
    if diff < max_diff:
        max_diff = diff
        index = i
print(A[0], A[index])
