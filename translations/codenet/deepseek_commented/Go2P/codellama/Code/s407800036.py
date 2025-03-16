
# Code for A - Between Two Integers
A, B, C = map(int, input().split())

# Read three integers A, B, and C from standard input
# Check if C is between A and B (inclusive)
if C >= A and C <= B:
    # If C is between A and B, print "Yes"
    print("Yes")
else:
    # If C is not between A and B, print "No"
    print("No")

