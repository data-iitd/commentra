
# Read three integers from user input
a = int(input())
b = int(input())
c = int(input())

# Check if b is greater than the product of a and c
if b > a * c:
    # If true, print the value of c
    print(c)
else:
    # If false, print the result of b divided by a
    print(b // a)

# End of code
