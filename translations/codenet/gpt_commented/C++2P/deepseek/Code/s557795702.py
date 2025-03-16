INF = 0x3f3f3f3f  # Define a large constant for comparison
MAXN = 2 * 10**5 + 10  # Define the maximum size for the array

def merge(left, mid, right):
    cnt = 0  # Initialize inversion count
    n1 = mid - left  # Size of the left subarray
    n2 = right - mid  # Size of the right subarray
    L = [0] * (n1 + 1)  # Temporary array for left subarray
    R = [0] * (n2 + 1)  # Temporary array for right subarray

    # Copy data to temporary arrays L and R
    for i in range(n1):
        L[i] = a[left + i]
    for i in range(n2):
        R[i] = a[mid + i]

    # Sentinel values to avoid out-of-bounds access
    L[n1] = INF
    R[n2] = INF

    i = j = 0  # Initialize pointers for L and R
    # Merge the two subarrays back into the original array
    for k in range(left, right):
        if L[i] <= R[j]:
            a[k] = L[i]
            i += 1
        else:
            a[k] = R[j]
            j += 1
            cnt += n1 - i  # Count inversions: all remaining elements in L are greater than R[j]
    return cnt  # Return the count of inversions

def mergesort(left, right):
    if left + 1 < right:
        mid = (left + right) // 2  # Find the mid point
        v1 = mergesort(left, mid)  # Sort the left half and count inversions
        v2 = mergesort(mid, right)  # Sort the right half and count inversions
        v3 = merge(left, mid, right)  # Merge both halves and count cross inversions
        return v1 + v2 + v3  # Return total inversion count
    return 0  # Return 0 for a single element (no inversions)

# Read input
n = int(input())
a = list(map(int, input().split()))

# Perform mergesort and get the inversion count
ans = mergesort(0, n)

# Output the result
print(ans)
