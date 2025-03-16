# Read input values from the user
a, b, c, d = map(int, input().split())

# Check if the condition is true
if a * b % 2 == 1 and (c + d) % 2 == 1:
    # If the condition is true, print "No"
    print("No")
else:
    # If the condition is false, print "Yes"
    print("Yes")

# <END-OF-CODE>
