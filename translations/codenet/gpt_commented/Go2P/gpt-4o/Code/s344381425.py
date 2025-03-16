# Declare three integer variables to hold the input values
a, b, c = map(int, input().split())

# Check if the integers are in strictly increasing order
if a < b < c:
    # If they are in increasing order, print "Yes"
    print("Yes")
else:
    # If they are not in increasing order, print "No"
    print("No")

# End of the main function
# <END-OF-CODE>
