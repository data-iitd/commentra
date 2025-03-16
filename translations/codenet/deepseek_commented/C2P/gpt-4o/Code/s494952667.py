# Include headers for input/output operations
# Include headers for string manipulation

def main():
    str_input = input()  # Read a string from the user
    
    len_str = len(str_input)  # Calculate the length of the input string

    # Reverse the string and print it
    for i in range(len_str - 1, -1, -1):
        print(str_input[i], end='')  # Print each character in reverse order
    print()  # Print a newline character at the end

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
