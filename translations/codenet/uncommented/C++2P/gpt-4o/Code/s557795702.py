import sys
from typing import List

INF = float('inf')
MAXN = 2 * 10**5 + 10
a = [0] * MAXN
L = [0] * (MAXN // 2)
R = [0] * (MAXN // 2)

def merge(left: int, mid: int, right: int) -> int:
    global a, L, R
    cnt = 0
    n1 = mid - left
    n2 = right - mid
    for i in range(n1):
        L[i] = a[left + i]
    for i in range(n2):
        R[i] = a[mid + i]
    L[n1] = R[n2] = INF
    i = j = 0
    for k in range(left, right):
        if L[i] <= R[j]:
            a[k] = L[i]
            i += 1
        else:
            a[k] = R[j]
            j += 1
            cnt += n1 - i
    return cnt

def mergesort(left: int, right: int) -> int:
    if left + 1 < right:
        mid = (left + right) // 2
        v1 = mergesort(left, mid)
        v2 = mergesort(mid, right)
        v3 = merge(left, mid, right)
        return v1 + v2 + v3
    return 0

if __name__ == "__main__":
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    for i in range(n):
        a[i] = int(data[i + 1])
    ans = mergesort(0, n)
    print(ans)

# <END-OF-CODE>
