import sys
from typing import List

INF = float('inf')  # Define a large constant for comparison
MAXN = 2 * 10**5 + 10  # Define the maximum size for the array
a = [0] * MAXN  # Declare the array
L = [0] * (MAXN // 2)  # Temporary array for merging
R = [0] * (MAXN // 2)  # Temporary array for merging

# Function to merge two halves of the array and count inversions
def merge(left: int, mid: int, right: int) -> int:
    cnt = 0  # Initialize inversion count
    n1 = mid - left  # Size of the left subarray
    n2 = right - mid  # Size of the right subarray

    # Copy data to temporary arrays L and R
    for i in range(n1):
        L[i] = a[left + i]
    for i in range(n2):
        R[i] = a[mid + i]

    # Sentinel values to avoid out-of-bounds access
    L[n1] = R[n2] = INF

    i = j = 0  # Initialize pointers for L and R
    # Merge the two subarrays back into the original array
    for k in range(left, right):
        if L[i] <= R[j]:
            a[k] = L[i]  # If L[i] is smaller, take it
            i += 1
        else:
            a[k] = R[j]  # If R[j] is smaller, take it
            j += 1
            cnt += n1 - i  # Count inversions: all remaining elements in L are greater than R[j]
    return cnt  # Return the count of inversions

# Function to perform mergesort and count inversions
def mergesort(left: int, right: int) -> int:
    if left + 1 < right:  # Base case: if the subarray has more than one element
        mid = (left + right) // 2  # Find the mid point
        v1 = mergesort(left, mid)  # Sort the left half and count inversions
        v2 = mergesort(mid, right)  # Sort the right half and count inversions
        v3 = merge(left, mid, right)  # Merge both halves and count cross inversions
        return v1 + v2 + v3  # Return total inversion count
    return 0  # Return 0 for a single element (no inversions)

def main():
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])  # Read the number of elements
    for i in range(n):
        a[i] = int(data[i + 1])  # Read the elements into the array

    ans = mergesort(0, n)  # Perform mergesort and get the inversion count
    print(ans)  # Output the result

if __name__ == "__main__":
    main()

# <END-OF-CODE>
