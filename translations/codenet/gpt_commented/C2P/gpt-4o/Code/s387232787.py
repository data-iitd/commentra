# Array to hold the count of each letter (a-z)
c = [0] * 26

# Read strings from standard input until EOF
try:
    while True:
        # Read a line of input
        str_input = input()
        # Iterate through each character in the string
        for p in str_input:
            # Check if the character is a lowercase letter
            if 'a' <= p <= 'z':
                # Increment the count for the corresponding letter
                c[ord(p) - ord('a')] += 1
            # Check if the character is an uppercase letter
            elif 'A' <= p <= 'Z':
                # Increment the count for the corresponding letter (converted to lowercase)
                c[ord(p) - ord('A')] += 1
except EOFError:
    pass

# Print the count of each letter from 'a' to 'z'
for i in range(26):
    print(f"{chr(ord('a') + i)} : {c[i]}")

# Indicate that the program ended successfully
# <END-OF-CODE>
