# Importing necessary libraries
import sys

def main():
    # Reading a line of input from the console
    str_input = input().strip()  # Using input() to read a line and strip any extra whitespace

    dot_index = 0  # Initializing dot_index variable to 0

    # Finding the index of the last occurrence of '.' character in the string
    for i in range(len(str_input)):
        if str_input[i] == '.':
            dot_index = i
            break

    # Checking if the character before the '.' character is '9'
    if str_input[dot_index - 1] == '9':
        print("GOTO Vasilisa.")  # Printing the message if the condition is true

    # Checking if the character after the '.' character is a digit greater than 4
    elif int(str_input[dot_index + 1]) > 4:
        _str = str_input[:dot_index]  # Creating a substring from the beginning to the index of '.' character

        # Performing big integer addition and printing the result
        print(int(_str) + 1)  # Converting the substring to an integer, adding 1, and printing the result

    # Printing the substring of the input from the beginning to the index of '.' character
    else:
        print(str_input[:dot_index])  # Printing the substring

if __name__ == "__main__":
    main()  # Calling the main function to execute the program

# <END-OF-CODE>
