
# Declare and initialize three integer variables
a, b, c = 0, 0, 0

# Read the values of a, b, and c from the standard input using cin
a, b, c = map(int, input().split())

# Check if the sum of a and b is greater than or equal to c
if a + b >= c:
    print("Yes")
else:
    print("No")

# 