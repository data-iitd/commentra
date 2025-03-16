# Read three integers from the user
a, b, c = map(int, input().split())

# Check if any two of the three numbers sum up to the third number
# If a + b equals c, or b + c equals a, or a + c equals b, print "Yes"
# Otherwise, print "No"
print("Yes" if a + b == c or b + c == a or a + c == b else "No")

