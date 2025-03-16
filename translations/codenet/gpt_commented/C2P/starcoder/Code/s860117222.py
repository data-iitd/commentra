# <START-OF-CODE>

# Declare three long long integer variables to hold input values
a, b, c = 0, 0, 0

# Read three long long integers from standard input
a, b, c = map(int, input().split())

# Calculate the value of d as the difference between c and the sum of a and b
d = c - (a + b)

# Check if d is positive and if 4 times the product of a and b is less than d squared
if (d > 0) and ((4 * a * b) < (d * d)):
    # If the condition is true, print "Yes"
    print("Yes")
else:
    # If the condition is false, print "No"
    print("No")

# 