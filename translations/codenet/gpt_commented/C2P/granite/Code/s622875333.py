
# Python code to solve the problem

# Infinite loop to continuously accept input until a termination condition is met
while True:
    # Read the values of n and r from the user
    n, r = map(int, input().split())
    
    # Check for the termination condition (both n and r are zero)
    if n == 0 and r == 0: break
    
    # Initialize array a with values from n down to 1
    a = [n - i for i in range(n)]
    
    # Process r operations as specified by the user
    for _ in range(r):
        # Copy current state of array a to array b
        b = a[:] # Make a copy of a to b
        
        # Read the values of p and c for the current operation
        p, c = map(int, input().split())

        # Update the first c elements of array a based on the values from array b
        a[:c] = b[p - 1:p - 1 + c] # Move elements from b to a based on p and c
        
        # Shift the remaining elements in array a
        a[c:] = b[c - 1:c - 1 + p - 1] # Continue filling a with the remaining elements from b
    
    # Output the first element of array a after all operations
    print(a[0])

