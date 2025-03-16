import sys

def func(A):
    a = A[:]
    min = 0
    for i in range(len(a)):
        if a[i] == 0:
            a.remove(i)
            i -= 1
        else:
            if min!= 0:
                a[i] = a[i] % min
                if a[i] == 1:
                    print(1)
                    sys.exit(0)
            else:
                min = a[i]
    a.sort()
    return a

n = int(input())
A = []
for i in range(n):
    A.append(int(input()))

while True:
    A = func(A)
    if len(A) == 1:
        print(A[0])
        sys.exit(0)

