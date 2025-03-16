# Assign values to variables a, b, and c from the input string
a, b, c = input().strip().split()

# Check if the values of variables a, b, and c are equal to each other
if a == b and b == c:
    # If they are, print "Yes"
    print("Yes")
else:
    # If not, print "No"
    print("No")