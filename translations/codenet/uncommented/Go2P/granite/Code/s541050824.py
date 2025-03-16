
import sys
import math

def main():
    solve()
    sys.stdout.flush()

def solve():
    N = int(input())
    T, A = [], []
    for i in range(N):
        t, a = map(int, input().split())
        T.append(t)
        A.append(a)
    t, a = T[0], A[0]
    for i in range(1, N):
        r = max(math.ceil(t / T[i]), math.ceil(a / A[i]))
        t, a = T[i] * r, A[i] * r
    print(t + a)

main()

