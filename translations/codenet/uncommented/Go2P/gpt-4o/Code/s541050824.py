import sys
import math

def read_int():
    return int(sys.stdin.readline().strip())

def read_ints():
    return list(map(int, sys.stdin.readline().strip().split()))

def solve():
    N = read_int()
    T, A = [], []
    for _ in range(N):
        t, a = read_ints()
        T.append(t)
        A.append(a)
    
    t, a = T[0], A[0]
    for i in range(1, N):
        r = max(math.ceil(t / T[i]), math.ceil(a / A[i]))
        t, a = T[i] * r, A[i] * r
    
    print(t + a)

if __name__ == "__main__":
    solve()
# <END-OF-CODE>
