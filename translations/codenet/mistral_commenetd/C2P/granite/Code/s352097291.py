

# Read a string from the standard input and store it in the 'c' variable
c = input()

# Initialize an empty string to store the output
ans = ""

# Process the string
for i in range(len(c)):
    if c[i]!= 'B':
        ans += c[i]
    else:
        ans = ans[:-1]

# Print the output
print(ans)

# The comments explain the purpose of each logical block and make the code more readable.

