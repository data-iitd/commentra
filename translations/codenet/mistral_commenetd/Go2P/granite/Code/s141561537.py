

# Importing the'sys' module for input/output operations
import sys

# Declaring variables a, b, c, x, and sum of integer data type
a, b, c, x = map(int, sys.stdin.readline().split())

# Initializing a nested for loop to iterate through the possible combinations of i, j, and k
sum = 0
for i in range(a + 1):
    for j in range(b + 1):
        for k in range(c + 1):
            # Checking if the sum of i, j, and k multiplied by 50, 100, and 50 respectively equals x
            if 500 * i + 100 * j + 50 * k == x:
                sum += 1 # Incrementing the sum variable if the condition is true

# Printing the final value of sum to the console
print(sum)

# End of the code

