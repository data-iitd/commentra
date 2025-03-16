import sys

# Method to check if a character is a lowercase Latin letter
def is_latin_letter(c):
    return 'a' <= c <= 'z'

# Method to check if a character is a punctuation mark
def is_punctuation(c):
    # Check for specific punctuation characters
    if c == '.': return True
    if c == ',': return True
    if c == '!': return True
    if c == '?': return True
    return False

# Main function
def main():
    # Read a line of input from the user
    s = sys.stdin.readline().strip()
    # Initialize a StringBuilder to construct the output string
    sb = []
    n = len(s)  # Get the length of the input string
    
    # Append the first character of the input string to the StringBuilder
    sb.append(s[0])
    
    # Loop through the input string starting from the second character
    for i in range(1, n):
        c = s[i]  # Get the current character
        
        # Check if the current character is a Latin letter
        if is_latin_letter(c):
            # If the previous character is not a Latin letter, append a space
            if not is_latin_letter(s[i - 1]):
                sb.append(' ')
            # Append the current Latin letter to the StringBuilder
            sb.append(c)
        # Check if the current character is a punctuation mark
        elif is_punctuation(c):
            sb.append(c)  # Append the punctuation mark to the StringBuilder
    
    # Print the constructed output string
    print(''.join(sb))

if __name__ == "__main__":
    main()
