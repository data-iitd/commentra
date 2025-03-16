# Read input values from the user and split them into two variables A and B
A, B = input().split()

# Convert the first input value A to an integer
A = int(A)

# Remove the decimal point from the second input value B and convert it to an integer
B = int(B.replace(".", ""))

# Calculate the product of A and B, then divide by 100 to get the final result
# Print the result
print(A * B // 100)
