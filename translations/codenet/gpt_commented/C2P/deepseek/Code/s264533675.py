def main():
    # Declare a character array (string) of size 30 to hold user input
    str = input()

    # Replace the character at index 5 with a space
    str_list = list(str)
    str_list[5] = ' '

    # Replace the character at index 13 with a space
    str_list[13] = ' '

    # Print the modified string to the console
    print(''.join(str_list))


# Call the main function to execute the program
main()

