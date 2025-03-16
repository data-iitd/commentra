# Read the number of elements from user input
n = int(input())

# Allocate a list for 'n' integers
data = []

# Read 'n' integers from user input into the list
for _ in range(n):
    data.append(int(input()))

# Initialize variables to find the maximum value and its index
max_value = 0
index = -1

# Find the maximum value in the list and its index
for i in range(n):
    if data[i] > max_value:
        max_value = data[i]
        index = i

# Initialize a variable to calculate the sum of all elements except the maximum
total_sum = 0

# Calculate the sum of all elements excluding the maximum value
for i in range(n):
    if i != index:
        total_sum += data[i]

# Compare the sum of the other elements with the maximum value and print the result
if total_sum > max_value:
    print("Yes")
else:
    print("No")

# <END-OF-CODE>
