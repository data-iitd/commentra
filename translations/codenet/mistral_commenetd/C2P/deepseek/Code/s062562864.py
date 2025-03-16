# Include the standard input output library
import sys

# Declare the main function
def main():
    # Declare variables a, b, c, d, i, and j
    a, b, c, d = map(int, sys.stdin.readline().split())
    
    # Multiply variables a and b and store the result in variable i
    i = a * b
    
    # Multiply variables c and d and store the result in variable j
    j = c * d
    
    # Check if the value of i is greater than j
    if i > j:
        # If true, print the value of i
        print(i)
    else:
        # If the condition in the if statement is false
        # Print the value of j
        print(j)

# Call the main function
if __name__ == "__main__":
    main()

# End-of-code
