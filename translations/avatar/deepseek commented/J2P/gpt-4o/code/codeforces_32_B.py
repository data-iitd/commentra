# Import the sys module for reading input
import sys

def main():
    n = sys.stdin.read().strip()  # Read the input string and remove any surrounding whitespace
    s = False  # Initialize a boolean variable to keep track of the state

    # Process each character in the string
    for char in n:
        if char == '.':  # Check if the current character is a dot
            if s:  # If the state is true
                print(1, end='')  # Print '1' and reset the state to false
                s = False
            else:  # If the state is false
                print(0, end='')  # Print '0' and set the state to false
                s = False
        else:  # If the current character is not a dot
            if s:  # If the state is true
                print(2, end='')  # Print '2' and reset the state to false
                s = False
            else:  # If the state is false
                s = True  # Set the state to true

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
