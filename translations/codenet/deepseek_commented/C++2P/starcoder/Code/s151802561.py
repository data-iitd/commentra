
# Step 1: Reading the number of elements (n)
n = int(input())
A = [int(x) for x in input().split()]

# Step 2: Reading the elements of the array
# Step 3: Selection Sort Implementation
sw = 0
for i in range(n):
    mini = i
    # Find the index of the minimum element in the unsorted part of the array
    for j in range(i, n):
        if A[j] < A[mini]: mini = j
    # Swap the found minimum element with the first element of the unsorted part
    t = A[i]
    A[i] = A[mini]
    A[mini] = t
    # Increment the swap counter if a swap was made
    if i!= mini: sw += 1

# Step 4: Counting the number of swaps
# Step 5: Printing the sorted array
print(*A)

# Step 6: Printing the number of swaps
print(sw)

# 