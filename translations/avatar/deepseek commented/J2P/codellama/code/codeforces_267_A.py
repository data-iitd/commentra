import math

def main():
    # Create a new Scanner object to read input from the user
    scan = input()
    
    # Read an integer value n from the user and store it in the variable n
    n = int(scan)
    
    # Loop n times to read pairs of integers and print their greatest common divisor
    for i in range(n):
        # Read two integers a and b from the user and store them in the variables a and b
        a = int(input())
        b = int(input())
        
        # Call the sub method with the values of a and b as arguments and print the result
        print(sub(a, b))

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
        curr_min = min(min, max)
        curr_max = max(min, max)
        min = curr_min
        max = curr_max
    
    # Return the value of result, which represents the greatest common divisor
    return result

main()

