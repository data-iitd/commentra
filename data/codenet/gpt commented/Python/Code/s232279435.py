# Read an integer input for the length of the string
n = int(input())

# Read a string input
s = str(input())

# Initialize a variable to keep track of the maximum number of common characters
ans = 0

# Iterate through each index of the string
for i in range(n):
    # Create a set of characters from the substring s[0:i+1]
    x = set(s[:i+1])
    
    # Create a set of characters from the substring s[i+1:n]
    y = set(s[i+1:])

    # Initialize a counter for common characters between the two sets
    z = 0
    
    # Check each character in the first set
    for w in x:
        # If the character is also in the second set, increment the counter
        if w in y:
            z += 1
            
    # If the current count of common characters is greater than the previous maximum, update it
    if z > ans:
        ans = z

# Print the maximum number of common characters found
print(ans)
