# Initialize a list 'c' of size 26 to store the count of each character.
c = [0] * 26

# Use a loop to read strings from the standard input until EOF is reached.
try:
    while True:
        str_input = input()  # Read a line of input.
        # Traverse the string 'str_input'.
        for p in str_input:
            # Check if the current character is a lowercase or uppercase letter.
            if 'a' <= p <= 'z':
                # Increment the count of the corresponding character in the 'c' list.
                c[ord(p) - ord('a')] += 1
            elif 'A' <= p <= 'Z':
                # Increment the count of the corresponding character in the 'c' list.
                c[ord(p) - ord('A')] += 1
except EOFError:
    pass  # End of input

# Print the count of each character and its corresponding character.
for i in range(26):
    print(f"{chr(ord('a') + i)} : {c[i]}")

# End of the code
# <END-OF-CODE>
