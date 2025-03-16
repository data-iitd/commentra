# Declare an integer array 'v' of size 10 and an integer variable 'sum' to store the sum of array elements.
v = []  # Declare an integer array 'v' of size 10.
sum = 0  # Declare an integer variable 'sum' and initialize it to zero.

# Read 10 integers from the user and store them in the array 'v'.
for i in range(10):
    value = int(input(f"Enter the value for index {i}: "))
    v.append(value)  # Append the value to the array 'v'.

# Calculate the sum of all elements in the array 'v'.
for i in range(10):
    sum += v[i]  # Add the value of the current element in the array 'v' to the variable 'sum'.

# Print the sum of all elements in the array 'v'.
print(sum)  # Display the sum of all elements in the array 'v'.

# <END-OF-CODE>