# Importing necessary libraries for reading input and writing output
import sys

# Method to check if a character is a Latin letter
def is_latin_letter(c):
    # Check if the character falls within the ASCII range of Latin letters
    return 'a' <= c <= 'z'

# Method to check if a character is a punctuation mark
def is_punctuation(c):
    # Check if the character is a dot, comma, exclamation mark, or question mark
    return c in {'.', ',', '!', '?'}

def main():
    # Reading a line of input from the console
    s = sys.stdin.readline().strip()

    # Creating a list to store the output
    output = []

    # Finding the length of the input string
    n = len(s)

    # Appending the first character of the input string to the output list
    output.append(s[0])

    # Iterating through the rest of the characters in the input string
    for i in range(1, n):
        c = s[i]  # Getting the current character from the input string

        # If the current character is a Latin letter
        if is_latin_letter(c):
            # Append it to the output list with a space before it if the previous character was not a Latin letter
            if not is_latin_letter(s[i - 1]):
                output.append(' ')
            output.append(c)
        # If the current character is a punctuation mark, append it directly to the output list without a space
        elif is_punctuation(c):
            output.append(c)

    # Writing the output to the console
    print(''.join(output))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
