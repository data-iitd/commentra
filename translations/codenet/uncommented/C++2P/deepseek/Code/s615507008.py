def solve(N, T, M, P, X):
    for i in range(M):
        ans = 0
        for j in range(N):
            if j == P[i] - 1:
                ans += X[i]
            else:
                ans += T[j]
        print(ans)


if __name__ == "__main__":
    import sys
    input = sys.stdin.readline
    N = int(input())
    T = list(map(int, input().split()))
    M = int(input())
    P = []
    X = []
    for _ in range(M):
        p, x = map(int, input().split())
        P.append(p)
        X.append(x)
    solve(N, T, M, P, X)
