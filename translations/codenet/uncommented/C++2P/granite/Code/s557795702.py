
import sys

def merge(L, R):
    n1 = len(L)
    n2 = len(R)
    i = j = 0
    cnt = 0
    while i < n1 and j < n2:
        if L[i] <= R[j]:
            i += 1
        else:
            cnt += n1 - i
            j += 1
    return cnt

def mergesort(A):
    if len(A) <= 1:
        return 0
    mid = len(A) // 2
    L = A[:mid]
    R = A[mid:]
    return mergesort(L) + mergesort(R) + merge(L, R)

n = int(input())
A = list(map(int, input().split()))
ans = mergesort(A)
print(ans)
