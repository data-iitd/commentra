import sys

MAX_N = 2000001
MAX_Ai = 10001
STR_SIZE = 10000010

def getNum():
    n = 0
    while str[p].isdigit():
        n = n * 10 + int(str[p])
        p += 1
    p += 1
    return n

def putNum(n):
    if n < 10:
        PutChar(chr(ord('0') + n))
        return
    d = n // 10
    if d:
        putNum(d)
    PutChar(chr(ord('0') + (n - (d * 10))))

def CountingSort(A, B, k, len):
    C = [0] * (k + 1)
    for j in range(1, len + 1):
        C[A[j]] += 1
    for i in range(1, k + 1):
        C[i] += C[i - 1]
    for j in range(len, 0, -1):
        B[C[A[j]]] = A[j]
        C[A[j]] -= 1

# Read input
input_str = sys.stdin.read(STR_SIZE)
str = list(input_str)
p = 0

# Main logic
n = getNum()
A = [0] * (n + 1)
for i in range(1, n + 1):
    A[i] = getNum()

CountingSort(A, B, MAX_Ai, n)

p = 0
result = []
for i in range(1, n):
    putNum(B[i])
    result.append(' ')
putNum(B[n])

# Output the result
output_str = ''.join(result) + str[p:]
print(output_str)
