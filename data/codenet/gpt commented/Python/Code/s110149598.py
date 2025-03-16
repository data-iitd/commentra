# Take two inputs from the user and split them into variables a and b
a, b = input().split()

# Compare the two inputs
if a < b:
    # If a is less than b, print "<"
    print("<")
elif a > b:
    # If a is greater than b, print ">"
    print(">")
else:
    # If a is equal to b, print "="
    print("=")
