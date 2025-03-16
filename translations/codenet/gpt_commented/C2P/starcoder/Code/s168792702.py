# <START-OF-CODE>

# Declare three integer variables to hold the input values
a = 0
b = 0
c = 0

# Read three integers from standard input
a, b, c = map(int, input().split())

# Check if the first number is less than the second, and the second is less than the third
if (a < b and b < c):
    print("Yes")  # If the condition is true, print "Yes"
else:
    print("No")   # If the condition is false, print "No"

# 