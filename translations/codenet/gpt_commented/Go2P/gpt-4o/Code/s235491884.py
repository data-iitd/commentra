# Importing the sys module for reading input
import sys

def main():
    # Read a string from standard input
    s = sys.stdin.read().strip()  # Use strip() to remove any leading/trailing whitespace

    # Count the occurrences of the letter 'o' in the input string 's'
    n = s.count('o')

    # Calculate the result based on the count of 'o' and print it
    # The formula adds 700 to 100 times the count of 'o'
    print(700 + n * 100)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
