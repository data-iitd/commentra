#include <iostream>
#include <map>
#include <set>
#include <vector>
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;

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
    cin.tie(0)
    ios.sync_with_stdio(False)
    N = int(input())
    T = [int(input()) for _ in range(N)]
    M = int(input())
    P = [int(input()) for _ in range(M)]
    X = [int(input()) for _ in range(M)]
    solve(N, T, M, P, X)
    return 0


if __name__ == '__main__':
    main()

