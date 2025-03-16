# Declare variables
c = input()  # Read a string from the standard input
ans = ''     # An empty string to store the output

# Process the string
for char in c:  # Iterate through each character in the string 'c'
    if char != 'B':  # If the current character is not 'B'
        ans += char  # Append the character to the output string 'ans'
    else:  # If the current character is 'B'
        ans = ans[:-1]  # Remove the last character from the output string 'ans'

# Print the output
print(ans)  # Print the final output string

# <END-OF-CODE>
