
import sys

N, L, R, QL, QR = map(int, input().split())
W = list(map(int, input().split()))

sum_W = [0] * (N + 1)
for n in range(N):
    sum_W[n + 1] = sum_W[n] + W[n]

min_cost = sys.maxsize
for firstR in range(N + 1):
    lCount = firstR
    rCount = N - lCount
    cand = sum_W[lCount] * L + (sum_W[N] - sum_W[lCount]) * R
    llCount = max(0, lCount - rCount - 1)
    rrCount = max(0, rCount - lCount - 1)
    cand += llCount * QL
    cand += rrCount * QR
    min_cost = min(cand, min_cost)

print(min_cost)

Translate the above Python code to C++ and end with comment "