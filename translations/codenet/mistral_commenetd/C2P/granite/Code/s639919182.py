

# Read 10 integers from the user and store them in the list 'v'.
v = []
for i in range(10):
    value = int(input("Enter the value for index %d: " % i))
    v.append(value)

# Calculate the sum of all elements in the list 'v'.
sum = 0
for value in v:
    sum += value

# Print the sum of all elements in the list 'v'.
print(sum)

