
# Declare a variable to hold the input string
s = input()

# Initialize a counter to keep track of the number of '1's in the string
ans = 0

# Iterate over each character in the input string
for c in s:
    # Check if the current character is '1'
    if c == '1':
        # Increment the counter if '1' is found
        ans += 1

# Print the total count of '1's found in the input string
print(ans)

