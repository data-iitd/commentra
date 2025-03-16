#include <stdio.h>

#define MAX_N (2000001) // Maximum number of elements
#define MAX_Ai (10001)  // Maximum value of elements
#define STR_SIZE (10000010) // Size of the output string

#define PutChar(c) ; *p = (char)(c); ++p;

#define getNum() int(input()[0])
#define putNum(n) print(n, end=" ")

def CountingSort(A, B, k, len):
    C = [0] * (MAX_Ai + 1)
    for j in range(1, len + 1):
        C[A[j]] += 1
    for i in range(1, k + 1):
        C[i] += C[i - 1]
    for j in range(len, 0, -1):
        B[C[A[j]]] = A[j]
        C[A[j]] -= 1

n = getNum()
A = [0] * (MAX_N + 1)
B = [0] * (MAX_N + 1)
for i in range(1, n + 1):
    A[i] = getNum()
CountingSort(A, B, MAX_Ai, n)
for i in range(1, n + 1):
    putNum(B[i])
print()

