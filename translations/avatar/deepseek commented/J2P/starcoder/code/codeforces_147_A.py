
import sys

# Method to check if a character is a Latin letter
def isLatinLetter(c):
    return c >= 'a' and c <= 'z'

# Method to check if a character is a punctuation mark
def isPunctuation(c):
    if c == '.':
        return True
    if c == ',':
        return True
    if c == '!':
        return True
    if c == '?':
        return True
    return False

# Main method: Entry point of the program
def main():
    # Read the input string
    s = sys.stdin.readline()
    # Create a StringBuilder to build the output string
    sb = []
    # Get the length of the input string
    n = len(s)
    # Append the first character of the input string to the StringBuilder
    sb.append(s[0])
    # Loop through the input string starting from the second character
    for i in range(1, n):
        c = s[i]
        # Check if the character is a Latin letter
        if isLatinLetter(c):
            # If the previous character is not a Latin letter, add a space
            if not isLatinLetter(s[i - 1]):
                sb.append(' ')
            # Append the current Latin letter to the StringBuilder
            sb.append(c)
        # Check if the character is a punctuation mark
        elif isPunctuation(c):
            # Append the punctuation mark to the StringBuilder
            sb.append(c)
    # Print the final string with spaces added between Latin letters
    print(''.join(sb))

# Entry point of the program
if __name__ == '__main__':
    main()

