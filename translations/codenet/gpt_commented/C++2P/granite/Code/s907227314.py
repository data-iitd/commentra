
# Read input string from the user
s = input()

# Declare variables to store the positions of 'A' and 'Z'
a = -1
z = -1

# Loop through the string to find the first occurrence of 'A'
for i in range(len(s)):
    if s[i] == 'A':
        a = i
        break

# Loop through the string in reverse to find the last occurrence of 'Z'
for i in range(len(s) - 1, -1, -1):
    if s[i] == 'Z':
        z = i
        break

# Calculate the number of characters between 'A' and 'Z' (inclusive) and print the result
print(z - a + 1)

