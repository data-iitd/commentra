import sys

# Merge function: Merges two sorted halves of the array a from index left to right.
def merge(left, mid, right):
    global cnt
    n1 = mid - left
    n2 = right - mid
    L = [0] * (n1 + 1)
    R = [0] * (n2 + 1)
    for i in range(n1):
        L[i] = a[left + i]
    for i in range(n2):
        R[i] = a[mid + i]
    L[n1] = float('inf')
    R[n2] = float('inf')
    i = j = 0
    for k in range(left, right):
        if L[i] <= R[j]:
            a[k] = L[i]
            i += 1
        else:
            a[k] = R[j]
            j += 1
            cnt += n1 - i

# Merge sort function: Recursively divides the array into halves and sorts them using merge sort.
def mergesort(left, right):
    if left + 1 < right:
        mid = (left + right) // 2
        mergesort(left, mid)
        mergesort(mid, right)
        merge(left, mid, right)

# Main function: Synchronizes the input/output streams, reads the number of elements and the elements themselves, calls the merge sort function to sort the array and compute the number of inversions, and prints the number of inversions.
if __name__ == "__main__":
    input = sys.stdin.readline
    n = int(input())
    a = list(map(int, input().split()))
    cnt = 0
    mergesort(0, n)
    print(cnt)
