s = input()  # Take input string from user
res = []  # Initialize an empty list to store the result
punctuation = [',', '.', '!', '?']  # Define a list of punctuation marks

# Iterate over each character in the input string
for i in range(len(s)):
    if i >= 1:  # Check if it's not the first character
        if s[i] == ' ':  # Check if the current character is a space
            if res[-1] != ' ':  # Check if the last character in res is not a space
                res.append(s[i])  # Append the current space to res
            else:
                continue  # Skip the current space if the last character is also a space
        else:  # If the current character is not a space
            if s[i] in punctuation:  # Check if the current character is a punctuation mark
                if res[-1] == ' ':  # Check if the last character in res is a space
                    res.pop()  # Remove the last character (space) from res
                res.append(s[i])  # Append the punctuation mark to res
                res.append(' ')  # Append a space after the punctuation mark
            else:
                res.append(s[i])  # Append the character to res if it's not a punctuation mark
    else:  # For the first character
        if s[i] == ' ':  # Check if the first character is a space
            continue  # Skip the first space
        if s[i] in punctuation:  # Check if the first character is a punctuation mark
            continue  # Skip the first punctuation mark
        else:
            res.append(s[i])  # Append the first character to res

# Join the list res into a string and print it
print(''.join(res))
