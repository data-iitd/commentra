# Declare variables A, B, and C to hold integer values
A, B, C = map(int, input().split())

# Check if C is within the range defined by A and B (inclusive)
if A <= C <= B:
    # If C is within the range, print "Yes"
    print("Yes")
else:
    # If C is outside the range, print "No"
    print("No")

# <END-OF-CODE>
