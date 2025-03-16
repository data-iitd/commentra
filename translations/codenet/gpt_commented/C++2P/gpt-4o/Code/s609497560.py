# Import the sys module for input and output operations (not necessary for this simple example)

# Main function where the execution of the program begins
def main():
    # Prompt the user to enter a value for 'a'
    a = int(input("Enter a number: "))  # Read the input value from the user and convert it to an integer

    # Calculate the expression a + a^2 + a^3 and output the result
    print(a + (a ** 2) + (a ** 3))  # Use ** for exponentiation in Python

# Call the main function to execute the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
