# Read the number of elements in the array
n = int(input())
# Read the size of the subarray to be summed
a = int(input())
# Initialize the sum variable to zero
sum = 0
# Declare a list to store the input elements
s = []

# Read the elements of the array from the user
for i in range(n):
    s.append(int(input()))

# Sort the list in ascending order
s.sort()

# Calculate the sum of the last 'a' elements of the sorted list
for i in range(n-1, n-a-1, -1):
    sum += s[i]

# Print the result
print(sum)
