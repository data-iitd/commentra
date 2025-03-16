INF = 0x3f3f3f3f
MAXN = 2 * 10**5 + 10

def merge(left, mid, right):
    cnt = 0
    n1 = mid - left
    n2 = right - mid
    L = [0] * (n1 + 1)
    R = [0] * (n2 + 1)

    for i in range(n1):
        L[i] = a[left + i]

    for i in range(n2):
        R[i] = a[mid + i]

    L[n1] = INF
    R[n2] = INF

    i, j = 0, 0
    for k in range(left, right):
        if L[i] <= R[j]:
            a[k] = L[i]
            i += 1
        else:
            a[k] = R[j]
            j += 1
            cnt += n1 - i

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
ans = mergesort(0, n)
print(ans)
