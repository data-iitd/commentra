# Reading an integer input from the user
x = int(input())

# Using a ternary operator to determine the boolean value based on the input
bool = True if x == 1 else False

# Setting the result based on the boolean value; if bool is False, result is 1, otherwise 0
result = 1 if not bool else 0

# Printing the result to the console
print(result)
