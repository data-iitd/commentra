# Read two integers from the standard input
a, b = map(int, input().split())

# Initialize the answer variable 'ans' to zero
ans = 0

# Check if 'a' is greater than or equal to 13
if a >= 13:
    ans = b  # If 'a' is greater than or equal to 13, then the answer is 'b'
# Else if 'a' is greater than or equal to 6
elif a >= 6:
    ans = b // 2  # If 'a' is greater than or equal to 6, then the answer is half of 'b'

# Print the answer to the standard output
print(ans)  # Output the result

# <END-OF-CODE>
