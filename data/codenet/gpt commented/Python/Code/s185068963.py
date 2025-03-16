# Read three integers from user input and unpack them into variables a, b, and c
a, b, c = map(int, input().split())

# Check if the sum of a and b is greater than or equal to c
# Print "Yes" if the condition is true, otherwise print "No"
print("Yes" if a + b >= c else "No")
