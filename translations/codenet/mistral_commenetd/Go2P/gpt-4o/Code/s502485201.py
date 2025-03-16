# Initialize variables r, d, and x with given values
r, d, x = map(int, input().split())

# Loop through 10 iterations
for i in range(10):
    # Calculate new value of x using given formula
    x = r * x - d

    # Print the current value of x
    print(x)

# <END-OF-CODE>
