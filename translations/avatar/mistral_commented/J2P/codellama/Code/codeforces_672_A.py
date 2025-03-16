# Import the Python utility library for string manipulation and input/output
import sys

# Define a function named 'generate_string' that returns a string of numbers from 1 to 1000
def generate_string():
    # Use a for loop to iterate from 1 to 1000 and append each number to a string
    result = ''
    for i in range(1, 1001):
        result += str(i)

    # Return the generated string
    return result

# Define the main function that reads user input and prints the result
def main():
    # Read an integer value from the user input
    n = int(sys.stdin.readline().strip())

    # Print the character at the specified index of the generated string
    print(generate_string()[n - 1])

# Call the main function
main()

# END-OF-CODE
