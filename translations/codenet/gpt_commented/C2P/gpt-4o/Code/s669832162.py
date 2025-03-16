# Declare variables to hold the month and day values for two dates
m1, d1, m2, d2 = map(int, input().split())

# Compare the months of the two dates
if m1 != m2:
    # If the months are different, print "1"
    print("1")
else:
    # If the months are the same, print "0"
    print("0")

# Return 0 to indicate successful completion of the program
# (Note: In Python, we don't explicitly return from the main function)
# <END-OF-CODE>
