import numpy as np

# Read an integer input from the user which defines the size of the array
n = int(input())

# Initialize an array of zeros with size n to store counts
A = np.zeros(n)

# Initialize variables x, y, z to start the calculations
x, y, z = 1, 1, 1

# Outer loop to iterate over the variable x
while x**2 + y**2 + z**2 + x*y + y*z + z*x <= n:
    # Middle loop to iterate over the variable y
    while x ** 2 + y ** 2 + z ** 2 + x * y + y * z + z * x <= n:
        # Innermost loop to iterate over the variable z
        while x ** 2 + y ** 2 + z ** 2 + x * y + y * z + z * x <= n:
            # Calculate the value based on the current x, y, z
            i = x ** 2 + y ** 2 + z ** 2 + x * y + y * z + z * x
            
            # Increment the count in the array A at the index i - 1
            A[i - 1] += 1
            
            # Increment z for the next iteration
            z += 1
        
        # Reset z to 1 for the next value of y
        z = 1
        
        # Increment y for the next iteration
        y += 1
    
    # Reset y and z to 1 for the next value of x
    y, z = 1, 1
    
    # Increment x for the next iteration
    x += 1

# Print the counts stored in array A for each index from 0 to n-1
for i in range(n):
    print(int(A[i]))
