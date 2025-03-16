
# Import the Python utility library for string manipulation and input/output
import sys

# Define a function named 'generateString' that returns a string representing a string of numbers from 1 to 1000
def generateString():
    sb = "" # Create an empty string

    # Use a for loop to append numbers from 1 to 1000 to the string
    for i in range(1, 1001):
        sb += str(i) # Append the current number to the string

    # Return the generated string
    return sb

# Define the main method that reads user input and prints the result
def main():
    n = int(input()) # Read an integer value from the user input

    # Print the character at the specified index of the generated string
    print(generateString()[n - 1])

# Call the main method to execute the program
if __name__ == "__main__":
    main()
