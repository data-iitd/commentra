import sys

MAX_N = 2000001
MAX_Ai = 10001
STR_SIZE = 10000010

def get_num():
    n = 0
    while str[p].isdigit():
        n = n * 10 + int(str[p])
        p += 1
    p += 1  # Move past the space or newline
    return n

def put_num(n):
    if n < 10:
        PutChar(chr(ord('0') + n))
        return
    d = n // 10
    if d:
        put_num(d)
    PutChar(chr(ord('0') + (n - (d * 10))))

def counting_sort(A, B, k, len):
    C = [0] * (k + 1)
    for j in range(1, len + 1):
        C[A[j]] += 1
    for i in range(1, k + 1):
        C[i] += C[i - 1]
    for j in range(len, 0, -1):
        B[C[A[j]]] = A[j]
        C[A[j]] -= 1

# Read input into the buffer
str = sys.stdin.read(STR_SIZE)
p = 0

# Get the number of elements
n = get_num()

# Read each element into the array A
A = [0] * (n + 1)
for i in range(1, n + 1):
    A[i] = get_num()

# Sort the array A using Counting Sort
B = [0] * (n + 1)
counting_sort(A, B, MAX_Ai, n)

# Reset the pointer to the start of the buffer
p = 0

# Decrement n to exclude the last element from the output
n -= 1

# Write each sorted element
for i in range(1, n + 1):
    put_num(B[i])
    PutChar(' ')
put_num(B[n + 1])
PutChar('\0')

# Output the sorted string
sys.stdout.write(str)
