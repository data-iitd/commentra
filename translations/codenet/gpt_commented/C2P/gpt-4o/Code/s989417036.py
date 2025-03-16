# Declare variables to hold input values
a, b, c = map(int, input().split())

# Check if b is less than or equal to c
if b <= c:
    # If true, print "NO" and exit the program
    print("NO")
else:
    # Initialize d with the value of a
    d = a

    # Loop through values from 0 to b-1
    for i in range(b):
        # Update d to be the remainder of d when divided by b
        d = d % b

        # Check if d is equal to c
        if d == c:
            # If true, print "YES" and exit the program
            print("YES")
            break
        # Check if this is not the first iteration and d is equal to c
        elif i != 0 and d == c:
            # If true, print "NO" and exit the program
            print("NO")
            break

        # Increment d by the value of a
        d += a
    else:
        # If no conditions were met, print "NO"
        print("NO")
# <END-OF-CODE>
