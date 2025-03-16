# Read the number of elements
n = int(input())

# Read the elements into a list and convert them to integers
a = list(map(int, input().split()))

# Initialize a list 'b' with zeros to store the positions of elements
b = [0] * n

# Populate the list 'b' with the indices of elements from list 'a'
for i in range(n):
    b[a[i] - 1] = i  # Store the index of each element in 'b' based on its value in 'a'

# Initialize the result variable to accumulate the total distance
res = 0

# Calculate the total distance between consecutive elements in 'b'
for i in range(1, n):
    res += abs(b[i] - b[i - 1])  # Add the absolute difference of indices to the result

# Print the final result
print(res)
