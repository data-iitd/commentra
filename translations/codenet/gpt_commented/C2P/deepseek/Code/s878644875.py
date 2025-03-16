# Read the first string from user input
s = input()

# Read the second string from user input
t = input()

# Initialize a counter to keep track of matching characters
hit = 0

# Loop through the first three characters of both strings
for i in range(3):
    # Check if the characters at the same position in both strings match
    if s[i] == t[i]:
        hit += 1  # Increment the hit counter if there's a match

# Output the total number of matching characters
print(hit)
