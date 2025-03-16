# Declare three integer variables to hold the input values
a, b, c = map(int, input().split())

# Check if the difference between b and a is equal to the difference between c and b
if b - a == c - b:
    # If the condition is true, print "YES"
    print("YES")
else:
    # Otherwise, print "NO"
    print("NO")
# <END-OF-CODE>
