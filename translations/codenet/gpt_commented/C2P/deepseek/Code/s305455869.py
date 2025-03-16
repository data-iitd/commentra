# Read two integers from standard input
a, b = map(int, input().split())

# Initialize the answer variable to zero
ans = 0

# Determine the value of ans based on the value of a
if a >= 13:
    # If a is 13 or greater, set ans to b
    ans = b
elif a >= 6:
    # If a is between 6 and 12, set ans to half of b
    ans = b // 2

# Output the result
print(ans)
