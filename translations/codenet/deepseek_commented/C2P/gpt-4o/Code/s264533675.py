# Include the standard input/output library
def main():  # Define the main function
    str_input = input()  # Read input from the user
    str_list = list(str_input)  # Convert the string to a list to modify it
    str_list[5] = ' '  # Modify the string by replacing the character at position 5 with a space
    str_list[13] = ' '  # Modify the string by replacing the character at position 13 with a space
    modified_str = ''.join(str_list)  # Join the list back into a string
    print(modified_str)  # Print the modified string to the console

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
