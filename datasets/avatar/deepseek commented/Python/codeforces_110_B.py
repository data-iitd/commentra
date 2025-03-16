
LUCKY = "abcd"
# Define a string LUCKY containing the characters "abcd"

n = int(input())
# Take an integer input n from the user

s = ""
# Initialize an empty string s to store the result

for i in range(n):
    # Loop n times to construct the string s
    s += LUCKY[i % 4]
    # Append a character from LUCKY to s based on the index i modulo 4

print(s)
# Print the final string s


