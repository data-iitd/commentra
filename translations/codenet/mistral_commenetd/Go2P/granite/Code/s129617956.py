

import math

# Read an integer from standard input and initialize n variable
n = int(input())

# Initialize minimum factor with a large value
minf = 100

# Calculate the square root of n
rt = int(math.sqrt(n))

# Check divisibility for numbers from 1 to the square root of n
for i in range(1, rt+1):
    # Check if n is divisible by i
    if n % i == 0:
        # Calculate the number of digits in the divisor
        b = n // i
        ndigit = 0
        while b > 0:
            b //= 10
            ndigit += 1
        # Update minimum factor if a divisor with fewer digits is found
        minf = min(minf, ndigit)

# Print the result
print(minf)

