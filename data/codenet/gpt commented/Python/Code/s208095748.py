# Read three integers A, B, and C from user input
A, B, C = map(int, input().split())

# Check if B is less than C
if B < C:
    # If B is less than C, print 0
    print(0)
# Check if A multiplied by C is less than B
elif A * C < B:
    # If A * C is less than B, print C
    print(C)
else:
    # Otherwise, print the result of B divided by A (integer division)
    print(B // A)
