

import sys # Import sys module for handling input/output operations

def main(): # Main function to start the program
    a = input() # Read the input string from the console and store it in the 'a' variable
    a = a.replace(',','') # Replace all occurrences of ',' in the 'a' string with a single space
    print(a) # Print the modified string to the console

if __name__ == "__main__": # Check if the script is being run directly
    main() # Call the main function to start the program

