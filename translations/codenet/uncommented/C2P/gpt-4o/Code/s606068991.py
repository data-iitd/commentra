def white(n, A):
    for i in range(n - 1):
        print(A[i], end=' ')
    print(A[n - 1])

def insertionsort(n, A):
    for i in range(n):
        for j in range(i):
            if A[i] < A[j]:
                A[i], A[j] = A[j], A[i]
        white(n, A)

if __name__ == "__main__":
    n = int(input())
    A = list(map(int, input().split()))
    insertionsort(n, A)

# <END-OF-CODE>
