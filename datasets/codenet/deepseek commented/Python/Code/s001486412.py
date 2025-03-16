
n = int(input())  # Read the number of elements in the list
a = list(map(int, input().split()))  # Read the list of integers
below = 0  # Initialize a variable to store the sum of reciprocals

# Loop through each element in the list and add its reciprocal to 'below'
for i in range(n):
    below += 1 / a[i]  # Add the reciprocal of the current element

# Print the reciprocal of the sum of the reciprocals
print(1 / below)


