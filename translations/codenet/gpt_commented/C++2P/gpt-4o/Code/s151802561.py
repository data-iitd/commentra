# Declare an array to hold up to 100 integers and other necessary variables
A = [0] * 100
n = int(input())  # Read the number of elements to be sorted

# Read the elements into the array A
for i in range(n):
    A[i] = int(input())

# Selection sort algorithm to sort the array A
sw = 0  # Initialize swap count
for i in range(n):
    mini = i  # Assume the minimum is the first element of the unsorted part
    # Find the index of the minimum element in the unsorted part
    for j in range(i, n):
        if A[j] < A[mini]:
            mini = j  # Update mini if a smaller element is found
    # Swap the found minimum element with the first element of the unsorted part
    A[i], A[mini] = A[mini], A[i]  # Swap using tuple unpacking

    # Count the number of swaps made
    if i != mini:
        sw += 1

# Print the sorted array
print(" ".join(map(str, A[:n])))  # Print the sorted array elements
# Print the total number of swaps made during sorting
print(sw)

# End of the program
# <END-OF-CODE>
