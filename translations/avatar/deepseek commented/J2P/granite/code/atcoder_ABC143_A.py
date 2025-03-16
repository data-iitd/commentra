
import sys # Importing sys module for input operations

def main(): # Defining the main function
    try: # Beginning of try block to handle potential exceptions
        a, b = map(int, sys.stdin.readline().split()) # Reading input and splitting it into two integers
        c = a - b * 2 # Performing a mathematical operation to calculate a result
        if c < 0: c = 0 # Checking if the result is negative and setting it to 0 if true
        print(c) # Printing the result to the standard output
    except Exception as e: # Catch block to handle exceptions
        # Handle exceptions (not implemented in this code)

if __name__ == "__main__": # Checking if the script is being run directly
    main() # Calling the main function

