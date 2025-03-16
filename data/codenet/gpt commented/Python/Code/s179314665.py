# Read two integers from user input and split them into a list
A, B = [int(x) for x in input().split()]

# Check if both integers are less than 10
if A < 10 and B < 10:
    # If both conditions are met, print the product of A and B
    print(A * B)
else:
    # If either A or B is 10 or greater, print -1
    print(-1)
