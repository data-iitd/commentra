
def getNum():
    global p
    n = 0
    while True:
        c = next(p)
        if c =='':
            break
        n = n * 10 + ord(c) - ord('0')
    return n

def putNum(n):
    global p
    while n > 0:
        n, r = divmod(n, 10)
        p = p + chr(r + ord('0'))

def CountingSort(A, B, k, len):
    C = [0] * k
    for i in range(len):
        C[A[i]] += 1
    for i in range(1, k):
        C[i] += C[i - 1]
    for i in range(len - 1, -1, -1):
        B[C[A[i]] - 1] = A[i]
        C[A[i]] -= 1

A = [0] * MAX_N
B = [0] * MAX_N
str = input()
p = iter(str)
n = getNum()
for i in range(n):
    A[i] = getNum()
CountingSort(A, B, MAX_Ai, n)
for i in range(n):
    putNum(B[i])
    putNum(10)
print(''.join(B))

