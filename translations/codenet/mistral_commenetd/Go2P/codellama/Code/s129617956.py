
# Initialize variables
n = int(input())
rt = int(math.sqrt(n))

# Initialize minimum factor with a large value
minf = 100

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

# END-OF-CODE

Translate the above Python code to C++ and end with comment "