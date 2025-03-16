# Initialize a string variable to store the input
s = input()

# Initialize a variable to count the number of '1's in the input string
ans = 0
# Iterate over each character in the string `s`
for c in s:
    # Check if the character is '1'
    if c == '1':
        # Increment the count of '1's
        ans += 1

# Print the count of '1's to the standard output
print(ans)

# <END-OF-CODE>
