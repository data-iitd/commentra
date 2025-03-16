# Import the necessary library for input
import sys

# Define a function named 'generate_string' that returns a string of numbers from 1 to 1000
def generate_string():
    sb = []  # Create a list to hold the numbers as strings

    # Use a for loop to append numbers from 1 to 1000 to the list
    for i in range(1, 1001):
        sb.append(str(i))  # Append the current number as a string to the list

    # Join the list into a single string and return it
    return ''.join(sb)

# Define the main function that reads user input and prints the result
def main():
    n = int(input())  # Read an integer value from the user input

    # Print the character at the specified index of the generated string
    print(generate_string()[n - 1])

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
