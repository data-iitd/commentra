#include <iostream>
using namespace std;

N = 0
S = 0

while N > 0:
    N, M, m, addup, i = map(int, input().split())
    for i in range(N):
        S = int(input())
        addup += S
        if S > M:
            M = S
        if S < m:
            m = S
    print((addup - M - m) / (N - 2))

