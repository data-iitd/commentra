# Read two integers from the user, separated by a space
A, B = map(int, input().split())

# Calculate the difference between A and 2 times B
ans = A - 2 * B

# Check if the difference is negative
if ans < 0:
    # If it is, set it to zero
    ans = 0

# Print the final answer
print(ans)
