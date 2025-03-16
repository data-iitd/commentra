# Declare two integer variables h and r
h, r = map(int, input().split())

# Compare the value of r with -h
if r > -h:
    # If r is greater than -h, print "1"
    print("1")
elif r == -h:
    # If r is equal to -h, print "0"
    print("0")
else:
    # If r is less than -h, print "-1"
    print("-1")

# End of the program
# <END-OF-CODE>
