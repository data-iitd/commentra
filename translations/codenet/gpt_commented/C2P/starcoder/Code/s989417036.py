# <START-OF-CODE>

# Declare variables to hold input values and loop counter
a = 0
b = 0
c = 0
d = 0
e = 0
i = 0

# Read three integers from user input
a, b, c = map(int, input().split())

# Check if b is less than or equal to c
if b <= c:
    # If true, print "NO" and exit the program
    print("NO")
    exit(0)
else:
    # Initialize d with the value of a
    d = a

    # Calculate the remainder of d when divided by b
    e = d % b

    # Loop through values from 0 to b-1
    for i in range(b):
        # Update d to be the remainder of d when divided by b
        d = d % b

        # Check if d is equal to c
        if d == c:
            # If true, print "YES" and exit the program
            print("YES")
            exit(0)
        # Check if this is not the first iteration and d is equal to c
        elif i!= 0 and d == c:
            # If true, print "NO" and exit the program
            print("NO")
            exit(0)

        # Increment d by the value of a
        d += a

# If no conditions were met, print "NO"
print("NO")

# 