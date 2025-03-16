# Importing the sys module for input and output operations
import sys

def main():
    # Reading an integer input from the user
    x = int(input().strip())
    
    # Using a ternary operator to determine the boolean value based on the input
    bool_value = True if x == 1 else False
    
    # Setting the result based on the boolean value; if bool_value is False, result is 1, otherwise 0
    result = 1 if not bool_value else 0
    
    # Printing the result to the console
    print(result)

# Calling the main function to execute the code
if __name__ == "__main__":
    main()

# <END-OF-CODE>
