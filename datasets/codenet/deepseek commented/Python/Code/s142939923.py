a, b = map(int, input().split())

# Taking two integer inputs, a and b

# A + B
x = [a + b]
# Adding the result of A + B to the list x

# A - B
x.append(a - b)
# Adding the result of A - B to the list x

# A * B
x.append(a * b)
# Adding the result of A * B to the list x

# Printing the maximum value among the results of the operations
print(max(x))
