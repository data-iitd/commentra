
# Declare three integer variables A, B, and C
A = int(input())
B = int(input())
C = int(input())

# Check if the expression C - A + B is less than 0
if C - A + B < 0:
    # If the expression is less than 0, print "0"
    print("0")
else:
    # If the expression is 0 or greater, print the result of C - A + B
    print(C - A + B)

