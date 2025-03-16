
# Read a string input from the user
A, B = input().split()

# Convert the first string (A) to an integer
A = int(A)

# Convert the second string (B) to an integer after removing any decimal points
B = int(B.replace(".", ""))

# Multiply A and B
result = A * B

# Divide the result by 100
final_result = result // 100

# Print the final result
print(final_result)