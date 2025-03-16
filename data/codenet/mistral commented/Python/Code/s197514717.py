# Define a list 'ABC' with three integers read from a line of input
ABC = list(map(int, input().split()))

# Assign the first, second, and third elements of the list to variables 'A', 'B', and 'C' respectively
A = ABC[0]
B = ABC[1]
C = ABC[2]

# Calculate the maximum value of three expressions
max_value = max([10*A+B+C, 10*B+C+A, 10*C+A+B])

# Print the maximum value
print(max_value)
