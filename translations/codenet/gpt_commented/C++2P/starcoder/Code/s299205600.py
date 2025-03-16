# Declare variables to hold the input values
a = int(input())
b = int(input())

# Declare a variable to store the result
result = 0

# Determine the result based on the comparison of a and b
if a > b:
    # If a is greater than b, calculate result as 2 * a - 1
    result = 2 * a - 1
elif a == b:
    # If a is equal to b, calculate result as 2 * a
    result = 2 * a
else:
    # If a is less than b, calculate result as 2 * b - 1
    result = 2 * b - 1

# Output the result to the console
print(result)

