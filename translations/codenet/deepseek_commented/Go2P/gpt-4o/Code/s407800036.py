# Python translation of the Go code

# Read three integers A, B, and C from standard input
A, B, C = map(int, input().split())

# Check if C is between A and B (inclusive)
if A <= C <= B:
    # If C is between A and B, print "Yes"
    print("Yes")
else:
    # If C is not between A and B, print "No"
    print("No")

# <END-OF-CODE>
