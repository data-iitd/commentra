
import sys

def merge(left, mid, right):
    global cnt
    n1 = mid - left
    n2 = right - mid
    L = [0] * (n1 + 1)
    R = [0] * (n2 + 1)
    for i in range(n1):
        L[i] = a[left + i]
    for j in range(n2):
        R[j] = a[mid + j]
    L[n1] = R[n2] = float('inf')
    i, j, k = 0, 0, left
    while i < n1 and j < n2:
        if L[i] <= R[j]:
            a[k] = L[i]
            i += 1
        else:
            a[k] = R[j]
            j += 1
            cnt += n1 - i
        k += 1
    while i < n1:
        a[k] = L[i]
        i += 1
        k += 1
    while j < n2:
        a[k] = R[j]
        j += 1
        k += 1

def mergesort(left, right):
    global cnt
    if left + 1 < right:
        mid = (left + right) // 2
        mergesort(left, mid)
        mergesort(mid, right)
        merge(left, mid, right)

if __name__ == "__main__":
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n = data[0]
    a = data[1:n + 1]
    cnt = 0
    mergesort(0, n)
    print(cnt)

