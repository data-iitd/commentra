# Import the sys module for reading input
import sys

def main():
    # Read input values from standard input and split them into a list
    input_values = sys.stdin.read().strip().split()
    
    # Declare and initialize two integer variables "a" and "b"
    a = int(input_values[0])
    b = int(input_values[1])
    
    # Calculate the product of "a" and "b"
    product = a * b
    
    # Check if the product is even or odd using an if statement
    if product % 2 == 0:
        # If the product is even, print the message "Even" to the standard output
        print("Even")
    else:
        # If the product is odd, print the message "Odd" to the standard output
        print("Odd")

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
