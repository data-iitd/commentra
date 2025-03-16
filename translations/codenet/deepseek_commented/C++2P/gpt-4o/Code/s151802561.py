# Python translation of the given C++ code

# Step 1: Reading the number of elements (n)
n = int(input())
A = list(map(int, input().split()))

# Step 3: Selection Sort Implementation
sw = 0
for i in range(n):
    mini = i
    # Find the index of the minimum element in the unsorted part of the array
    for j in range(i, n):
        if A[j] < A[mini]:
            mini = j
    # Swap the found minimum element with the first element of the unsorted part
    A[i], A[mini] = A[mini], A[i]
    # Increment the swap counter if a swap was made
    if i != mini:
        sw += 1

# Step 5: Printing the sorted array
print(" ".join(map(str, A)))

# Step 6: Printing the number of swaps
print(sw)

# <END-OF-CODE>
