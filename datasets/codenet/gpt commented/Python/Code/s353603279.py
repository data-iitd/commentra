# Read an integer input from the user
X = int(input())

# Calculate the number of 500s in X
h = X // 500

# Calculate the remaining amount after extracting 500s and determine how many 5s fit into it
a = (X % 500) // 5

# Calculate the total value based on the number of 500s and 5s
y = h * 1000 + a * 5

# Print the final calculated value
print(y)
