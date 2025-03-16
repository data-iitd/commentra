N, M = map(int, input().split())  # Read the number of elements N and the number of operations M
*A, = map(int, input().split())  # Read N integers and store them in the list A
A = sorted(A)  # Sort the list A in ascending order

# Main loop to perform M operations
while M:
    A[-1] //= 2  # Halve the largest element in A
    M -= 1  # Decrement the number of operations left
    i = -2  # Initialize the index for the second largest element
    # Nested loop to halve the second largest element repeatedly
    while M and (-N <= i and A[i] >= A[-1]):
        A[i] //= 2  # Halve the second largest element
        M -= 1  # Decrement the number of operations left
        i -= 1  # Move to the next smaller element
    A.sort()  # Sort the list A again after each modification

print(sum(A))  # Print the sum of the elements in A
