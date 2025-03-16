# Declaring variables r, D, and x of type int
r, D, x = map(int, input().split())

# Loop runs 10 times
for i in range(1, 11):
    # Print the result of the current iteration
    print(r * x - D)

    # Update the value of x for the next iteration
    x = r * x - D

# End-of-code
