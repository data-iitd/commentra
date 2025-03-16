
# Python code to count the occurrences of each letter in a string

# Initialize the alpha dictionary to count occurrences of each letter
alpha = {}

# Read a string from the user
string = input("Enter a string: ")

# Loop through each character in the string
for ch in string:
    # Check if the character is an alphabet letter
    if ch.isalpha():
        # Convert the character to lowercase and count its occurrences
        ch = ch.lower()
        if ch in alpha:
            alpha[ch] += 1
        else:
            alpha[ch] = 1

# Print the count of each letter
for letter in alpha:
    print(f"{letter}: {alpha[letter]}")

# End of Python code

