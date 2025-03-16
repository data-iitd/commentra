MAX = 100000

# Function prototypes for partitioning and sorting
def partition(C, A, p, r):
    i = p - 1
    x = C[r]
    y = A[r]

    for j in range(p, r):
        if A[j] <= y:
            i += 1
            # Swap elements to partition the array
            A[i], A[j] = A[j], A[i]
            C[i], C[j] = C[j], C[i]

    # Place the pivot in the correct position
    A[i + 1], A[r] = A[r], A[i + 1]
    C[i + 1], C[r] = C[r], C[i + 1]

    return i + 1  # Return the pivot index

def quicksort(C, A, p, r):
    # Base case for recursion
    if p < r:
        q = partition(C, A, p, r)  # Partition the array
        quicksort(C, A, p, q - 1)  # Recursively sort the left subarray
        quicksort(C, A, q + 1, r)  # Recursively sort the right subarray

def merge(MC, MN, left, mid, right):
    n1 = mid - left + 1  # Size of left subarray
    n2 = right - mid  # Size of right subarray
    LN = [0] * (n1 + 1)  # Left subarray for integers
    RN = [0] * (n2 + 1)  # Right subarray for integers
    LC = [''] * (n1 + 1)  # Left subarray for characters
    RC = [''] * (n2 + 1)  # Right subarray for characters

    # Copy data to temporary arrays
    for i in range(1, n1 + 1):
        LN[i] = MN[left + i - 1]
        LC[i] = MC[left + i - 1]

    for i in range(1, n2 + 1):
        RN[i] = MN[mid + i]
        RC[i] = MC[mid + i]

    # Sentinel values for merging
    LN.append(1000000000)
    RN.append(1000000000)

    i = 1  # Index for left subarray
    j = 1  # Index for right subarray

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

def merge_sort(MC, MN, left, right):
    # Base case for recursion
    if left < right:
        mid = (left + right) // 2  # Find the midpoint
        merge_sort(MC, MN, left, mid)  # Recursively sort the left half
        merge_sort(MC, MN, mid + 1, right)  # Recursively sort the right half
        merge(MC, MN, left, mid, right)  # Merge the sorted halves

def main():
    # Declare arrays for storing values and characters
    A = [0] * (MAX + 1)  # Array for integer values
    C = [''] * (MAX + 1)  # Array for characters
    MC = [''] * (MAX + 1)  # Array for characters for merge sort
    MN = [0] * (MAX + 1)  # Array for integer values for merge sort

    # Read the number of elements
    n = int(input())

    # Read character and integer pairs into arrays
    for i in range(1, n + 1):
        C[i], A[i] = input().split()
        A[i] = int(A[i])

    # Copy original arrays to auxiliary arrays for merge sort
    for i in range(1, n + 1):
        MC[i] = C[i]
        MN[i] = A[i]

    # Perform merge sort on the auxiliary arrays
    merge_sort(MC, MN, 1, n)

    # Perform quicksort on the original arrays
    p = 1
    quicksort(C, A, p, n)

    # Check if the sorting is stable by comparing original and sorted arrays
    count = sum(1 for i in range(1, n + 1) if MN[i] == A[i] and MC[i] == C[i])

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

# <END-OF-CODE>
