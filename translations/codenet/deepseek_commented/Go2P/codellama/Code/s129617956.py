
import math

# Read an integer n from the standard input
n = int(input())

# Calculate the square root of n and store it in rt
rt = int(math.sqrt(n))

# Initialize minf to 100, which will hold the minimum number of digits
minf = 100

# Iterate from 1 to rt + 1 to find divisors of n
for i in range(1, rt+1):
    if n % i == 0:
        # If i is a divisor of n, calculate the quotient b
        b = n // i
        
        # Count the number of digits in b
        ndigit = 0
        while b > 0:
            b //= 10
            ndigit += 1
        
        # Update minf with the minimum number of digits found
        minf = min(minf, ndigit)

# Print the minimum number of digits
print(minf)

