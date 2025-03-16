MAX = 100000

# Partition function used in Quicksort algorithm
def partition(C, A, p, r):
    x = A[r]
    i = p - 1
    for j in range(p, r):
        if A[j] <= x:
            i += 1
            A[i], A[j] = A[j], A[i]
            C[i], C[j] = C[j], C[i]
    A[i + 1], A[r] = A[r], A[i + 1]
    C[i + 1], C[r] = C[r], C[i + 1]
    return i + 1

# Quicksort function to sort the array
def quicksort(C, A, p, r):
    if p < r:
        q = partition(C, A, p, r)
        quicksort(C, A, p, q - 1)
        quicksort(C, A, q + 1, r)

# Merge function used in Merge Sort algorithm
def merge(MC, MN, left, mid, right):
    n1 = mid - left + 1
    n2 = right - mid
    LN = [0] * (n1 + 1)
    RN = [0] * (n2 + 1)
    LC = [0] * (n1 + 1)
    RC = [0] * (n2 + 1)
    
    for i in range(n1):
        LN[i] = MN[left + i]
        LC[i] = MC[left + i]
    
    for i in range(n2):
        RN[i] = MN[mid + i + 1]
        RC[i] = MC[mid + i + 1]
    
    LN[n1] = float('inf')
    RN[n2] = float('inf')
    
    i = 0
    j = 0
    
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
def merge_sort(MC, MN, left, right):
    if left < right:
        mid = (left + right) // 2
        merge_sort(MC, MN, left, mid)
        merge_sort(MC, MN, mid + 1, right)
        merge(MC, MN, left, mid, right)

# Main function to read input, sort data using both algorithms, and check stability
def main():
    # Arrays to store characters and their corresponding numbers
    C = [0] * (MAX + 1)
    A = [0] * (MAX + 1)
    MC = [0] * (MAX + 1)
    MN = [0] * (MAX + 1)

    # Variables to store the number of elements and loop index
    n = int(input())

    # Read characters and their corresponding numbers
    for i in range(1, n + 1):
        C[i], A[i] = input().split()
        A[i] = int(A[i])

    # Copy characters and numbers to another array for Merge Sort
    for i in range(1, n + 1):
        MC[i] = C[i]
        MN[i] = A[i]

    # Sort the copied array using Merge Sort
    merge_sort(MC, MN, 1, n)

    # Sort the original array using Quicksort
    quicksort(C, A, 1, n)

    # Check if the sorting results are stable
    count = 0
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

if __name__ == "__main__":
    main()
