# Declare three integer variables a, b, and c
a, b, c = map(int, input().split())

# Check if b is greater than the product of a and c
if b > a * c:
    # If true, print the value of c
    print(c)
else:
    # If false, print the result of b divided by a
    print(b // a)

# <END-OF-CODE>
