import numpy as np
n = int(input())
A = np.zeros(n)

# Initialize variables x, y, and z to 1
x, y, z = 1, 1, 1

# Outer while loop: Iterate over x values
while x**2 + y**2 + z**2 + x*y + y*z + z*x <= n:
    # Second while loop: Iterate over y values
    while x**2 + y**2 + z**2 + x*y + y*z + z*x <= n:
        # Innermost while loop: Iterate over z values
        while x**2 + y**2 + z**2 + x*y + y*z + z*x <= n:
            # Calculate the sum of squares and products
            i = x**2 + y**2 + z**2 + x*y + y*z + z*x
            # Increment the corresponding index in array A
            A[i - 1] += 1
            # Increment z
            z += 1
        # Reset z to 1 and increment y
        z = 1
        y += 1
    # Reset y and z to 1 and increment x
    y, z = 1, 1
    x += 1

# Print the elements of array A
for i in range(n):
    print(int(A[i]))
