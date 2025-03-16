# Import necessary modules
import sys

def main():
    # Read input from the user
    str_input = input().strip()
    
    # Initialize variable to store the index of the decimal point
    dot_index = str_input.index('.')
    
    # Check if the digit before the decimal point is '9'
    if str_input[dot_index - 1] == '9':
        # If it is, print a specific message
        print("GOTO Vasilisa.")
    # Check if the digit after the decimal point is greater than 4
    elif int(str_input[dot_index + 1]) > 4:
        # If it is, create a new string from the integer part and add 1
        integer_part = str_input[:dot_index]
        # Print the incremented value
        print(int(integer_part) + 1)
    # If the digit after the decimal point is 4 or less
    else:
        # Print the integer part as it is
        print(integer_part)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
