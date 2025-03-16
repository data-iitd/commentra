#include <stdio.h>
  
#define PutChar(c) ; *p = (char)(c); ++p;
  
#define MAX_N (2000001)
#define MAX_Ai (10001)
#define STR_SIZE (10000010)
  
def getNum():
    n = 0
    while ((*p >= '0') and (*p <= '9')):
        n = n * 10 + (int)(*p - '0')
        ++p
    ++p
    return n
  
def putNum(n):
    d = 0
    if (n < 10):
        PutChar('0' + n)
        return
    d = n / 10
    if (d): putNum(d)
    PutChar('0' + (n - (d * 10)))
  
def CountingSort(A, B, k, len):
    C = [0] * MAX_Ai
    i = 0
    j = 0
    for j in range(1, len + 1):
        ++C[A[j]]
    for i in range(1, k + 1):
        C[i] += C[i - 1]
    for j in range(len, 0, -1):
        B[C[A[j]]] = A[j]
        --C[A[j]]
  
A = [0] * MAX_N
B = [0] * MAX_N
str = [0] * STR_SIZE
p = str
  
n = getNum()
for i in range(1, n + 1):
    A[i] = getNum()
  
CountingSort(A, B, MAX_Ai, n)
  
p = str
n -= 1
for i in range(1, n + 1):
    putNum(B[i])
    PutChar(' ')
putNum(B[i])
PutChar('\0')
  
print(str)
  
