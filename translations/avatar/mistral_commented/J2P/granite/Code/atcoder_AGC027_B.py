

import sys

def main():
    N, X = map(int, input().split())
    x = list(map(int, input().split()))
    xsum = [0] * (N + 1)
    for i in range(N):
        xsum[i + 1] = xsum[i] + x[i]
    ans = X * N + 5 * xsum[N]
    for i in range(1, N):
        cost = X * i + 5 * (xsum[N] - xsum[N - i])
        for j in range(5, N - i + 1, 2):
            if cost > ans:
                break
            cost += j * (xsum[N - i] - xsum[max(0, N - i - j)])
        ans = min(ans, cost)
    print(ans + N * X)

if __name__ == "__main__":
    main()

These comments should provide a clear understanding of what each part of the code does. Let me know if you need any further clarification.