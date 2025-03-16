

# Read the values of A and B from the standard input
A, B = map(int, input().split())

# Declare an integer variable C and assign the sum of A and B to it
C = A + B

# Check if both A and B are not divisible by 3
if A % 3!= 0 and B % 3!= 0:
    # Check if their sum C is also not divisible by 3
    if C % 3!= 0:
        # If all conditions are met, print "Impossible" to the standard output
        print("Impossible")
    else:
        # Otherwise, print "Possible" to the standard output
        print("Possible")

# Return 0 to indicate successful execution of the program
exit(0)

