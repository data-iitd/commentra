def main():
    # Read an integer value n from the user
    n = int(input())
    
    # Loop n times to read pairs of integers and print their greatest common divisor
    for _ in range(n):
        # Read two integers a and b from the user
        a, b = map(int, input().split())
        
        # Call the sub function with the values of a and b as arguments and print the result
        print(sub(a, b))

# Define the sub function to calculate the greatest common divisor using the Euclidean algorithm
def sub(a, b):
    # Initialize min and max to store the smaller and larger of the two input values
    min_val = min(a, b)
    max_val = max(a, b)
    
    # Initialize result to 0, which will be used to store the result of the Euclidean algorithm
    result = 0
    
    # Apply the Euclidean algorithm until min becomes 0
    while min_val > 0:
        # Add the quotient of max divided by min to result
        result += max_val // min_val
        
        # Update max to be the remainder of max divided by min
        max_val = max_val % min_val
        
        # Swap min and max if necessary to ensure min is the smaller value
        min_val, max_val = min(min_val, max_val), max(min_val, max_val)
    
    # Return the value of result, which represents the greatest common divisor
    return result

if __name__ == "__main__":
    main()

# <END-OF-CODE>
