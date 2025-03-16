
import math # Importing math module for mathematical operations

# Read an integer input from the user
x = int(input())

# If x is even and not equal to 2, increment x to make it odd
if x!= 2 and x % 2 == 0: 
    x += 1

# Infinite loop to find the next prime number
while True:
    i = 3 # Variable to hold the divisor
    # Calculate the square root of x for optimization
    sqrtNum = math.sqrt(x)
    
    # Check for factors of x from 3 to the square root of x, incrementing by 2 (to check only odd numbers)
    while i <= sqrtNum:
        # If i divides x, then x is not prime
        if x % i == 0: 
            break # Exit the loop if a divisor is found
        i += 2 # Increment i by 2 to check the next odd number
    
    # If no divisors were found, i will be greater than sqrtNum, indicating x is prime
    if i > sqrtNum: 
        break # Exit the while loop as we found a prime number
    
    # Increment x by 2 to check the next odd number
    x += 2

# Output the next prime number
print(x)

