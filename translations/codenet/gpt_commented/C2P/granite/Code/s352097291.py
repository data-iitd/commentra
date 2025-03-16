
# Read a string input from the user
c = input()

# Declare an empty string 'ans' to store the result
ans = ''

# Iterate through each character of the input string
for i in range(len(c)):
    # If the current character is not 'B', append it to the 'ans' string
    if c[i]!= 'B':
        ans += c[i]
    # If the current character is 'B', remove the last character from 'ans' (if it exists)
    else:
        ans = ans[:-1]

# Print the resulting string after processing the input
print(ans)

