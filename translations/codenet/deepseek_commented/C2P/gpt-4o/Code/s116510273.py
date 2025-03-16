# Import the sys module for reading input
import sys

def main():
    mes = input()  # Read a string input from the user

    # Calculate the length of the string excluding the first and last character
    length = len(mes) - 2

    # Print the first character, the calculated length, and the last character of the string
    print(f"{mes[0]}{length}{mes[-1]}")

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
