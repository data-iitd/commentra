# <START-OF-CODE>

# Declare an array to hold up to 100 integers and other necessary variables
A = [0] * 100
n = 0
i = 0
j = 0
t = 0
sw = 0
mini = 0

# Read the number of elements to be sorted
n = int(input())

# Read the elements into the array A
for i in range(n):
    A[i] = int(input())

# Selection sort algorithm to sort the array A
for i in range(n):
    mini = i # Assume the minimum is the first element of the unsorted part
    # Find the index of the minimum element in the unsorted part
    for j in range(i, n):
        if (A[j] < A[mini]):
            mini = j # Update mini if a smaller element is found
    # Swap the found minimum element with the first element of the unsorted part
    t = A[i]
    A[i] = A[mini]
    A[mini] = t

    # Count the number of swaps made
    if (i!= mini):
        sw += 1

# Print the sorted array
for i in range(n):
    if (i):
        print(" ", end="") # Print a space before each element except the first
    print(A[i], end="") # Print the current element
print() # Print a newline after the array

# Print the total number of swaps made during sorting
print(sw)

# 