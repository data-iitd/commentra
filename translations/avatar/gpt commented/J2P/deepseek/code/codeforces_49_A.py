def main():
    # Read a line of input from the user
    s = input()
    
    # Get the length of the input string
    length = len(s)
    
    # Initialize a character variable to store the last non-space, non-question mark character
    ch = ''
    
    # Loop through the string in reverse to find the last relevant character
    for i in range(length - 1, -1, -1):
        # Check if the current character is not a space or a question mark
        if s[i] != ' ' and s[i] != '?':
            ch = s[i]  # Store the character
            break  # Exit the loop once the character is found
    
    # Convert the character to lowercase for uniform comparison
    ch = ch.lower()
    
    # Check if the character is a vowel or 'y'
    if ch in ['a', 'e', 'i', 'o', 'u', 'y']:
        print("YES")  # Print "YES" if it is a vowel
    else:
        print("NO")  # Print "NO" if it is not a vowel

# Call the main function
main()
