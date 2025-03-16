
import math

def gcd(a, b):
    if b > a:
        tmp = a
        a = b
        b = tmp
    if b == 0:
        return a
    r = -1
    while r != 0:
        r = a % b
        a = b
        b = r
    return a

def main():
    sc = input()
    N = int(sc)
    A = []
    for i in range(N):
        A.append(int(input()))
    M = []
    L = []
    R = []
    L.append(A[0])
    for i in range(1, N):
        L.append(gcd(L[i - 1], A[i]))
    R.append(A[N - 1])
    for i in range(N - 2, -1, -1):
        R.append(gcd(R[i + 1], A[i]))
    answer = max(L[N - 2], R[1])
    for i in range(1, N - 1):
        answer = max(answer, gcd(L[i - 1], R[i + 1]))
    print(answer)

if __name__ == "__main__":
    main()

