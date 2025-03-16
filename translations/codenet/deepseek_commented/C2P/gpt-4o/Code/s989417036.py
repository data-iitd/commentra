# Python translation of the given C code

a, b, c = map(int, input().split())  # Read three integer inputs from the user

# Check if the second input (b) is less than or equal to the third input (c)
if b <= c:
    print("NO")  # If true, print "NO" and terminate the program
else:
    d = a  # Initialize variable d with the value of a
    
    # Loop that runs b times
    for i in range(b):
        d = d % b  # Update the value of d by taking the remainder of d divided by b
        
        # Check if d equals c
        if d == c:
            print("YES")  # If true, print "YES" and terminate the program
            break
        elif i != 0 and d == c:  # Check if d equals c and it's not the first iteration
            print("NO")  # If true, print "NO" and terminate the program
            break
        
        d += a  # Increment d by the value of a
    else:
        print("NO")  # If the loop completes without finding a solution, print "NO"

# <END-OF-CODE>
