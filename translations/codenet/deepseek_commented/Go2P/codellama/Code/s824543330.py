
# Declare two integer variables a and b
a, b = 0, 0

# Read two integers from the standard input and store them in a and b
a, b = map(int, input().split())

# Check if the product of a and b is even or odd
if a*b%2 == 0:
    # If the product is even, print "Even"
    print("Even")
else:
    # If the product is odd, print "Odd"
    print("Odd")

