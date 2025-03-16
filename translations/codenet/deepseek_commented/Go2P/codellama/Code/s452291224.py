
# Declare three integer variables A, B, and C
A = 0
B = 0
C = 0

# Read three integers from the standard input and assign them to A, B, and C
A, B, C = map(int, input().split())

# Check if the expression C-A+B is less than 0
if C-A+B < 0:
    # If true, print "0"
    print("0")
else:
    # Otherwise, print the value of C-A+B
    print(C-A+B)

