
# Declare integer variables to hold input values
r, d, x = 0, 0, 0

# Read three integers from standard input
r, d, x = map(int, input().split())

# Start a loop that will run 10 times
for i in range(10):
    # Update the value of x using the formula r*x - d
    x = r*x - d
    # Print the updated value of x
    print(x)

