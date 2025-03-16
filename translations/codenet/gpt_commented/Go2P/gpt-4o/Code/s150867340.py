# Declare two integer variables to hold the input values
a, b = map(int, input().split())

# Calculate the product of the two integers and check if it is even or odd
if (product := a * b) % 2 == 0:
    # If the product is even, print "Even"
    print("Even")
else:
    # If the product is odd, print "Odd"
    print("Odd")

# <END-OF-CODE>
