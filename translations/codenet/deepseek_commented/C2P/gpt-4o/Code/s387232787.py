# Array to store the count of each letter (a-z)
c = [0] * 26

# Read input strings until there are no more inputs
try:
    while True:
        # Read input string
        str_input = input()
        
        # Traverse each character in the string
        for char in str_input:
            # Check if the character is a lowercase letter
            if 'a' <= char <= 'z':
                # Increment the count for the corresponding letter
                c[ord(char) - ord('a')] += 1
            # Check if the character is an uppercase letter
            elif 'A' <= char <= 'Z':
                # Increment the count for the corresponding letter
                c[ord(char) - ord('A')] += 1
except EOFError:
    pass

# Print the counts for each letter from 'a' to 'z'
for i in range(26):
    print(f"{chr(ord('a') + i)} : {c[i]}")

# <END-OF-CODE>
