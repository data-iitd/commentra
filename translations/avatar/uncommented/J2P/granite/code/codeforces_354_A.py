
import sys

def main():
    N, L, R, QL, QR = map(int, sys.stdin.readline().split())
    W = list(map(int, sys.stdin.readline().split()))
    sum_W = [0] * (N + 1)
    for n in range(N):
        sum_W[n + 1] = sum_W[n] + W[n]
    min_cost = float('inf')
    for firstR in range(N + 1):
        lCount = firstR
        rCount = N - lCount
        cost = sum_W[lCount] * L + (sum_W[N] - sum_W[lCount]) * R
        llCount = max(0, lCount - rCount - 1)
        rrCount = max(0, rCount - lCount - 1)
        cost += llCount * QL
        cost += rrCount * QR
        min_cost = min(cost, min_cost)
    print(min_cost)

if __name__ == "__main__":
    main()

