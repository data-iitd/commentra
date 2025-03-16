
import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))

answer = 0
# Calculate the maximum absolute difference between any two elements in the array
for i in range(N - 1):
    for j in range(i + 1, N):
        diff = abs(A[i] - A[j])
        answer = max(answer, diff)
# Output the result
print(answer)
