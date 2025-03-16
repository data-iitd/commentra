#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

# Partition function used in Quicksort algorithm
def Partition(C, A, p, r):

    # Variables to store temporary values during partition
    i, j = p - 1, p
    x = C[r]
    y = A[r]

    # Rearrange elements in the array
    for j in range(p, r):
        if A[j] <= y:
            i = i + 1
            tmpN = A[j]
            tmpC = C[j]
            A[j] = A[i]
            C[j] = C[i]
            A[i] = tmpN
            C[i] = tmpC

    # Place the pivot element in its correct position
    tmpN = A[i + 1]
    tmpC = C[i + 1]
    A[i + 1] = A[r]
    C[i + 1] = C[r]
    A[r] = tmpN
    C[r] = tmpC

    return i + 1

# Quicksort function to sort the array recursively
def Quicksort(C, A, p, r):

    # Base case: if the subarray has more than one element
    if p < r:
        q = Partition(C, A, p, r)
        Quicksort(C, A, p, q - 1)
        Quicksort(C, A, q + 1, r)

# Merge function to merge two sorted subarrays
def Merge(MC, MN, left, mid, right):

    # Calculate sizes of two subarrays to be merged
    n1 = mid - left + 1
    n2 = right - mid
    LN = [0] * (n1 + 1)
    RN = [0] * (n2 + 1)
    LC = [0] * (n1 + 1)
    RC = [0] * (n2 + 1)

    # Copy data to temp arrays
    i, j, k = 1, 1, left

    for i in range(1, n1 + 1):
        LN[i] = MN[left + i - 1]
        LC[i] = MC[left + i - 1]

    for i in range(1, n2 + 1):
        RN[i] = MN[mid + i]
        RC[i] = MC[mid + i]

    # Sentinel values to avoid checking if any subarray is empty
    LN[n1 + 1] = 1000000000
    RN[n2 + 1] = 1000000000

    # Merge the temp arrays back into arr[left..right]
    for k in range(left, right + 1):
        if LN[i] <= RN[j]:
            MN[k] = LN[i]
            MC[k] = LC[i]
            i += 1
        else:
            MN[k] = RN[j]
            MC[k] = RC[j]
            j += 1

# Merge Sort function to sort the array using recursion
def Merge_Sort(MC, MN, left, right):
    mid = (left + right) // 2

    # Base case: if the subarray has more than one element
    if left < right:
        Merge_Sort(MC, MN, left, mid)
        Merge_Sort(MC, MN, mid + 1, right)
        Merge(MC, MN, left, mid, right)

# Main function to read input, sort data using both algorithms, and check stability
def main():

    # Arrays to store characters and their corresponding numbers
    A = [0] * (MAX + 1)
    C = [0] * (MAX + 1)
    MC = [0] * (MAX + 1)
    MN = [0] * (MAX + 1)

    # Variables to store the number of elements and loop index
    n, i, p = 0, 0, 0
    count = 0

    # Read the number of elements
    n = int(input())

    # Read characters and their corresponding numbers
    for i in range(1, n + 1):
        C[i], A[i] = input().split()
        MC[i] = C[i]
        MN[i] = A[i]

    # Sort the copied array using Merge Sort
    Merge_Sort(MC, MN, 1, n)

    # Sort the original array using Quicksort
    p = 1
    Quicksort(C, A, p, n)

    # Check if the sorting results are stable
    for i in range(1, n + 1):
        if MN[i] == A[i] and MC[i] == C[i]:
            count += 1

    # Print the stability result
    if count == n:
        print("Stable")
    else:
        print("Not stable")

    # Print the sorted characters and their corresponding numbers
    for i in range(1, n + 1):
        print(C[i], A[i])

# Call the main function
main()

