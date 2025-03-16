# Declare four integer variables to hold input values
a, b, c, d = int(input()), int(input()), int(input()), int(input())

# Compare the sum of the first two integers (a and b) with the sum of the last two integers (c and d)
if a + b > c + d:
    # If the sum of a and b is greater, print "Left"
    print("Left")
elif a + b < c + d:
    # If the sum of a and b is less, print "Right"
    print("Right")
else:
    # If both sums are equal, print "Balanced"
    print("Balanced")

# 