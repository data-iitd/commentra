def main():
    # Read the next line from the console and store it in the string 's'
    s = input()

    # Get the length of the string 's'
    length = len(s)

    # Initialize a character variable 'ch' to store the first non-space and non-question mark character found in the string 's'
    ch = ' '

    # Iterate through the string 's' from the end to the beginning
    for i in range(length - 1, -1, -1):
        # Check if the current character is not a space or a question mark
        if s[i] != ' ' and s[i] != '?':
            # If yes, store the character in 'ch' and break out of the loop
            ch = s[i]
            break

    # Convert the character 'ch' to lowercase
    ch = ch.lower()

    # Check if the character 'ch' is a vowel or a y
    if ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u' or ch == 'y':
        # If yes, print "YES" to the console
        print("YES")
    else:
        # If no, print "NO" to the console
        print("NO")

# Call the main function
main()

