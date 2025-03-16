import sys

MAX_N = 2000001
MAX_Ai = 10001
STR_SIZE = 10000010

def get_num():
    global p
    n = 0
    while p < len(str) and '0' <= str[p] <= '9':
        n = n * 10 + int(str[p]) - int('0')
        p += 1
    p += 1  # Skip the space or newline
    return n

def put_num(n):
    global p
    if n < 10:
        str_result.append(chr(ord('0') + n))
        return
    d = n // 10
    if d:
        put_num(d)
    str_result.append(chr(ord('0') + (n - (d * 10))))

def counting_sort(A, B, k, length):
    C = [0] * MAX_Ai
    for j in range(1, length + 1):
        C[A[j]] += 1
    for i in range(1, k + 1):
        C[i] += C[i - 1]
    for j in range(length, 0, -1):
        B[C[A[j]]] = A[j]
        C[A[j]] -= 1

# Read input
str_result = []
str = sys.stdin.read()
p = 0

n = get_num()
A = [0] * MAX_N
B = [0] * MAX_N

for i in range(1, n + 1):
    A[i] = get_num()

counting_sort(A, B, MAX_Ai, n)

for i in range(1, n):
    put_num(B[i])
    str_result.append(' ')
put_num(B[n])
str_result.append('\0')

# Print the result
print(''.join(str_result).replace('\0', ''))

# End of code
# <END-OF-CODE>
