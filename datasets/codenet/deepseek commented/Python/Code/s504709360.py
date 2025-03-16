
s = input()  # Take a string input from the user

# Check if the length of the string is less than 26
if len(s) < 26:
    # Iterate through the alphabet from 'a' to 'z'
    for i in range(26):
        c = chr(ord("a") + i)  # Get the character at position i in the alphabet
        # Check if the character is not in the input string
        if c not in s:
            # Print the input string concatenated with the missing character and exit
            print(s + c)
            exit()
else:
    # Iterate through the string in reverse order, starting from the second last character to the first character
    for i in reversed(range(1, 26)):
        # Check if the previous character is less than the current character
        if s[i - 1] < s[i]:
            s1 = s[0:i - 1]  # Create a new string from the start to the previous character
            # Iterate through the alphabet from 'a' to 'z'
            for j in range(26):
                c = chr(ord("a") + j)  # Get the character at position j in the alphabet
                # Check if the character is greater than the previous character and not in the new string
                if c > s[i - 1] and c not in s1:
                    # Print the new string concatenated with the found character and exit
                    print(s1 + c)
                    exit()
    # If no such character is found, print -1
    print(-1)

