
import sys # Import the sys module for reading input

def main():
    n = sys.stdin.read().strip() # Read the input string and remove any leading or trailing whitespace
    s = False # Initialize a boolean variable to keep track of the state

    # Process each character in the input string
    for i in range(len(n)):
        if n[i] == '.': # Check if the current character is a dot
            if s: # If the state is true
                print(1, end='') # Print '1' and reset the state to false
                s = False
            else: # If the state is false
                print(0, end='') # Print '0' and set the state to false
                s = False
        else: # If the current character is not a dot
            if s: # If the state is true
                print(2, end='') # Print '2' and reset the state to false
                s = False
            else: # If the state is false
                s = True # Set the state to true
    print() # Print a newline character to separate the output from the rest of the program

if __name__ == '__main__':
    main() # Call the main function

