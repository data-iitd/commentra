# Read five integers from user input and unpack them into variables a, b, c, d, and e
a, b, c, d, e = map(int, input().split())

# Calculate the remaining value by subtracting the sum of a, b, c, d, and e from 15
remaining_value = 15 - a - b - c - d - e

# Print the calculated remaining value
print(remaining_value)
