
import sys

# Read a long integer N from user input
N = int(input())

# Initialize a variable to hold the minimum value
min = 0

# Loop to read five long integers and find the minimum
for i in range(5):
    # For the first iteration, directly assign the value to min
    if i == 0:
        min = int(input())
    else:
        # For subsequent iterations, update min if a smaller value is found
        min = min if min < int(input()) else int(input())

# Calculate the result by dividing N by min, rounding up, and adding 4
print(str(int((N + min - 1) / min) + 4))

# End of code
print("