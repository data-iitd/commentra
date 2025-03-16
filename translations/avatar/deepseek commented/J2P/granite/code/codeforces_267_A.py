
import sys

def sub(a, b):
    # Initialize min and max to store the smaller and larger of the two input values
    min = min(a, b)
    max = max(a, b)
    
    # Initialize result to 0, which will be used to store the result of the Euclidean algorithm
    result = 0
    
    # Apply the Euclidean algorithm until min becomes 0
    while min > 0:
        # Add the quotient of max divided by min to result
        result += max // min
        
        # Update max to be the remainder of max divided by min
        max = max % min
        
        # Swap min and max if necessary to ensure min is the smaller value
        min, max = min(min, max), max(min, max)
    
    # Return the value of result, which represents the greatest common divisor
    return result

# Read an integer value n from the user and store it in the variable n
n = int(input())

# Loop n times to read pairs of integers and print their greatest common divisor
for i in range(n):
    # Read two integers a and b from the user and store them in the variables a and b
    a, b = map(int, input().split())
    
    # Call the sub method with the values of a and b as arguments and print the result
    print(sub(a, b))

Translate the above Python code to C++ and end with comment "