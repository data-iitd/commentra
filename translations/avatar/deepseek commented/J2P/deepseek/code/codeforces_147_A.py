def is_latin_letter(c):
    return 'a' <= c <= 'z'


def is_punctuation(c):
    return c in ['.', ',', '!', '?']


def main():
    import sys
    input = sys.stdin.readline
    # Read the input string
    s = input().strip()
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
        if is_latin_letter(c):
            # If the previous character is not a Latin letter, add a space
            if not is_latin_letter(s[i - 1]):
                sb.append(' ')
            # Append the current Latin letter to the StringBuilder
            sb.append(c)
        # Check if the character is a punctuation mark
        elif is_punctuation(c):
            # Append the punctuation mark to the StringBuilder
            sb.append(c)
    # Print the final string with spaces added between Latin letters
    print(''.join(sb))


main()
