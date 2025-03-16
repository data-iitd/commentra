
import sys # Import the sys module for input and output

def sub(a, b):
    # Determine the minimum and maximum of the two numbers
    min = min(a, b)
    max = max(a, b)
    
    # Initialize the result variable to store the final output
    result = 0
    
    # Continue the process while min is greater than 0
    while min > 0:
        # Add the quotient of max divided by min to the result
        result += max // min
        
        # Update max to be the remainder of max divided by min
        max = max % min
        
        # Update min and max for the next iteration
        min, max = min(min, max), max(min, max)
    
    # Return the final result
    return result

def main():
    # Read the number of test cases from user input
    n = int(input())
    
    # Loop through each test case
    for i in range(n):
        # Read two integers a and b from user input
        a, b = map(int, input().split())
        
        # Call the sub method and print the result
        print(sub(a, b))

if __name__ == "__main__":
    main()

