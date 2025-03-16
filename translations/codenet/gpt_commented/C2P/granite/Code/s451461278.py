
import sys

# Function prototypes for partitioning and sorting
def partition(C, A, p, r):
    x = C[r]
    i = p - 1
    for j in range(p, r):
        if A[j] <= x:
            i += 1
            A[i], A[j] = A[j], A[i]
            C[i], C[j] = C[j], C[i]
    A[i + 1], A[r] = A[r], A[i + 1]
    C[i + 1], C[r] = C[r], C[i + 1]
    return i + 1

def quicksort(C, A, p, r):
    if p < r:
        q = partition(C, A, p, r)
        quicksort(C, A, p, q - 1)
        quicksort(C, A, q + 1, r)

def merge(MC, MN, left, mid, right):
    n1 = mid - left + 1
    n2 = right - mid
    LC = MC[left:left + n1]
    RC = MC[mid + 1:right + 1]
    LN = MN[left:left + n1]
    RN = MN[mid + 1:right + 1]
    LC.append(sys.maxsize)
    RC.append(sys.maxsize)
    LN.append(sys.maxsize)
    RN.append(sys.maxsize)
    i = j = k = 0
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
    while i < n1:
        MN[k] = LN[i]
        MC[k] = LC[i]
        i += 1
        k += 1
    while j < n2:
        MN[k] = RN[j]
        MC[k] = RC[j]
        j += 1
        k += 1

def merge_sort(MC, MN, left, right):
    if left < right:
        mid = (left + right) // 2
        merge_sort(MC, MN, left, mid)
        merge_sort(MC, MN, mid + 1, right)
        merge(MC, MN, left, mid, right)

# Read the number of elements
n = int(input())

# Read character and integer pairs into arrays
C = []
A = []
for _ in range(n):
    c, a = input().split()
    C.append(c)
    A.append(int(a))

# Copy original arrays to auxiliary arrays for merge sort
MC = C.copy()
MN = A.copy()

# Perform merge sort on the auxiliary arrays
merge_sort(MC, MN, 0, n - 1)

# Perform quicksort on the original arrays
quicksort(C, A, 0, n - 1)

# Check if the sorting is stable by comparing original and sorted arrays
count = 0
for i in range(n):
    if MN[i] == A[i] and MC[i] == C[i]:
        count += 1

# Output stability result
if count == n:
    print("Stable")
else:
    print("Not stable")

# Print the sorted character and integer pairs
for i in range(n):
    print(C[i], A[i])

