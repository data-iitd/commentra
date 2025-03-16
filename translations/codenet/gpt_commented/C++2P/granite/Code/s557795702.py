
import sys

def merge(left, mid, right):
    global cnt
    i, j, k = 0, 0, left
    L = a[left:mid] + [float('inf')]
    R = a[mid:right] + [float('inf')]
    for k in range(left, right):
        if L[i] <= R[j]:
            a[k] = L[i]
            i += 1
        else:
            a[k] = R[j]
            j += 1
            cnt += len(L) - i
    return cnt

def mergesort(left, right):
    if left + 1 < right:
        mid = (left + right) // 2
        v1 = mergesort(left, mid)
        v2 = mergesort(mid, right)
        v3 = merge(left, mid, right)
        return v1 + v2 + v3
    return 0

n = int(input())
a = list(map(int, input().split()))
cnt = 0
mergesort(0, n)
print(cnt)

