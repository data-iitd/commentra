import sys

# Method to check if a character is a Latin letter
def is_latin_letter(c):
    return 'a' <= c <= 'z'

# Method to check if a character is a punctuation mark
def is_punctuation(c):
    return c in {'.', ',', '!', '?'}

# Main function: Entry point of the program
def main():
    # Read the input string
    s = sys.stdin.readline().strip()
    # Create a list to build the output string
    output = []
    # Get the length of the input string
    n = len(s)
    # Append the first character of the input string to the output list
    output.append(s[0])
    
    # Loop through the input string starting from the second character
    for i in range(1, n):
        c = s[i]
        # Check if the character is a Latin letter
        if is_latin_letter(c):
            # If the previous character is not a Latin letter, add a space
            if not is_latin_letter(s[i - 1]):
                output.append(' ')
            # Append the current Latin letter to the output list
            output.append(c)
        # Check if the character is a punctuation mark
        elif is_punctuation(c):
            # Append the punctuation mark to the output list
            output.append(c)
    
    # Print the final string with spaces added between Latin letters
    print(''.join(output))

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
