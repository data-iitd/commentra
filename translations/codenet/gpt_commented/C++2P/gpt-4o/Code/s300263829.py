# Import the sys module for input and output operations
import sys

# Main function where the execution of the program begins
def main():
    # Prompt the user to enter two integers
    a, b = map(int, input("Enter two integers: ").split())  # Read two integers from user input and store them in variables a and b
    
    # Calculate the product of a and b and display the result
    print("The product is:", a * b)  # Display the product of a and b

# Call the main function to execute the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
