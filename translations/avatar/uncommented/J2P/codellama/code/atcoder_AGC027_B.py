import sys

def main():
    sc = sys.stdin
    N = int(sc.readline())
    X = int(sc.readline())
    x = [int(sc.readline()) for i in range(N)]
    xsum = [0] * (N + 1)
    for i in range(N):
        xsum[i + 1] = xsum[i] + x[i]
    ans = X * N + 5 * xsum[N]
    for i in range(1, N):
        cost = X * i + 5 * (xsum[N] - xsum[N - i])
        for j in range(5, N - i + 1, 2):
            if cost > ans:
                break
            cost += j * (xsum[N - i - j] - xsum[max(N - i - j - i, 0)])
        ans = min(ans, cost)
    print(ans + N * X)


if __name__ == "__main__":
    main()

