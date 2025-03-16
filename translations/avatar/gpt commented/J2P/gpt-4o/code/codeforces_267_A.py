# Import the sys module for user input
import sys

def main():
    # Read the number of test cases from user input
    n = int(sys.stdin.readline().strip())
    
    # Loop through each test case
    for _ in range(n):
        # Read two integers a and b from user input
        a, b = map(int, sys.stdin.readline().strip().split())
        
        # Call the sub method and print the result
        print(sub(a, b))

# Method to perform a specific subtraction-like operation
def sub(a, b):
    # Determine the minimum and maximum of the two numbers
    min_val = min(a, b)
    max_val = max(a, b)
    
    # Initialize the result variable to store the final output
    result = 0
    
    # Continue the process while min_val is greater than 0
    while min_val > 0:
        # Add the quotient of max_val divided by min_val to the result
        result += max_val // min_val
        
        # Update max_val to be the remainder of max_val divided by min_val
        max_val = max_val % min_val
        
        # Update min_val and max_val for the next iteration
        curr_min = min(min_val, max_val)
        curr_max = max(min_val, max_val)
        min_val = curr_min
        max_val = curr_max
    
    # Return the final result
    return result

if __name__ == "__main__":
    main()

# <END-OF-CODE>
