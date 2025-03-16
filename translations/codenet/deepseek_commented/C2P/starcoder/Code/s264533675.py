# Include the standard input/output library
import sys

# Define the main function
def main():
    # Declare a character array to hold the input string
    str = [None] * 30
    # Read input from the user
    str = sys.stdin.readline()
    # Modify the string by replacing the character at position 5 with a space
    str[5] =''
    # Modify the string by replacing the character at position 13 with a space
    str[13] =''
    # Print the modified string to the console
    print(str)

# Call the main function
if __name__ == "__main__":
    main()

