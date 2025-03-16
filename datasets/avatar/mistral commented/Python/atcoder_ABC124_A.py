# Get two integers as input from the user, separated by a space
a, b = map(int, input().split())

# Initialize a variable 'c' to store the sum of the larger numbers in each iteration
c = 0

# Loop through the given condition for 2 times
for i in range(2):

    # Calculate the sum of the larger number in each iteration and add it to the variable 'c'
    c += max(a, b)

    # Update the smaller number in each iteration
    if a >= b:
        a -= 1
    else:
        b -= 1

# Print the final result
print(c)
