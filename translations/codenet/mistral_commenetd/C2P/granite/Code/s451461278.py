
import sys

def partition(C, A, p, r):
    x = C[r]
    y = A[r]
    i = p - 1
    for j in range(p, r):
        if A[j] <= y:
            i += 1
            A[i], A[j] = A[j], A[i]
            C[i], C[j] = C[j], C[i]
    A[i+1], A[r] = A[r], A[i+1]
    C[i+1], C[r] = C[r], C[i+1]
    return i + 1

def quicksort(C, A, p, r):
    if p < r:
        q = partition(C, A, p, r)
        quicksort(C, A, p, q-1)
        quicksort(C, A, q+1, r)

def merge(MC, MN, left, mid, right):
    n1 = mid - left + 1
    n2 = right - mid
    LC = MC[left:left+n1]
    RC = MC[mid+1:right+1]
    LN = MN[left:left+n1]
    RN = MN[mid+1:right+1]
    LC.append(sys.maxsize)
    RC.append(sys.maxsize)
    LN.append(sys.maxsize)
    RN.append(sys.maxsize)
    i = j = k = left
    while i < n1 and j < n2:
        if LN[i] <= RN[j]:
            MN[k] = LN[i]
            MC[k] = LC[i]
            i += 1
        else:
            MN[k] = RN[j]
            MC[k] = RC[j]
            j += 1
        k += 1

def merge_sort(MC, MN, left, right):
    if left < right:
        mid = (left + right) // 2
        merge_sort(MC, MN, left, mid)
        merge_sort(MC, MN, mid+1, right)
        merge(MC, MN, left, mid, right)

n = int(input())
A = [0] * (n + 1)
C = [""] * (n + 1)
MC = [""] * (n + 1)
MN = [0] * (n + 1)

for i in range(1, n + 1):
    C[i], A[i] = input().split()
    MC[i] = C[i]
    MN[i] = int(A[i])

merge_sort(MC, MN, 1, n)
quicksort(C, A, 1, n)

count = 0
for i in range(1, n + 1):
    if MN[i] == A[i] and MC[i] == C[i]:
        count += 1

if count == n:
    print("Stable")
else:
    print("Not stable")

for i in range(1, n + 1):
    print(C[i], A[i])

print("