# Read input string from the user
s = input()

# Check if the length of the string is less than 26
if len(s) < 26:
    # Iterate through the alphabet (from 'a' to 'z')
    for i in range(26):
        # Get the current character by calculating its ASCII value
        c = chr(ord("a") + i)
        # Check if the character is not already in the input string
        if c not in s:
            # Print the input string concatenated with the missing character
            print(s + c)
            # Exit the program after printing
            exit()
else:
    # If the string length is 26 or more, we need to find the next lexicographical string
    for i in reversed(range(1, 26)):
        # Check if the current character is less than the next character
        if s[i - 1] < s[i]:
            # Create a substring up to the character before the current one
            s1 = s[0:i - 1]
            # Iterate through the alphabet to find a suitable character
            for j in range(26):
                # Get the current character
                c = chr(ord("a") + j)
                # Check if the character is greater than the last character of s1 and not already in s1
                if c > s[i - 1] and c not in s1:
                    # Print the new string formed by concatenating s1 with the new character
                    print(s1 + c)
                    # Exit the program after printing
                    exit()
    # If no valid string can be formed, print -1
    print(-1)
