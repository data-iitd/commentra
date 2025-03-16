
# Declare two integer variables 'a' and 'b'
a, b = 0, 0

# Read two integers from the standard input and store them in variables 'a' and 'b'
a, b = map(int, input().split())

# Initialize the answer variable 'ans' to zero
ans = 0

# Check if 'a' is greater than or equal to 13
if a >= 13:
    ans = b

# Else if 'a' is greater than or equal to 6
elif a >= 6:
    ans = b/2

# Print the answer to the standard output
print(ans)

