
#include <iostream>
#include <map>
#include <set>
#include <vector>
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;

def solve(N, T, M, P, X):
    REP(i, M) {
        ans = 0;
        REP(j, N) {
            if (j == P[i] - 1) ans += X[i];
            else ans += T[j];
        }
        print(ans);
    }

if __name__ == "__main__":
    N = int(input())
    T = [int(x) for x in input().split()]
    M = int(input())
    P = [int(x) for x in input().split()]
    X = [int(x) for x in input().split()]
    solve(N, T, M, P, X)

