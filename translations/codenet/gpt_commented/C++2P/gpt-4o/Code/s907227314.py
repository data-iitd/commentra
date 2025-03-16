# Declare a string variable to hold the input
s = input()

# Initialize variables to store the positions of 'A' and 'Z'
a = -1
z = -1

# Loop through the string to find the first occurrence of 'A'
for i in range(len(s)):
    if s[i] == 'A':
        a = i  # Store the index of 'A'
        break  # Exit the loop once 'A' is found

# Loop through the string in reverse to find the last occurrence of 'Z'
for i in range(len(s) - 1, -1, -1):
    if s[i] == 'Z':
        z = i  # Store the index of 'Z'
        break  # Exit the loop once 'Z' is found

# Calculate the number of characters between 'A' and 'Z' (inclusive) and print the result
print(z - a + 1)

# <END-OF-CODE>
