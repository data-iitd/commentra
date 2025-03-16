
import sys

def getNum():
    n = 0
    while True:
        c = sys.stdin.read(1)
        if c.isdigit():
            n = n * 10 + int(c)
        else:
            sys.stdin.read(1)
            return n

def putNum(n):
    if n < 10:
        sys.stdout.write(str(n))
    else:
        putNum(n // 10)
        sys.stdout.write(str(n % 10))

def CountingSort(A, B, k, len):
    C = [0] * (k + 1)
    for j in range(1, len + 1):
        C[A[j]] += 1
    for i in range(1, k + 1):
        C[i] += C[i - 1]
    for j in range(len, 0, -1):
        B[C[A[j]]] = A[j]
        C[A[j]] -= 1

if __name__ == "__main__":
    n = getNum()
    A = [0] * (n + 1)
    B = [0] * (n + 1)
    for i in range(1, n + 1):
        A[i] = getNum()
    CountingSort(A, B, 10000, n)
    p = 1
    for i in range(1, n):
        putNum(B[i])
        sys.stdout.write(' ')
    putNum(B[n])
    sys.stdout.write('\n')