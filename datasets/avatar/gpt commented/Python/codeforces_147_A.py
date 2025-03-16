# Take input from the user
s = input()

# Initialize an empty list to store the result
res = []

# Define a list of punctuation marks to check against
punctuation = [',', '.', '!', '?']

# Iterate through each character in the input string
for i in range(len(s)):
    # Check if the current index is greater than or equal to 1
    if i >= 1:
        # If the current character is a space
        if s[i] == '':
            # Only append a space if the last element in res is not a space
            if res[-1] != '':
                res.append(s[i])
            else:
                continue  # Skip if the last element is already a space
        else:
            # If the current character is a punctuation mark
            if s[i] in punctuation:
                # If the last element in res is a space, remove it
                if res[-1] == '':
                    res.pop()
                # Append the punctuation mark to the result
                res.append(s[i])
                # Append a space after the punctuation
                res.append('')
            else:
                # If the current character is not punctuation, append it to the result
                res.append(s[i])
    else:
        # For the first character, handle it separately
        if s[i] == '':
            continue  # Skip if it's a space
        if s[i] in punctuation:
            continue  # Skip if it's a punctuation mark
        else:
            # Append the first character to the result if it's not a space or punctuation
            res.append(s[i])

# Join the list into a single string and print the result
print(''.join(res))
