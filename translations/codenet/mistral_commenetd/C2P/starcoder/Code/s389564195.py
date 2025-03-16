# Include the standard input/output library
import sys

# Declare the main function with no arguments and no return value
def main():

    # Declare two integer variables, x and kotae
    x = 0
    kotae = 0

    # Ask the user to input an integer value for x
    x = int(input("Enter an integer value for x: "))

    # Calculate the cube of the input integer x and store the result in the variable kotae
    kotae = x*x*x

    # Print the result (the cube of the input integer) to the console
    print("The cube of", x, "is", kotae, ".")

    # Return 0 to indicate successful execution of the program
    return 0

# Call the main function
if __name__ == "__main__":
    main()

