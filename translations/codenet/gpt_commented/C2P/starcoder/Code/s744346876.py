# Declare two integer variables A and B
A, B = 0, 0

# Read two integers from user input
A, B = map(int, input().split())

# Check if both A and B are less than 10
if A < 10 and B < 10:
    # If both are less than 10, print their product
    print(A * B)
else:
    # If either A or B is 10 or greater, print -1
    print(-1)

# 