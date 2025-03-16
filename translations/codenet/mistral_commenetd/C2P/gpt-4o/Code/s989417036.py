# Declare variables
a, b, c = map(int, input().split())

# Check if b is less than or equal to c
if b <= c:
    # If so, print "NO" and exit
    print("NO")
else:
    # Initialize d with a
    d = a

    # Iterate through b using a for loop
    for i in range(b):
        # Update d by calculating the remainder of d divided by b
        d = d % b

        # If d is equal to c, print "YES" and exit
        if d == c:
            print("YES")
            break
        # If d is already equal to c and i is not the first iteration, print "NO" and exit
        elif i != 0 and d == c:
            print("NO")
            break

        # Update d by adding a
        d += a
    else:
        # If the loop finishes without finding c, print "NO" and exit
        print("NO")
# <END-OF-CODE>
