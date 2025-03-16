
import sys

def solve(N, T, M, P, X):
    for i in range(M):
        ans = 0
        for j in range(N):
            if j == P[i] - 1:
                ans += X[i]
            else:
                ans += T[j]
        print(ans)

def main():
    sys.setrecursionlimit(10**6)
    input = sys.stdin.readline
    N = int(input())
    T = list(map(int, input().split()))
    M = int(input())
    P = [0] * M
    X = [0] * M
    for i in range(M):
        P[i], X[i] = map(int, input().split())
    solve(N, T, M, P, X)

if __name__ == '__main__':
    main()

