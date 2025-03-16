# Declare three integer variables a, b, and c
a, b, c = map(int, input().split())

# Check if c is within the range [a, b]
if a <= c <= b:
    # If c is within the range, print "Yes"
    print("Yes")
else:
    # If c is outside the range, print "No"
    print("No")

# <END-OF-CODE>
