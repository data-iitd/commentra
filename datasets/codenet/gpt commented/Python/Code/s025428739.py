# Read two integers from input and unpack them into variables A and B
A, B = map(int, input().split())

# Initialize an empty list to store the results of operations
lst = []

# Append the result of addition of A and B to the list
lst.append(A + B)

# Append the result of subtraction of A and B to the list
lst.append(A - B)

# Append the result of multiplication of A and B to the list
lst.append(A * B)

# Print the maximum value from the list of results
print(max(lst))
