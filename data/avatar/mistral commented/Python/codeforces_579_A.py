# Import the math module for log2 function
import math

# Take an integer input from the user and assign it to the variable n
n = int(input())

# Initialize a counter variable x to 1
x = 1

# While loop starts
while True:
    # Check if the log base 2 of n is an integer yet
    if math.log2(n).is_integer():
        break

    # Increment the counter variable x by 1
    x += 1

    # Update the value of n by subtracting 2 raised to the power of the current log base 2 of n
    n -= 2 ** int(math.log2(n))

# Print the output value of x
print(x)
