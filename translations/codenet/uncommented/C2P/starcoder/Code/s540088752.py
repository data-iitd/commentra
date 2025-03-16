
#include <stdio.h>

def main():
    N = int(raw_input())
    A = [0] * (N + 1)
    B = [0] * N
    for i in range(N):
        A[i] = int(raw_input())
    for i in range(N):
        B[i] = int(raw_input())
    ans = 0
    for i in range(N):
        if A[i] >= B[i]:
            ans = ans + B[i]
            A[i] = A[i] - B[i]
            B[i] = 0
        else:
            ans = ans + A[i]
            B[i] = B[i] - A[i]
            A[i] = 0
        if A[i + 1] >= B[i]:
            ans = ans + B[i]
            A[i + 1] = A[i + 1] - B[i]
            B[i] = 0
        else:
            ans = ans + A[i + 1]
            B[i] = B[i] - A[i + 1]
            A[i + 1] = 0
    print ans

main()

