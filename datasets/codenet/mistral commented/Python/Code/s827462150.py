

# Import NumPy library
import numpy as np

# Get user input for the number of elements in the array A
n = int(input())

# Initialize A as a NumPy array of zeros with the given size
A = np.zeros(n)



# Initialize variables x, y, and z with initial values of 1
x, y, z = 1, 1, 1



# Main loop that runs while the sum of the squares and pairwise products of x, y, and z is less than or equal to n
while x**2 + y**2 + z**2 + x*y + y*z + z*x <= n:



# Inner loop that runs while the sum of the squares and pairwise products of x, y, and z is less than or equal to n
# Calculate the index i based on the current values of x, y, and z
i = x**2 + y**2 + z**2 + x*y + y*z + z*x

# Increment the value at index i in array A by 1
A[i-1] += 1

# Increment z by 1
z += 1



# If z is not equal to 1, set it back to 1 and increment y by 1
if z != 1:
    z = 1
    y += 1



# Increment x by 1 and reset y and z to 1
x += 1
y, z = 1, 1



# Loop that prints the contents of array A
for i in range(n):
    print(int(A[i]))
