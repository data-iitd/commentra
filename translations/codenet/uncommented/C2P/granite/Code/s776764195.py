
import sys

def getNum():
    n = 0
    while True:
        c = sys.stdin.read(1)
        if not c:
            break
        if c >= '0' and c <= '9':
            n = n * 10 + ord(c) - ord('0')
    return n

def putNum(n):
    if n < 10:
        sys.stdout.write(chr(ord('0') + n))
    else:
        putNum(n // 10)
        sys.stdout.write(chr(ord('0') + n % 10))

def CountingSort(A, B, k, len):
    C = [0] * (k + 1)
    for j in range(1, len + 1):
        C[A[j]] += 1
    for i in range(1, k + 1):
        C[i] += C[i - 1]
    for j in range(len, 0, -1):
        B[C[A[j]]] = A[j]
        C[A[j]] -= 1

MAX_N = 2000001
MAX_Ai = 10001
STR_SIZE = 10000010

A = [0] * MAX_N
B = [0] * MAX_N

str = ""
p = 0

n = getNum()
for i in range(1, n + 1):
    A[i] = getNum()

CountingSort(A, B, MAX_Ai, n)

p = 0
for i in range(1, n):
    putNum(B[i])
    str += " "
putNum(B[i])
str += "\0"

print(str)

