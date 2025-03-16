
# Ask user for an integer value
X = int(input("Enter the number of units: "))

# Calculate the number of 500-unit boxes
h = X // 500

# Calculate the number of additional 5-unit boxes
a = (X % 500) // 5

# Calculate the total number of units
y = h * 1000 + a * 5

# Print the result
print("The total number of units is:", y)