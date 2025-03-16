# Take input from the user and split it into three variables a, b, and c
a, b, c = input().strip().split()

# Check if all three variables are equal
if a == b and b == c:
    # If they are equal, print "Yes"
    print("Yes")
else:
    # If they are not equal, print "No"
    print("No")
