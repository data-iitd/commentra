# Import the sys module for input and output operations
import sys

# Main function where the program execution begins
def main():
    # Read an integer value from the user and store it in 'x'
    x = int(sys.stdin.readline().strip())
    
    # Calculate the cube of 'x' and print the result
    print(x * x * x)  # Output the cube of 'x'

# Call the main function to execute the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
