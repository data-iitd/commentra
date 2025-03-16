# Read two integers N and M from input, where N is the number of elements in the list and M is the number of operations to perform
N, M = map(int, input().split())

# Read a list of integers A from input and unpack it into a list
*A, = map(int, input().split())

# Sort the list A in ascending order
A = sorted(A)

# Perform M operations
while M:
    # Halve the largest element in the list A
    A[-1] //= 2
    # Decrement the number of operations left
    M -= 1
    
    # Initialize index to the second last element
    i = -2
    
    # While there are still operations left and the current element is greater than or equal to the new largest element
    while M and (-N <= i and A[i] >= A[-1]):
        # Halve the current element
        A[i] //= 2
        # Decrement the number of operations left
        M -= 1
        # Move to the next element to the left
        i -= 1
    
    # Sort the list A again after modifications
    A.sort()

# Print the sum of the modified list A
print(sum(A))
