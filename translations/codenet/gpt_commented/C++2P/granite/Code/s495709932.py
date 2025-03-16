
import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))

answer = 0
for i in range(N - 1):
    for j in range(i + 1, N):
        diff = abs(A[i] - A[j])
        answer = max(answer, diff)

print(answer)

