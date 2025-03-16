import sys

INF = float('inf')  # Define a constant INF for initializing arrays.
MAXN = 2 * 10**5 + 10  # Define a constant MAXN for the maximum number of elements in the array.
a = [0] * MAXN  # Declare an array a to store the elements.
L = [0] * (MAXN // 2)  # Array to temporarily store the left half during merge sort.
R = [0] * (MAXN // 2)  # Array to temporarily store the right half during merge sort.

# Merge function: Merges two sorted halves of the array a from index left to right.
def merge(left, mid, right):
    global L, R
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

# Merge sort function: Recursively divides the array into halves and sorts them using merge sort.
def mergesort(left, right):
    if left + 1 < right:
        mid = (left + right) // 2
        v1 = mergesort(left, mid)
        v2 = mergesort(mid, right)
        v3 = merge(left, mid, right)
        return v1 + v2 + v3
    return 0

# Main function: Reads the number of elements and the elements themselves, calls the merge sort function to sort the array and compute the number of inversions, and prints the number of inversions.
if __name__ == "__main__":
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    for i in range(n):
        a[i] = int(data[i + 1])
    ans = mergesort(0, n)
    print(ans)

# <END-OF-CODE>
