def main():
    str = input()  # Read input from the user
    str_list = list(str)  # Convert the string to a list of characters
    str_list[5] = ' '  # Modify the list by replacing the character at position 5 with a space
    str_list[13] = ' '  # Modify the list by replacing the character at position 13 with a space
    modified_str = ''.join(str_list)  # Convert the list back to a string
    print(modified_str)  # Print the modified string to the console


main()  # Call the main function
