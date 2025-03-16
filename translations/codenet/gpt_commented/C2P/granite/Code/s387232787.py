
# Read strings from standard input until EOF
for str in iter(input, ''):
    # Iterate through each character in the string
    for c in str:
        # Check if the character is a lowercase letter
        if 'a' <= c and c <= 'z':
            # Increment the count for the corresponding letter
            count[c] = count.get(c, 0) + 1
        # Check if the character is an uppercase letter
        elif 'A' <= c and c <= 'Z':
            # Increment the count for the corresponding letter (converted to lowercase)
            count[c.lower()] = count.get(c.lower(), 0) + 1

# Print the count of each letter from 'a' to 'z'
for c in 'abcdefghijklmnopqrstuvwxyz':
    print(c, ':', count.get(c, 0))

