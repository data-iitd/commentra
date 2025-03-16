
# Declare three integer variables to hold the input values
a, b, c = 0, 0, 0

# Read three integers from standard input
a, b, c = map(int, input().split())

# Check if the integers are in strictly increasing order
if a < b and b < c:
    # If they are in increasing order, print "Yes"
    print("Yes")
else:
    # If they are not in increasing order, print "No"
    print("No")

# End of the main function
# 