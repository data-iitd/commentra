
import sys # Importing sys module for system-specific parameters and functions

def main(): # Defining the main function
    a = input() # Reading a line of input from the user
    a = a.replace(",", " ") # Replacing commas with spaces in the input string
    print(a) # Printing the manipulated string

if __name__ == "__main__": # Checking if the script is being run directly
    main() # Calling the main function

