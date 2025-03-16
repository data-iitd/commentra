# Import necessary modules
import sys

def main():
    # Read input string from the user
    str_input = input().strip()

    # Find the index of the dot ('.') in the string
    dot_index = str_input.index('.')

    # Check if the character before the dot is '9'
    if str_input[dot_index - 1] == '9':
        print("GOTO Vasilisa.")
    # If the character before the dot is not '9', check the digit after the dot
    elif int(str_input[dot_index + 1]) > 4:
        # Increment the number before the dot by 1 and print the result
        number_before_dot = str_input[:dot_index]
        print(int(number_before_dot) + 1)
    # If the digit after the dot is 4 or less, print the number before the dot without any changes
    else:
        print(str_input[:dot_index])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
