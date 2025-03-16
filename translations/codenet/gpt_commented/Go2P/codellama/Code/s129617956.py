
# Read an integer input from the user
n = int(input())

# Calculate the integer square root of n
rt = int(n**0.5)

# Initialize a variable to keep track of the minimum number of digits found
minf = 100

# Loop through all integers from 1 to the square root of n
for i in range(1, rt+1):
    # Check if i is a divisor of n
    if n % i == 0:
        # Calculate the corresponding divisor b
        b = n // i
        
        # Initialize a counter for the number of digits in b
        ndigit = 0
        
        # Count the number of digits in b
        while b > 0:
            b //= 10
            ndigit += 1
        
        # Update minf with the minimum number of digits found
        minf = min(minf, ndigit)

# Print the minimum number of digits found among the divisors
print(minf)

