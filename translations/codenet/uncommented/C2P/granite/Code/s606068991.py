
def white(n, A):
    for i in range(n-1):
        print(A[i], end=" ")
    print(A[i])

def insertionsort(n, A):
    for i in range(n):
        for j in range(i):
            if A[i] < A[j]:
                A[i], A[j] = A[j], A[i]
        white(n, A)

n = int(input())
A = [int(input()) for _ in range(n)]
insertionsort(n, A)

