# Read an integer value for n from the standard input
n = int(input().strip())  # Use strip() to remove any trailing newline characters

# Allocate a list to store n integers
data = list(map(int, input().strip().split()))  # Read n integers from the standard input

max_value = 0  # Initialize max to 0
index = 0  # Initialize index to 0

# Iterate through the list to find the maximum value and its index
for i in range(n):
    if data[i] > max_value:
        max_value = data[i]
        index = i  # Update the index of the maximum value

a = 0  # Initialize a variable to store the sum of elements excluding the maximum value

# Iterate through the list again, excluding the element at the index of the maximum value, and sum up the remaining elements
for i in range(n):
    if i != index:
        a += data[i]

# Compare the sum of the remaining elements (a) with the maximum value (max_value)
if a > max_value:
    print("Yes")  # Print "Yes" if the sum of remaining elements is greater than the maximum value
else:
    print("No")  # Print "No" otherwise

# <END-OF-CODE>
