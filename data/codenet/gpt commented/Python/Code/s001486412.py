# Read an integer input for the number of elements
n = int(input())

# Read a list of integers from input and convert them to a list of integers
a = list(map(int, input().split()))

# Initialize a variable to accumulate the sum of the reciprocals
below = 0

# Loop through each element in the list
for i in range(n):
    # Add the reciprocal of the current element to the 'below' variable
    below += 1 / a[i]

# Calculate and print the reciprocal of the accumulated sum of reciprocals
print(1 / below)
