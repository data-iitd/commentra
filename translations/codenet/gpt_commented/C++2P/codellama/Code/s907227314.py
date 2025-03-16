# Declare a string variable to hold the input
s = input()

# Declare variables to store the positions of 'A' and 'Z'
a = 0
z = 0

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

# Return 0 to indicate successful completion of the program
return 0

