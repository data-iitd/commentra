
import sys

def solve():
    N = int(sys.stdin.readline())
    T, A = [], []
    for i in range(N):
        T.append(int(sys.stdin.readline()))
        A.append(int(sys.stdin.readline()))
    t, a = T[0], A[0]
    for i in range(1, N):
        r = max(t // T[i], a // A[i])
        t, a = T[i] * r, A[i] * r
    print(t + a)

solve()

