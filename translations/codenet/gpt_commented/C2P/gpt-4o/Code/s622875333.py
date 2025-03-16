# Declare global variables
n, r, i, j, p, c = 0, 0, 0, 0, 0, 0
a = [0] * 100
b = [0] * 100

while True:
    # Read the values of n and r from the user
    n, r = map(int, input().split())
    
    # Check for the termination condition (both n and r are zero)
    if n == 0 and r == 0:
        break
    
    # Initialize array a with values from n down to 1
    for i in range(n):
        a[i] = n - i  # Fill array a with decreasing values starting from n
    
    # Process r operations as specified by the user
    for i in range(r):
        # Copy current state of array a to array b
        for j in range(n):
            b[j] = a[j]  # Save the current configuration of a into b
        
        # Read the values of p and c for the current operation
        p, c = map(int, input().split())

        # Update the first c elements of array a based on the values from array b
        for j in range(c):
            a[j] = b[p - 1 + j]  # Move elements from b to a based on p and c
        
        # Shift the remaining elements in array a
        for j in range(c, c + p - 1):
            a[j] = b[j - c]  # Continue filling a with the remaining elements from b
    
    # Output the first element of array a after all operations
    print(a[0])

# <END-OF-CODE>
