# <START-OF-CODE>

# Declare variables
n = 0 # Number of elements in the array
sum = 0 # Variable to store the total sum of differences

# Read the number of elements from user input
n = int(input())

# Declare an array of size n
a = [0] * n

# Read n elements into the array from user input
for i in range(n):
    a[i] = int(input())

# Iterate through the array to calculate the sum of differences
for i in range(1, n):
    # Check if the previous element is greater than the current element
    if a[i - 1] > a[i]:
        # Calculate the difference and add it to the sum
        sum += a[i - 1] - a[i]
        # Update the current element to be equal to the previous element
        a[i] = a[i - 1]

# Print the total sum of differences
print(sum)

# 