# Read a line of input, split it into parts, and convert each part to an integer
cookies = [int(x) for x in input().split()]

# Calculate the leftover cookies after taking some from the third type
leftOver = cookies[0] - cookies[2]

# Determine the number of cookies Takahashi can take, ensuring it's not negative
takahashi = max(0, leftOver)

# Print the number of cookies Takahashi can take, and the remaining cookies of the second type
# If Takahashi can take cookies, print the second type's count; otherwise, calculate the remaining
print(str(takahashi) + ' ' + (str(cookies[1]) if takahashi > 0 else str(max(0, cookies[1] - abs(leftOver)))))
