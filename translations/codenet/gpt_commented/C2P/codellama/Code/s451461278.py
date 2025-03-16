#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

# Function prototypes for partitioning and sorting
def Partition(C, A, p, r):
    i, j = p - 1, p
    x = C[r]
    y = A[r]

    # Rearrange elements based on the pivot
    for j in range(p, r):
        if A[j] <= y:
            i = i + 1
            # Swap elements to partition the array
            tmpN = A[j]
            tmpC = C[j]
            A[j] = A[i]
            C[j] = C[i]
            A[i] = tmpN
            C[i] = tmpC

    # Place the pivot in the correct position
    tmpN = A[i + 1]
    tmpC = C[i + 1]
    A[i + 1] = A[r]
    C[i + 1] = C[r]
    A[r] = tmpN
    C[r] = tmpC

    return i + 1 # Return the pivot index

# Function to perform quicksort
def Quicksort(C, A, p, r):
    # Base case for recursion
    if p < r:
        q = Partition(C, A, p, r) # Partition the array
        Quicksort(C, A, p, q - 1) # Recursively sort the left subarray
        Quicksort(C, A, q + 1, r) # Recursively sort the right subarray

# Function to merge two sorted subarrays
def Merge(MC, MN, left, mid, right):
    n1 = mid - left + 1 # Size of left subarray
    n2 = right - mid # Size of right subarray
    LN = [0] * (n1 + 1) # Left subarray for integers
    RN = [0] * (n2 + 1) # Right subarray for integers
    LC = [0] * (n1 + 1) # Left subarray for characters
    RC = [0] * (n2 + 1) # Right subarray for characters

    i, j, k = 1, 1, left

    # Copy data to temporary arrays
    for i in range(1, n1 + 1):
        LN[i] = MN[left + i - 1]
        LC[i] = MC[left + i - 1]

    for i in range(1, n2 + 1):
        RN[i] = MN[mid + i]
        RC[i] = MC[mid + i]

    # Sentinel values for merging
    LN[n1 + 1] = 1000000000
    RN[n2 + 1] = 1000000000

    # Merge the temporary arrays back into the original arrays
    for k in range(left, right + 1):
        if LN[i] <= RN[j]:
            MN[k] = LN[i]
            MC[k] = LC[i]
            i += 1
        else:
            MN[k] = RN[j]
            MC[k] = RC[j]
            j += 1

# Function to perform merge sort
def Merge_Sort(MC, MN, left, right):
    mid = (left + right) // 2 # Find the midpoint
    Merge_Sort(MC, MN, left, mid) # Recursively sort the left half
    Merge_Sort(MC, MN, mid + 1, right) # Recursively sort the right half
    Merge(MC, MN, left, mid, right) # Merge the sorted halves

# Main function
def main():
    # Declare arrays for storing values and characters
    A = [0] * (MAX + 1) # Array for integer values
    C = [0] * (MAX + 1) # Array for characters
    MC = [0] * (MAX + 1) # Array for characters for merge sort
    MN = [0] * (MAX + 1) # Array for integer values for merge sort

    n, i, p = 0, 0, 0
    count = 0 # Counter for stable sorting check

    # Read the number of elements
    n = int(input())

    # Read character and integer pairs into arrays
    for i in range(1, n + 1):
        C[i], A[i] = input().split()
        MC[i] = C[i]
        MN[i] = A[i]

    # Perform merge sort on the auxiliary arrays
    Merge_Sort(MC, MN, 1, n)

    # Perform quicksort on the original arrays
    p = 1
    Quicksort(C, A, p, n)

    # Check if the sorting is stable by comparing original and sorted arrays
    for i in range(1, n + 1):
        if MN[i] == A[i] and MC[i] == C[i]:
            count += 1

    # Output stability result
    if count == n:
        print("Stable")
    else:
        print("Not stable")

    # Print the sorted character and integer pairs
    for i in range(1, n + 1):
        print(C[i], A[i])

if __name__ == "__main__":
    main()

