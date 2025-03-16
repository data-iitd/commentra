# Importing the 'sys' module for reading input
import sys

# Function main is the entry point of the program
def main():
    # Read a string input from the standard input
    s = sys.stdin.read().strip()

    # Count the number of occurrences of the substring "o" in the string 's'
    n = s.count("o")

    # Calculate the result by adding 700 to the product of 100 and the number of occurrences of "o" in the string
    result = 700 + n * 100

    # Print the result to the standard output
    print(result)

# Call the main function to execute the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
