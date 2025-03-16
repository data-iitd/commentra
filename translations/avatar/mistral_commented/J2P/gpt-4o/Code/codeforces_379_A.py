# Import the sys module for reading input
import sys

def main():
    # Read the first integer value from user input
    a = int(sys.stdin.readline().strip())
    # Read the second integer value from user input
    b = int(sys.stdin.readline().strip())
    
    # Initialize the result variable with the value of 'a'
    res = a
    
    # Start a while loop that continues as long as 'a' is greater than or equal to 'b'
    while a >= b:
        # Increment the result variable by the result of dividing 'a' by 'b'
        res += (a // b)
        
        # Update the value of 'a' with the result of the division and the remainder
        a = (a // b) + (a % b)
    
    # Print the value of the result variable to the standard output stream
    print(res)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
