
import math # Importing the math module for mathematical operations

# Step 1: Read an integer input from the user
x = int(input())

# Step 2: Check if the input is not equal to 2 and is even. If so, increment the input by 1.
if x!= 2 and x % 2 == 0:
    x += 1

# Step 3: Enter a loop where it checks if the number is a prime number.
while True:
    i = 3
    sqrtNum = math.sqrt(x) # Calculate the square root of the number

    # Step 4: Check for factors from 3 up to the square root of the number, incrementing by 2 (only odd numbers)
    while i <= sqrtNum:
        if x % i == 0:
            break # If a factor is found, break out of the loop
        i += 2

    # Step 5: If no factors are found and i is greater than the square root, the number is prime
    if i > sqrtNum:
        break # Exit the loop once a prime number is found

    # If the number is not prime, increment by 2 and check again
    x += 2

# Step 5: Print the prime number found
print(x)

