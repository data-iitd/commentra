# Declare three integer variables to hold the input values
a, b, c = map(int, input().split())

# Check if the difference between the first two numbers is equal to the difference between the last two numbers
if b - a == c - b:
    # If the differences are equal, print "YES"
    print("YES")
else:
    # If the differences are not equal, print "NO"
    print("NO")

# <END-OF-CODE>
