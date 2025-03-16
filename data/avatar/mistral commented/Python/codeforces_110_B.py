
# Define a constant string "abcd"
LUCKY = "abcd"

# Ask the user to input an integer n
n = int( input() )

# Initialize an empty string s
s = ""

# Use a for loop to iterate through the range of integers from 0 to n-1
for i in range(n):
    # Add the character at index i % 4 of the string LUCKY to the string s
    s += LUCKY[i % 4]

# Print the final string s
print(s)