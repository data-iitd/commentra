
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

def mergesort(a):
    if len(a) > 1:
        mid = len(a) // 2
        L = a[:mid]
        R = a[mid:]
        v1 = mergesort(L)
        v2 = mergesort(R)
        v3 = merge(L, R)
        return v1 + v2 + v3
    return 0

n = int(input())
a = list(map(int, input().split()))
ans = mergesort(a)
print(ans)

