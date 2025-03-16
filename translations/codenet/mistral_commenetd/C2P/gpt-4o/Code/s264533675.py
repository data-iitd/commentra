# Import the sys module for input/output operations
import sys

def main():  # Define the main function
    str_input = input()  # Get a string input from the user

    # Convert the string to a list of characters to modify specific indices
    str_list = list(str_input)

    # Assign a space character to the 6th index (index starts from 0) and 14th index of the string
    str_list[5] = ' '
    str_list[13] = ' '

    # Join the list back into a string and print the modified string
    print(''.join(str_list))

# Call the main function to execute the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
